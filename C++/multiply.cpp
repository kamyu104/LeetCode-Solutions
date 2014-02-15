// Time Complexity: O(n)
// Space Complexity: O(1)

class BigInt {
    public:
        BigInt(string s) {
            transform(s.rbegin(), s.rend(), back_inserter(n), 
                    [](const char c) { return c - '0';});
        }

        operator string() {
            string s;
            transform(find_if(this->n.rbegin(), prev(this->n.rend()), 
                        [](const int i) { return i != 0; }), this->n.rend(), back_inserter(s), 
                    [](const int i) { return i + '0'; });

            return s;
        }

        BigInt operator*(const BigInt &rhs) const {
            BigInt z(n.size() + rhs.size() + 1, 0);
            for(auto i = 0; i < n.size(); ++i) {
                for(auto j = 0; j < rhs.size(); ++j) {
                    z[i + j] += n[i] * rhs[j];
                    z[i + j + 1] += z[i + j] / 10;
                    z[i + j] %= 10;
                }
            }
            return z;
        }
    private:
        vector<int> n;

        BigInt(int num, int val): n(num, val) {
        }

        // getter
        int operator[] (int i) const {
            return this->n[i];
        }

        // setter
        int & operator[] (int i) {
            return this->n[i];
        }

        int size() const {
            return this->n.size();
        }
};

class Solution {
    public:
        string multiply(string num1, string num2) {
            return BigInt(num1) * BigInt(num2);
        }
};
