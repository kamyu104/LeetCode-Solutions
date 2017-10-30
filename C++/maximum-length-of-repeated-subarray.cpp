// Time:  O(m * n)
// Space: O(min(m, n))

// dp solution (99 ms)
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.size() < B.size()) { 
            return findLength(B, A);
        }
        int result = 0;
        vector<vector<int>> dp(2, vector<int>(B.size() + 1));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                if (A[i] == B[j]) {
                    dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
                    result = max(result, dp[(i + 1) % 2][j + 1]);
                } else {
                    dp[(i + 1) % 2][j + 1] = 0;
                }
            }
        }
        return result;
    }
};


// Time:  O(m * n * log(min(m, n)))
// Space: O(min(m, n))
// Binary search + rolling hash solution (36 ms)
class Solution2 {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) {
            return findLength(B, A);
        }
        int left = 0, right = min(A.size(), B.size()) + 1;
        while (left < right) {
            const auto mid = left + (right-left) / 2;
            if (!check(mid, A, B)) {  // find the min idx such that check(idx) == false
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
    
private:
    bool check(const int guess, const vector<int>& A, const vector<int>& B) {
        unordered_map<uint64_t, vector<int>> hashes;
        int i = 0;
        for (const auto& hash_a : rolling_hashes(A, guess)) {
            hashes[hash_a].emplace_back(i++);
        }
        int j = 0;
        for (const auto& hash_b : rolling_hashes(B, guess)) {
            for (const auto& i : hashes[hash_b]) {
                if (equal(A.begin() + i, A.begin() + i + guess, B.begin() + j)) {
                    return true;
                }
            }
            ++j;
        }
        return false;
    }
            
    vector<uint64_t> rolling_hashes(const vector<int>& source, const int length) {
        static const uint64_t M = 1000000007;
        static const uint64_t p = 113; 
        static const uint64_t p_inv = pow(p, M - 2, M);
        vector<uint64_t> result(source.size() - length + 1);
        uint64_t hash = 0, power = 1;
        if (length == 0) {
            return result;
        }
        for (int i = 0; i < source.size(); ++i) {
            hash = (hash + source[i] * power) % M;
            if (i < length - 1) {
                power = (power * p) % M;
            } else {
                result[i - (length - 1)] = hash;
                hash = (hash - source[i - (length - 1)]) * p_inv % M;
            }
        }
        return result;
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
