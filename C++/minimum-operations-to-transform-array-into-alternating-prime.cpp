// Time:  precompute: O(r)
//        runtime:    O(nlogr), prime gap is ln(r) on average
// Space: O(r)

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
    return pair(primes, spf);
};

const int MAX_NUMS = 1e5 + 3;
const auto& [PRIMES, SPF] = linear_sieve_of_eratosthenes(MAX_NUMS);

// number theory, prime gap
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            int x = nums[i];
            if (i % 2 == 0) {
                for (; SPF[x] != x; ++x) {
                    ++result;
                }
            } else {
                for (; SPF[x] == x; ++x) {
                    ++result;
                }
            }
        }
        return result;
    }
};

// Time:  precompute: O(r)
//        runtime:    O(nlogn)
// Space: O(r)
// number theory, binary search
class Solution2 {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            const auto& x = nums[i];
            if (i % 2 == 0) {
               result +=  *lower_bound(cbegin(PRIMES), cend(PRIMES), x) - x;
            } else {
                if (x == 2) {
                    result += 2;
                } else if (SPF[x] == x) {
                    ++result;
                }
            }
        }
        return result;
    }
};
