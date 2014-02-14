// Time Complexity: O(n)
// Space Complexity: O(n)

Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            const int n = height.size();
            stack<int> s;
            int ans = 0;
            if(n == 0) return 0;

            height.push_back(0);

            for(int i = 0; i < n + 1;) {
                if(s.empty() || height[s.top()] < height[i])
                    s.push(i++);
                else {
                    int tmp = s.top();
                    s.pop();
                    ans = max(ans, height[tmp] * (s.empty()? i : i - s.top() - 1));
                }
            }
            return ans;
        }
};
