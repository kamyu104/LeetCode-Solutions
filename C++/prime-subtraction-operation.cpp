// Time:  O(p + nlogp)
// Space: O(p)

// number theory, greedy, binary search
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
    return primes;  // len(primes) = O(n/(logn-1)), reference: https://math.stackexchange.com/questions/264544/how-to-find-number-of-prime-numbers-up-to-to-n
}

const int MAX_N = 1000;
const auto& PRIMES = linear_sieve_of_eratosthenes(MAX_N - 1);
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        for (int i = 0; i < size(nums); ++i) {
            const auto& it = lower_bound(cbegin(PRIMES), cend(PRIMES), i - 1 >= 0 ? nums[i] - nums[i - 1] : nums[i]);
            if (it != cbegin(PRIMES)) {
                nums[i] -= *prev(it);
            }
            if (i - 1 >= 0 && nums[i - 1] >= nums[i]) {
                return false;
            }
        }
        return true;
    }
};
