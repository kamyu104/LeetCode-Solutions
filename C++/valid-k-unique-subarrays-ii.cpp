// Time:  O(n + q)
// Space: O(n)

// two pointers, hash table, prefix sum
class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, int l0, int r0, int q) {
        const auto& min_left = [&](int k) {
            vector<int> result(size(nums), size(nums));
            unordered_map<int, int> cnt;
            for (int right = 0, left = 0; right < size(nums); ++right) {
                ++cnt[nums[right]];
                while (size(cnt) == k + 1) {
                    --cnt[nums[left]];
                    if (!cnt[nums[left]]) {
                        cnt.erase(nums[left]);
                    }
                    ++left;
                }
                if (size(cnt) == k) {
                    result[right] = left;
                }
            }
            return result;
        };

        const auto& left = min_left(k);
        const auto& right = min_left(k - 1);
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        unordered_map<int, uint64_t> h;
        vector<uint64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            if (!h.count(nums[i])) {
                h[nums[i]] = rng();
            }
            prefix[i + 1] = prefix[i] ^ h[nums[i]];
        }
        vector<bool> result;
        result.reserve(q);
        for (int _ = 0, l = l0, r = r0; _ < q; ++_) {
            result.emplace_back((r - l + 1) % 2 == 0 && (prefix[r + 1] ^ prefix[l]) == 0 && left[r] <= l && l < right[r]);
            const auto& g = result.back() ? l + r : r - l;
            l = (l ^ g) % size(nums);
            r = (r ^ g) % size(nums);
            if (l > r) {
                swap(l, r);
            }
        }
        return result;
    }
};
