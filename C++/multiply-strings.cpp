// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    string multiply(string num1, string num2) {
        const auto char_to_int = [](const char c) { return c - '0'; };
        const auto int_to_char = [](const int i) { return i + '0'; };

        vector<int> n1;
        transform(num1.rbegin(), num1.rend(), back_inserter(n1), char_to_int);
        vector<int> n2;
        transform(num2.rbegin(), num2.rend(), back_inserter(n2), char_to_int);

        vector<int> tmp(n1.size() + n2.size());
        for(int i = 0; i < n1.size(); ++i) {
            for(int j = 0; j < n2.size(); ++j) {
                tmp[i + j] += n1[i] * n2[j];
                tmp[i + j + 1] += tmp[i + j] / 10;
                tmp[i + j] %= 10;
            }
        }
            
        string res;
        transform(find_if(tmp.rbegin(), prev(tmp.rend()),
                         [](const int i) { return i != 0; }),
                  tmp.rend(), back_inserter(res), int_to_char);
        return res;
    }
};

// Time:  O(m * n)
// Space: O(m + n)
// Define a new BigInt class solutioin. 
class Solution2 {
public:
    string multiply(string num1, string num2) {
        return BigInt(num1) * BigInt(num2);
    }

    class BigInt {
    public:
        BigInt(const string& s) {
            transform(s.rbegin(), s.rend(), back_inserter(n_), 
                      [](const char c) { return c - '0'; });
        }
    
        operator string() {
            string s;
            transform(find_if(n_.rbegin(), prev(n_.rend()),
                             [](const int i) { return i != 0; }),
                      n_.rend(), back_inserter(s), 
                      [](const int i) { return i + '0'; });
            return s;
        }
    
        BigInt operator*(const BigInt &rhs) const {
            BigInt res(n_.size() + rhs.size(), 0);
            for(auto i = 0; i < n_.size(); ++i) {
                for(auto j = 0; j < rhs.size(); ++j) {
                    res[i + j] += n_[i] * rhs[j];
                    res[i + j + 1] += res[i + j] / 10;
                    res[i + j] %= 10;
                }
            }
            return res;
        }
    
    private:
        vector<int> n_;
    
        BigInt(int num, int val): n_(num, val) {
        }
    
        // Getter.
        int operator[] (int i) const {
            return n_[i];
        }
    
        // Setter.
        int & operator[] (int i) {
            return n_[i];
        }
    
        size_t size() const {
            return n_.size();
        }
    };
};
