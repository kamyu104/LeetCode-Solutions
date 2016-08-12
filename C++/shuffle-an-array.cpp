// Time:  O(n)
// Space: O(n)

class Solution {
public:
    Solution(vector<int> nums) : nums_(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums{nums_};
        default_random_engine seed((random_device())());
        for (int i = 0; i < nums.size(); ++i) {
            swap(nums[i],  nums[uniform_int_distribution<int>{
                                i, static_cast<int>(nums.size()) - 1}(seed)]);
        }
        return nums;
    }

private:
    const vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
 
