// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int result = 0;
        queue<int> q;
        for (const auto& box : initialBoxes) {
            q.emplace(box);
        }
        while (!q.empty()) {
            bool changed = false;
            for (int i = q.size() - 1; i >= 0; --i) {
                const auto box = q.front(); q.pop();
                if (!status[box]) {
                    q.emplace(box);
                    continue;
                }
                changed = true;
                result += candies[box];
                for (const auto& contained_key : keys[box]) {
                    status[contained_key] = 1;
                }
                for (const auto& contained_box : containedBoxes[box]) {
                    q.emplace(contained_box);
                }
            }
            if (!changed) {
                break;
            }
        }
        return result;
    }
};
