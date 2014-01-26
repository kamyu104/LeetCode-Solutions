// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int maxArea(vector<int> &height) {
            int start = 0, end = height.size() - 1, ans = 0;

            while(start < end) {
                if(height[start] <= height[end]) {
                    ans = max(ans, height[start] * (end - start));
                    start++;
                }
                if(height[start] > height[end]) {
                    ans = max(ans, height[end] * (end - start));
                    end--;
                }
            }
            return ans;
        }
};
