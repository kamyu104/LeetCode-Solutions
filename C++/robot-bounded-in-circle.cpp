// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isRobotBounded(string instructions) {
        static const vector<vector<int>>& directions = {{ 1, 0}, {0, -1},
                                                        {-1, 0}, {0, 1}};
        int x = 0, y = 0, i = 0;
        
        for (const auto& instruction : instructions) {
            if (instruction == 'R') {
                i = (i + 1) % 4;
            } else if (instruction == 'L') {
                i = (4 + i - 1) % 4;
            } else {
                x += directions[i][0], y += directions[i][1];
            }
        }
        return (x == 0 && y == 0) || i > 0;
    }
};
