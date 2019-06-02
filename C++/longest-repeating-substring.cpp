// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int longestRepeatingSubstring(string S) {
        auto left = 1ul, right = S.length() - 1;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (!check(S, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
    
private:
    uint64_t check(const string& S, uint64_t L) {
        static const uint64_t M = 1e9 + 7;
        static const uint64_t D = 26;
        uint64_t p = power(D, L, M);
        uint64_t curr = 0;
        for (uint64_t i = 0; i < L; ++i) {
            curr = ((D * curr) + S[i] - 'a') % M;
        }
        unordered_map<uint64_t, vector<uint64_t>> lookup;
        lookup[curr].emplace_back(L - 1);
        for (uint64_t i = L; i < S.length(); ++i) {
            curr = (D * curr) % M;
            curr = (curr + (S[i] - 'a')) % M;
            curr = (curr + (M - ((S[i - L] - 'a') * p) % M)) % M;
            if (lookup.count(curr)) {
                for (const auto& j : lookup[curr]) {  // check if string is the same when hash is the same
                    if (S.substr(j - L + 1, L) == S.substr(i - L + 1, L)) {
                        return i - L + 1;
                    }
                }
            }
            lookup[curr].emplace_back(i);
        }
        return 0;
    }
    
    uint64_t power(uint64_t D, uint64_t L, uint64_t M) {
        uint64_t result = 1;
        for (uint64_t i = 0; i < L; ++i) {
            result = (result * D) % M;
        }
        return result;
    }
};
