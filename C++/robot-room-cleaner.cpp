// Time:  O(n), n is the number of cells
// Space: O(n)

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

    void cleanRoom(Robot& robot) {
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        dfs({0, 0}, robot, 0, &lookup);
    }
    
private:
    void dfs(const pair<int, int>& pos, Robot& robot, int dir,
             unordered_set<pair<int, int>, PairHash<int>> *lookup) {
        if (lookup->count(pos)) {
            return;
        }
        lookup->emplace(pos);

        robot.clean();
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < directions.size(); ++i, dir = (dir + 1) % directions.size()) {
            if (robot.move()) {
                dfs({pos.first + directions[dir].first,
                     pos.second + directions[dir].second},
                     robot, dir, lookup);
                goBack(robot);
            }
            robot.turnRight();
        }
    }

    void goBack(Robot& robot) {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};
