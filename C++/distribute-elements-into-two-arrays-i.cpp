// Time:  O(n)
// Space: O(n)

// array
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a = {nums[0]}, b = {nums[1]};
        for (int i = 2; i < size(nums); ++i) {
            if (a.back() > b.back()) {
                a.emplace_back(nums[i]);
            } else {
                b.emplace_back(nums[i]);
            }
        }
        a.insert(end(a), cbegin(b), cend(b));
        return a;
    }
};
