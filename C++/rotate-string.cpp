// Time:  O(n)
// Space: O(1)

// Rabin-Karp Algorithm (rolling hash)
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        static const uint64_t M = 1000000007;
        static const uint64_t p = 113; 
        static const uint64_t p_inv = pow(p, M - 2, M);
    
        uint64_t b_hash = 0, power = 1;
        for (int i = 0; i < B.length(); ++i) {
            b_hash += power * B[i];
            b_hash %= M;
            power = (power * p) % M;
        }

        uint64_t a_hash = 0; power = 1;
        for (int i = 0; i < B.length(); ++i) {
            a_hash += power * A[i % A.length()];
            a_hash %= M;
            power = (power * p) % M;
        }
        if (a_hash == b_hash && check(0, A, B)) {
            return true;
        }
        
        power = (power * p_inv) % M;
        for (int i = B.length(); i < 2 * A.length(); ++i) {
            a_hash -= A[(i - B.length()) % A.length()];
            a_hash *= p_inv;
            a_hash += power * A[i % A.length()];
            a_hash %= M;
            if (a_hash == b_hash && check(i - B.length() + 1, A, B)) {
                return true;
            }
        }
        return false;
    }

private:
    bool check(int index, const string& A, const string& B) {
        for (int i = 0; i < B.length(); ++i) {
            if (A[(i + index) % A.length()] != B[i]) {
                return false;
            }
        }
        return true;
    }

    uint64_t pow(uint64_t a,uint64_t b, uint64_t m) {
        a %= m;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// KMP algorithm
class Solution2 {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        return strStr(A + A, B) != -1;
    }
    
private:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        return KMP(haystack, needle);
    }

    int KMP(const string& text, const string& pattern) {
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution3 {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};
