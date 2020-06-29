// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int result = numeric_limits<int>::min();
        deque<int> dq;
        for (int i = 0; i < points.size(); ++i) {
            const auto& x = points[i][0], &y = points[i][1];
            while(!dq.empty() && points[dq.front()][0] < x - k) {
                dq.pop_front();
            }
            if (!dq.empty()) {
                result = max(result, points[dq.front()][1] - points[dq.front()][0] + y + x);
            }
            while(!dq.empty() && points[dq.back()][1] - points[dq.back()][0] <= y - x) {
                dq.pop_back();
            }
            dq.emplace_back(i);
        }
        return result;
    }
};
