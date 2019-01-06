// Time:  O(1)
// Space: O(1)

class Fraction {
public:
    Fraction() = default;
    Fraction(int64_t n)
        : Fraction(n, 1)
    {
    }
    Fraction(int64_t n, int64_t d)
        : numerator_(n)
        , denominator_(d)
        , integer_(0)
    {
        reduce();
    }
    ~Fraction() = default;

    void set_num(int64_t value) { numerator_ = value; }
    void set_den(int64_t value) { denominator_ = value; }
    void set_int(int64_t value) { integer_ = value; }
    int64_t get_num() const { return numerator_; }
    int64_t get_den() const { return denominator_; }
    int64_t get_int() const { return integer_; }
    void reduce();
    int64_t calculate_gcd(int64_t, int64_t) const;
    
    Fraction& operator+=(const Fraction& rhs);
private:
    int64_t numerator_, denominator_, integer_;
};

void Fraction::reduce()
{
    const auto gcd = calculate_gcd(numerator_, denominator_);
    numerator_ = numerator_ / gcd;
    denominator_ = denominator_ / gcd;
    integer_ += numerator_ / denominator_;
    numerator_ %= denominator_;
}

int64_t Fraction::calculate_gcd(int64_t a, int64_t b) const
{
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int64_t tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

Fraction& Fraction::operator+=(const Fraction& rhs)
{
    set_num((get_num() * rhs.get_den()) + (get_den() * rhs.get_num()));
    set_den(get_den() * rhs.get_den());
    set_int(get_int() + rhs.get_int());
    reduce();
    return *this;
}

bool operator==(const Fraction &lhs, const Fraction &rhs) {
    return lhs.get_num() == rhs.get_num() &&
           lhs.get_den() == rhs.get_den() &&
           lhs.get_int() == rhs.get_int();
}

std::ostream &operator<<(std::ostream &os, const Fraction &value) {
    os << value.get_int() << ".(" << value.get_num() << "/" << value.get_den() << ")";
    return os;
}

class Solution {
public:
    bool isRationalEqual(string S, string T) {
        return frac(S) == frac(T);
    }

private:
    Fraction frac(const string& S) {
        auto i = S.find('.');
        if (i == string::npos) {
            return Fraction(stol(S));
        }

        Fraction result(stol(S.substr(0, i)), 1);
        const auto& non_int_part = S.substr(i + 1);
        i = non_int_part.find('(');
        if (i == string::npos) {
            if (!non_int_part.empty()) {
                result += Fraction(stol(non_int_part),
                                   static_cast<int64_t>(pow(10, non_int_part.length())));
            }
            return result;
        }

        if (i > 0) {
            result += Fraction(stol(non_int_part.substr(0, i)),
                               static_cast<int64_t>(pow(10, i)));
        }
        const auto& repeat_part = non_int_part.substr(i + 1, non_int_part.length() - i - 2);
        result += Fraction(stol(repeat_part),
                           static_cast<int64_t>(pow(10, i)) *
                           (static_cast<int64_t>(pow(10, repeat_part.length())) - 1));
        return result;
    }   
};

