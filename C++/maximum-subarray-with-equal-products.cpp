// Time:  precompute: O(r * log(logr)), r = MAX_NUM
//        runtime:    O(n * log(logr))
// Space: O(r * log(logr))

// number theory, hash table
vector<vector<int>> prime_divisors(int n) {
    const auto& linear_sieve_of_eratosthenes = [](int n) {  // Time: O(n), Space: O(n)
        vector<int> spf(n + 1, -1);
        vector<int> primes;
        for (int i = 2; i <= n; ++i) {
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
        return primes;
    };

    vector<vector<int>> result(n + 1);
    for (const auto& p : linear_sieve_of_eratosthenes(n)) {  // Time: O(nlog(logn))
        for (int i = p; i <= n; i += p) {
            result[i].emplace_back(p);
        }
    }
    return result;
}

const int MAX_NUM = 10;
const auto& PRIME_DIVISORS = prime_divisors(MAX_NUM);
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int result = 2;
        unordered_map<int, int> lookup;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            for (const auto& p : PRIME_DIVISORS[nums[right]]) {
                left = max(left, lookup[p]);
                lookup[p] = right + 1;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
