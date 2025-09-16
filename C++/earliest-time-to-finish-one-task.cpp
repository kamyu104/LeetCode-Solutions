// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        const auto it = min_element(
            cbegin(tasks), cend(tasks),
            [](const auto& a, const auto& b) {
                return a[0] + a[1] < b[0] + b[1];
            }
        );
        return (*it)[0] + (*it)[1];
    }
};
