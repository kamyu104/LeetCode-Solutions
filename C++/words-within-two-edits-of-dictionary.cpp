// Time:  O(25 * l * (n + q))
// Space: O(25 * l * n)

// hash
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        static const uint64_t MOD = (1ull << 64) - 59;  // largest 64-bit prime
        static const uint64_t BASE = 113;
        vector<uint64_t> POW = {1};
        const auto& add = [](uint64_t a, uint64_t b) {
            if (MOD - a <= b) {
                b -= MOD;  // relied on unsigned integer overflow in order to give the expected results
            }
            return a + b;
        };
        const auto& sub = [&](uint64_t a, uint64_t b) {
            return add(a, MOD - b);
        };
        const auto& mult = [&](uint64_t a, uint64_t b)  { 
            uint64_t result = 0;
            if (a < b) {
                swap(a, b);
            }
            while (b > 0)  { 
                if (b % 2 == 1) {
                    result = add(result, a);
                }
                a = add(a, a);
                b /= 2; 
            } 
            return result;
        };
        const auto& pow = [&](int i) {
            while (!(i < size(POW))) {
                POW.emplace_back(mult(POW.back(), BASE));
            }
            return POW[i];
        };
    
        unordered_set<uint64_t> lookup;
        for (const auto& w : dictionary) {
            uint64_t h = 0;
            for (int i = 0; i < size(w); ++i) {
                h = add(h, mult(sub(w[i], 'a'), pow(i)));
            }
            for (int i = 0; i < size(w); ++i) {
                for (char x = 'a'; x <= 'z'; ++x) {
                    if (x == w[i]) {
                        continue;
                    }
                    lookup.emplace(add(h, mult(sub(x, w[i]), pow(i))));
                }
            }
        }
        vector<string> result;
        for (const auto& w : queries) {
            uint64_t h = 0;
            for (int i = 0; i < size(w); ++i) {
                h = add(h, mult(sub(w[i], 'a'), pow(i)));
            }
            for (int i = 0; i < size(w); ++i) {
                char x = 'a';
                for (; x <= 'z'; ++x) {
                    if (x == w[i]) {
                        continue;
                    }
                    if (lookup.count(add(h, mult(sub(x, w[i]), pow(i))))) {
                        break;
                    }
                }
                if (x <= 'z') {
                    result.emplace_back(w);
                    break;
                }
            }
        }
        return result;
    }
};

// Time:  O(q * n * l)
// Space: O(1)
// brute force
class Solution2 {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        const auto& check = [&](const auto& w1, const auto& w2) {
            int cnt = 0;
            for (int i = 0; i < size(w1); ++i) {
                cnt += static_cast<int>(w1[i] != w2[i]);
            }
            return cnt <= 2;
        };
        
        vector<string> result;
        for (const auto& q : queries) {
            for (const auto& d : dictionary) {
                if (check(q, d)) {
                    result.emplace_back(q);
                    break;
                }
            }
        }
        return result;
    }
};
