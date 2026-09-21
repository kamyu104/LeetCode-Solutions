// Time:  O(nlogn)
// Space: O(n)

// merge sort, mono stack
class Solution {
public:
    int shadowPairs(vector<int>& nums) {
        const auto& merge_and_count = [&](const auto& left, const auto& right) {
            vector<int> merged;
            merged.reserve(size(left) + size(right));
            int cnt = 0;
            vector<int> stk1;
            vector<pair<int, int>> stk2;
            int i = 0;
            for (const auto& idx : right) {
                for (; i < size(left) && left[i] < idx; ++i) {
                    while (!empty(stk1) && stk1.back() < nums[left[i]]) {
                        stk1.pop_back();
                    }
                    if (!empty(stk2)) {
                        stk2.back().second = min<int>(stk2.back().second, size(stk1));
                    }
                    stk1.emplace_back(nums[left[i]]);
                    merged.emplace_back(left[i]);
                }
                while (!empty(stk2) && stk2.back().first >= nums[idx]) {
                    const auto base = stk2.back().second; stk2.pop_back();
                    if (!empty(stk2)) {
                        stk2.back().second = min(stk2.back().second, base);
                    }
                }
                cnt += size(stk1) - (!empty(stk2) ? stk2.back().second : 0);
                stk2.emplace_back(nums[idx], size(stk1));
                merged.emplace_back(idx);
            }
            for (; i < size(left); ++i) {
                merged.emplace_back(left[i]);
            }
            return pair(merged, cnt);
        };

        vector<int> vals(nums);
        ranges::sort(vals);
        vals.erase(begin(ranges::unique(vals)), end(vals));
        unordered_map<int, int> val_to_idx;
        for (const auto& [i, x] : views::enumerate(vals)) {
            val_to_idx[x] = i;
        }
        vector<vector<int>> groups(size(vals));
        for (int i = 0; i < size(nums); ++i) {
            groups[val_to_idx[nums[i]]].emplace_back(i);
        }
        int result = 0;
        while (size(groups) != 1) {
            vector<vector<int>> new_groups;
            for (int i = 0; i + 1 < size(groups); i += 2) {
                const auto& [merged, cnt] = merge_and_count(groups[i], groups[i + 1]);
                result += cnt;
                new_groups.emplace_back(move(merged));
            }
            if (size(groups) % 2) {
                new_groups.emplace_back(move(groups.back()));
            }
            groups = move(new_groups);
        }
        return result;
    }
};
