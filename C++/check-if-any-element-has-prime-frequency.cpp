// Time:  precompute: O(MAX_N)
//        runtime: O(n)
// Space: O(MAX_N)

// number theory, freq table
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

const int MAX_N = 100;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_N);
class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        return any_of(cbegin(cnt), cend(cnt), [](const auto& x) {
            return SPF[x.second] == x.second;
        });
    }
};
