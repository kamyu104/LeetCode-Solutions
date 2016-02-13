// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    string multiply(string num1, string num2) {
        return BigInt(num1) * BigInt(num2);
    }

    class BigInt {
    public:
        BigInt(const string& s) {
            transform(s.rbegin(), s.rend(), back_inserter(n_), 
                      [](const char c) { return c - '0';});
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
            BigInt res(n_.size() + rhs.size() + 1, 0);
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
