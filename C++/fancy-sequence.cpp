// Time:  O(1)
// Space: O(n)

// #define USE_UINT64_T

class Fancy {
public:
    Fancy() : ops_{{1, 0}} {
        
    }
    
    void append(int val) {
        arr_.emplace_back(val);
        ops_.emplace_back(ops_.back());
    }
    
    void addAll(int inc) {
        ops_.back().second = addmod(ops_.back().second, inc, MOD);
    }
    
    void multAll(int m) {
        ops_.back().first = mulmod(ops_.back().first, m, MOD);
        ops_.back().second = mulmod(ops_.back().second, m, MOD);
    }
    
    int getIndex(int idx) {
        if (idx >= size(arr_)) {
            return -1;
        }
        const auto& [a1, b1] = ops_[idx];
        const auto& [a2, b2] = ops_.back();
        int a = mulmod(a2, powmod(a1, MOD - 2, MOD), MOD);
        int b = submod(b2, mulmod(a, b1, MOD), MOD);
        return addmod(mulmod(arr_[idx], a, MOD), b, MOD);
    }

private:
    uint32_t addmod(uint32_t a, uint32_t b, uint32_t mod) {  // avoid overflow
        // a %= mod, b %= mod;  // assumed a, b have been mod
        if (mod - a <= b) {
            b -= mod;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }
    
    uint32_t submod(uint32_t a, uint32_t b, uint32_t mod) {
        // a %= mod, b %= mod;  // assumed a, b have been mod
        return addmod(a, mod - b, mod);
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b, uint32_t mod)  {  // avoid overflow
#ifdef USE_UINT64_T
        return uint64_t(a) * b % mod;  // speed up if we can use uint64_t
#else
        uint32_t result = 0;
        if (a < b) {
            swap(a, b);
        }
        while (b > 0)  { 
            if (b % 2 == 1) {
                result = addmod(result, a, mod);
            }
            a = addmod(a, a, mod);
            b /= 2; 
        } 
        return result;
#endif
    }

    uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
        a %= mod;
        uint32_t result = 1;
        while (b) {
            if (b & 1) {
                result = mulmod(result, a, mod);
            }
            a = mulmod(a, a, mod);
            b >>= 1;
        }
        return result;
    }
    
    static const int MOD = 1e9 + 7;
    vector<int> arr_;
    vector<pair<int, int>> ops_;
};

// Time:  O(1)
// Space: O(n)
class Fancy2 {
public:
    Fancy2() : op_{1, 0} {
        
    }
    
    void append(int val) {
        arr_.emplace_back(mulmod(submod(val, op_.second, MOD), powmod(op_.first, MOD - 2, MOD), MOD));
    }
    
    void addAll(int inc) {
        op_.second = addmod(op_.second, inc, MOD);
    }
    
    void multAll(int m) {
        op_.first = mulmod(op_.first, m, MOD);
        op_.second = mulmod(op_.second, m, MOD);
    }
    
    int getIndex(int idx) {
        if (idx >= size(arr_)) {
            return -1;
        }
        return addmod(mulmod(arr_[idx], op_.first, MOD), op_.second, MOD);
    }

private:
    uint32_t addmod(uint32_t a, uint32_t b, uint32_t mod) {  // avoid overflow
        // a %= mod, b %= mod;  // assumed a, b have been mod
        if (mod - a <= b) {
            b -= mod;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }
    
    uint32_t submod(uint32_t a, uint32_t b, uint32_t mod) {
        // a %= mod, b %= mod;  // assumed a, b have been mod
        return addmod(a, mod - b, mod);
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b, uint32_t mod)  {  // avoid overflow
#ifdef USE_UINT64_T
        return uint64_t(a) * b % mod;  // speed up if we can use uint64_t
#else
        uint32_t result = 0;
        if (a < b) {
            swap(a, b);
        }
        while (b > 0)  { 
            if (b % 2 == 1) {
                result = addmod(result, a, mod);
            }
            a = addmod(a, a, mod);
            b /= 2; 
        } 
        return result;
#endif
    }

    uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
        a %= mod;
        uint32_t result = 1;
        while (b) {
            if (b & 1) {
                result = mulmod(result, a, mod);
            }
            a = mulmod(a, a, mod);
            b >>= 1;
        }
        return result;
    }
    
    static const int MOD = 1e9 + 7;
    vector<int> arr_;
    pair<int, int> op_;
};
