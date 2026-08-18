// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int result = -1, mn = numeric_limits<int>::max();
        for (int i = 0; i < size(drones); ++i) {
            const auto& dist = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if (dist > drones[i][2] || dist >= mn) {
                continue;
            }
            mn = dist;
            result = i;
        }
        return result;
    }
};
