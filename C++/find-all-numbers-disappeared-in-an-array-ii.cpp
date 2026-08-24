// Time:  O(r)
// Space: O(r)

// hash table
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<bool> lookup(upper - lower + 1);
        for (const auto& x : nums) {
            if (!(lower <= x && x <= upper)) {
                continue;
            }
            lookup[x - lower] = true;
        }
        vector<vector<int>> result;
        for (int i = 0, l = 0; i < size(lookup); ++i) {
            ++l;
            if (i + 1 == size(lookup) || lookup[i + 1] != lookup[i]) {
                if (!lookup[i]) {
                    result.push_back({lower + (i - l + 1), lower + i});
                }
                l = 0;
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort
class Solution2 {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        vector<vector<int>> result;
        for (const auto& x : nums) {
            if (x > upper) {
                break;
            }
            if (x < lower) {
                continue;
            }
            if (lower <= x - 1) {
                result.push_back({lower, x - 1});
            }
            lower = x + 1;
        }
        if (lower <= upper) {
            result.push_back({lower, upper});
        }
        return result;
    }
};
