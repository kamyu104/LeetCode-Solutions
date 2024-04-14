// Time:  O(r + n), r = max(nums)
// Space: O(r)

// linear sieve of eratosthenes, number theory
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

static const int MAX_N = 100;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_N);
class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int left = -1, right = -1;
        for (int i = 0; i < size(nums); ++i) {
            if (SPF[nums[i]] != nums[i]) {
                continue;
            }
            if (left == -1) {
                left = i;
            }
            right = i;
        }
        return right - left;
    }
};
