// Time:  precompute: O(MAX_N)
//        runtime: O(n)
// Space: O(MAX_N)

// number theory
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

const int MAX_N = 4 * 1e6;
const auto& PRIMES = linear_sieve_of_eratosthenes(MAX_N);
const unordered_set<int> PRIMES_SET(cbegin(PRIMES), cend(PRIMES));
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (PRIMES_SET.count(nums[i][i])) {
                result = max(result, nums[i][i]);
            }
            if (PRIMES_SET.count(nums[i][size(nums) - 1 - i])) {
                result = max(result, nums[i][size(nums) - 1 - i ]);
            }
        }
        return result;
    }
};
