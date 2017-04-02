// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> indices(nums.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
             [&nums](int a, int b) {
                 return nums[a] > nums[b];  
             });
        
        const vector<string> ranks = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            result[indices[i]] = i > 2 ? to_string(i + 1) : ranks[i];
        }
        return result;
    }
};
