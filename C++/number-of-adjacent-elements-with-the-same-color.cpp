// Time:  O(n + q)
// Space: O(n)

// array
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n);
        const auto& update = [&](int i) {
            if (!nums[i]) {
                return 0;
            }
            int cnt = 0;
            if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
                ++cnt;
            }
            if (i + 1 < n && nums[i + 1] == nums[i]) {
                ++cnt;
            }
            return cnt;
        };

        vector<int> result(size(queries));
        for (int idx = 0, curr = 0; idx < size(queries); ++idx) {
            curr -= update(queries[idx][0]);
            nums[queries[idx][0]] = queries[idx][1];
            curr += update(queries[idx][0]);
            result[idx] = curr;
        }
        return result;
    }
};
