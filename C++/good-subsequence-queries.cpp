// Time:  precompute: O(rlog(logr))
//        runtime:    O(r + (n + q) * log(logr))
// Space: O(rlog(logr) + n)

// number theory, freq table
const auto& precompute = [](int r) {
    vector<vector<int>> factors(r + 1);
    int curr = 1, k = 0;
    for (int i = 2; i < size(factors); i++) {
        if (!empty(factors[i])) {
            continue;
        }
        if (curr * i <= r) {
            curr *= i;
            ++k;
        }
        for (int j = i; j < size(factors); j += i) {
            factors[j].emplace_back(i);
        }
    }
    return pair(factors, k);
};

const int MAX_NUMS = 50000;
const auto& [FACTORS, K] = precompute(MAX_NUMS);
class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        if (size(nums) == 1) {
            return 0;
        }
        int curr = 0;
        int mx = ranges::max(nums);
        for (const auto& q : queries) {
            mx = max(mx, q[1]);
        }
        vector<int> cnt(mx + 1), cnt2(size(nums) + 1);
        const auto& update = [&](int x, int d) {
            if (x % p) {
                return;
            }
            for (const auto& q : FACTORS[x / p]) {
                --cnt2[cnt[q]];
                cnt[q] += d;
                ++cnt2[cnt[q]];
            }
            curr += d;
        };

        const auto& check = [&]() {
            if (curr == 0 || cnt2[curr]) {
                return false;
            }
            if (curr != size(nums) || size(nums) > K) {
                return true;
            }
            for (int i = 0; i < size(nums); ++i) {
                update(nums[i], -1);
                const auto& found = (cnt2[curr] == 0);
                update(nums[i], +1);
                if (found) {
                    return true;
                }
            }
            return false;
        };

        int result = 0;
        for (const auto& x : nums) {
            update(x, +1);
        }
        for (const auto& q : queries) {
            const auto& i = q[0], &x = q[1];
            update(nums[i], -1);
            nums[i] = x;
            update(nums[i], +1);
            if (check()) {
                ++result;
            }
        }
        return result;
    }
};
