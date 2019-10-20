// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const auto& i = coordinates[0], &j = coordinates[1];
        return all_of(coordinates.cbegin() + 2,
                      coordinates.cend(),
                      [&](const auto& k) {
                          return i[0] * j[1] - j[0] * i[1] +
                                 j[0] * k[1] - k[0] * j[1] +
                                 k[0] * i[1] - i[0] * k[1] == 0;
                      }
               );
    }
};
