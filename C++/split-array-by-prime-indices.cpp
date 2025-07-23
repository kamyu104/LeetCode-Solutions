// Time:  precompute: O(max_n), max_n = max(len(nums))
//        runtime:    O(n)
// Space: O(max_n)

// number theory
vector<int64_t> linear_sieve_of_eratosthenes(int64_t n) {  // Time: O(n), Space: O(n)
    vector<int64_t> spf(n + 1, -1);
    vector<int64_t> primes;
    for (int64_t i = 2; i <= n; ++i) {
        if (spf[i] == -1) {
            spf[i] = i;
            primes.emplace_back(i);
        }
        for (const auto& p : primes) {
            if (i * p > n || p > spf[i]) {
                break;
            }
            spf[i * p] = p;
        }
    }
    return spf;
}

static const int MAX_IDX = 1e5 - 1;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_IDX);
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            result += SPF[i] == i ? nums[i] : -nums[i];
        }
        return abs(result);
    }
};
