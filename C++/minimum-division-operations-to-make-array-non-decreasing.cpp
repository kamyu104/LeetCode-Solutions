// Time:  precompute: O(r)
//        runtime:    O(n)
// Space: O(r) 

// greedy, number theory
vector<int> linear_sieve_of_eratosthenes(int n) {  // Time: O(n), Space: O(n)
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
    return spf;
}

const int MAX_N = 1e6;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_N);
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for (int i = size(nums) - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }
            if (SPF[nums[i]] > nums[i + 1]) {
                return -1;
            }
            nums[i] = SPF[nums[i]];
            ++result;
        }
        return result;
    }
};
