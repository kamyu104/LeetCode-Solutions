// Time:  O(n * r^2)
// Space: O(min(n * r^2, max_x * max_y))

// math, hash table
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int max_y = 0;
        for (const auto& circle : circles) {
            max_y = max(max_y, circle[1] + circle[2]);
        }
        unordered_set<int> lookup;
        for (const auto& circle : circles) {
            for (int i = -circle[2]; i <= circle[2]; ++i) {
                for (int j = -circle[2]; j <= circle[2]; ++j) {
                    if (i * i + j * j <= circle[2] * circle[2]) {
                        lookup.insert((circle[0] + i) * (max_y + 1) + (circle[1] + j));
                    }
                }
            }
        }
        return size(lookup);
    }
};


// Time:  O(n * max_x * max_y)
// Space: O(1)
// math
class Solution2 {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int max_x = 0, max_y = 0;
        for (const auto& circle : circles) {
            max_x = max(max_x, circle[0] + circle[2]);
            max_y = max(max_y, circle[1] + circle[2]);
        }
        int result = 0;
        for (int i = 0; i <= max_x; ++i) {
            for (int j = 0; j <= max_y; ++j) {
                 for (const auto& circle : circles) {
                    if ((i - circle[0]) * (i - circle[0]) + (j - circle[1]) * (j - circle[1]) <= (circle[2]) * circle[2]) {
                        ++result;
                        break;
                    }
                }
            }
        }
        return result;
    }
};
