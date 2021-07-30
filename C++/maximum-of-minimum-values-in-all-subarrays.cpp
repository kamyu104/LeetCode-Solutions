// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) {
        const auto& left = find_bound(nums, 0, size(nums), -1);
        const auto& right = find_bound(nums, size(nums) - 1, -1, size(nums));
        vector<int> result(size(nums), -1);
        for (int i = 0; i < size(nums); ++i) {
            result[((right[i] - 1) - left[i]) - 1] = max(result[((right[i] - 1) - left[i]) - 1], nums[i]);
        }
        for (int i = size(nums) - 2; i >= 0; --i) {
            result[i] = max(result[i], result[i + 1]);
        }
        return result;
    }

private:
    vector<int> find_bound(const vector<int>& nums, int begin, int end, int init) {
        vector<int> result(abs(end - begin), init);
        vector<int> stk = {init};
        const int d = (end - begin) > 0 ? 1 : -1;
        for (int i = begin; i != end; i += d) {
            while (stk.back() != -1 && stk.back() != size(nums) && nums[stk.back()] >= nums[i]) {
                stk.pop_back();
            }
            result[i] = stk.back();
            stk.emplace_back(i);
        }
        return result;
    }
};
