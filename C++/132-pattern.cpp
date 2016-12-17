// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int ak = numeric_limits<int>::min();
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < ak) {
                return true;
            } else {
                while (!st.empty() && nums[i] > st.top()) {
                    ak = st.top(), st.pop(); 
                }
            }
            st.emplace(nums[i]);
        }
        return false;
    }
};
