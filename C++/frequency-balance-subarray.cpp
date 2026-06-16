// Time:  O(n^2)
// Space: O(n)

// sort, coordinate compression, freq table
class Solution {
public:
    int getLength(vector<int>& nums) {
        vector<int> sorted_vals(nums);
        ranges::sort(sorted_vals);
        sorted_vals.erase(unique(begin(sorted_vals), end(sorted_vals)), end(sorted_vals));
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < size(sorted_vals); ++i) {
            val_to_idx[sorted_vals[i]] = i;
        }
        vector<int> arr(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            arr[i] = val_to_idx[nums[i]];
        }
        int result = 0;
        for (int left = 0; left < size(arr); ++left) {
            vector<int> cnt(size(arr)), cnt2(size(arr) + 1);
            int distinct = 0, total = 0, c = 0;
            for (int right = left; right < size(arr); ++right) {
                if (cnt[arr[right]]) {
                    if (--cnt2[cnt[arr[right]]] == 0) {
                        --c;
                        total -= cnt[arr[right]];
                    }
                }
                if (++cnt[arr[right]] == 1) {
                    ++distinct;
                }
                if (++cnt2[cnt[arr[right]]] == 1) {
                    total += cnt[arr[right]];
                    ++c;
                }
                if (distinct == 1 || (c == 2 && total % 3 == 0 && cnt2[total / 3])) {
                    result = max(result, right - left + 1);
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// freq table
class Solution2 {
public:
    int getLength(vector<int>& nums) {
        int result = 0;
        for (int left = 0; left < size(nums); ++left) {
            unordered_map<int, int> cnt, cnt2;
            int distinct = 0, total = 0, c = 0;
            for (int right = left; right < size(nums); ++right) {
                if (cnt[nums[right]]) {
                    if (--cnt2[cnt[nums[right]]] == 0) {
                        --c;
                        total -= cnt[nums[right]];
                    }
                }
                if (++cnt[nums[right]] == 1) {
                    ++distinct;
                }
                if (++cnt2[cnt[nums[right]]] == 1) {
                    total += cnt[nums[right]];
                    ++c;
                }
                if (distinct == 1 || (c == 2 && total % 3 == 0 && cnt2[total / 3])) {
                    result = max(result, right - left + 1);
                }
            }
        }
        return result;
    }
};
