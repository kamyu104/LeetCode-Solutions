// Time:  ctor:    O(r)
//        runtime: O(nlogr)
// Space: O(r)

// number theory, freq table, two pointers
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

const int MAX_NUMS = 1e5;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_NUMS);
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        const auto& prime_factors = [](int x) {
            unordered_map<int, int> cnt;
            while (x != 1) {
                ++cnt[SPF[x]];
                x /= SPF[x];
            }
            return cnt;
        };

        unordered_map<int, int> cnt;
        int result = 0, left = 0;
        for (const auto& x : nums) {
            for (const auto& [p, c] : prime_factors(x)) {
                cnt[p] += c;
            }
            if (size(cnt) <= k) {
                continue;
            }
            for (const auto& [p, c] : prime_factors(nums[left])) {
                cnt[p] -= c;
                if (!cnt[p]) {
                    cnt.erase(p);
                }
            }
            ++left;
        }
        return size(nums) - left;
    }
};

// Time:  ctor:    O(r)
//        runtime: O(nlogr)
// Space: O(r)
// number theory, freq table, two pointers
class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int k) {
        const auto& prime_factors = [](int x) {
            unordered_map<int, int> cnt;
            while (x != 1) {
                ++cnt[SPF[x]];
                x /= SPF[x];
            }
            return cnt;
        };

        unordered_map<int, int> cnt;
        int result = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            for (const auto& [p, c] : prime_factors(nums[right])) {
                cnt[p] += c;
            }
            for (; size(cnt) > k; ++left) {
                for (const auto& [p, c] : prime_factors(nums[left])) {
                    cnt[p] -= c;
                    if (!cnt[p]) {
                        cnt.erase(p);
                    }
                }
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
