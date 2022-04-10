// Time:  O(nlogn)
// Space: O(1)

// math, sort
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;
        sort(begin(nums), end(nums));
        auto total = accumulate(cbegin(nums), cend(nums), 0ll);
        int i = size(nums) - 1;
        for (; i >= 0; --i) {
            if (nums[i] * static_cast<int64_t>(i + 1) - total <= k) {
                break;
            }
            total -= nums[i];
        }
        const int q = (k + total) / (i + 1);
        const int r = (k + total) % (i + 1);
        return ((static_cast<uint64_t>(powmod(q, (i + 1) - r, MOD)) * powmod(q + 1, r, MOD) % MOD) *
                accumulate(cbegin(nums) + i + 1, cend(nums), 1ull,
                          [=](const auto& total, const auto& x) {
                              return total * x % MOD;
                          })) % MOD;
    }

private:
    uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
        a %= mod;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = result * a % mod;
            }
            a = uint64_t(a) * a % mod;
            b >>= 1;
        }
        return result;
    }
};

// Time:  O(n + k)
// Space: O(n)
// freq table
class Solution2 {
public:
    int maximumProduct(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;
        unordered_map<int, int> cnt;
        int min_num = numeric_limits<int>::max();
        for (const auto& x : nums) {
            ++cnt[x];
            min_num = min(min_num, x);
        }
        while (k) {
            const auto c = min(cnt[min_num], k);
            cnt[min_num] -= c;
            cnt[min_num + 1] += c;
            if (!cnt[min_num]) {
                cnt.erase(min_num);
                ++min_num;
            }
            k -= c;
        }
        return accumulate(cbegin(cnt), cend(cnt), 1ull,
                          [=](const auto& total, const auto& x) {
                              static const int MOD = 1e9 + 7;
                              return total * powmod(x.first, x.second, MOD) % MOD;
                          });
    }

private:
    uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
        a %= mod;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = result * a % mod;
            }
            a = uint64_t(a) * a % mod;
            b >>= 1;
        }
        return result;
    }
};

// Time:  O(n + klogn)
// Space: O(1)
// heap
class Solution3 {
public:
    int maximumProduct(vector<int>& nums, int k) {
        make_heap(begin(nums), end(nums), greater<int>());
        while (--k >= 0) {
            int x = nums.front();
            pop_heap(begin(nums), end(nums), greater<int>()); nums.pop_back();
            nums.emplace_back(x + 1);
            push_heap(begin(nums), end(nums), greater<int>());
        }
        return accumulate(cbegin(nums), cend(nums), 1ull,
                          [](const auto& total, const auto& x) {
                              static const int MOD = 1e9 + 7;
                              return total * x % MOD;
                          });
    }
};
