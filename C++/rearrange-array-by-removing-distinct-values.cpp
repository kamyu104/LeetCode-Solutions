// Time:  O(nlogn)
// Space: O(n)

// freq table, sort
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        vector<int> vals;
        for (const auto& [x, _] : cnt) {
            vals.emplace_back(x);
        }
        ranges::sort(vals);
        vector<int> result;
        while (!empty(vals)) {
            vector<int> new_vals;
            for (const auto& x : vals) {
                result.emplace_back(x);
                if (--cnt[x]) {
                    new_vals.emplace_back(x);
                } 
            }
            vals = move(new_vals);
        }
        return result;
    }
};
