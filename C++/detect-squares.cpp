// Time:  ctor:  O(1)
//        add:   O(1)
//        count: O(n)
// Space: O(n)

class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        x_to_ys[point[0]].emplace(point[1]);
        ++point_counts_[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        int result = 0;
        for (const auto& y : x_to_ys[point[0]]) {
            if (y == point[1]) {
                continue;
            }
            const int dy = point[1] - y;
            result += point_counts_[point[0]][y] * point_counts_[point[0] + dy][point[1]] *  point_counts_[point[0] + dy][y];
            result += point_counts_[point[0]][y] * point_counts_[point[0] - dy][point[1]] *  point_counts_[point[0] - dy][y];
        }
        return result;
    }

private:
    unordered_map<int, unordered_set<int>> x_to_ys;
    unordered_map<int, unordered_map<int, int>> point_counts_;
};


// Time:  ctor:  O(1)
//        add:   O(1)
//        count: O(n)
// Space: O(n)
class DetectSquares2 {
public:
    DetectSquares2() {
        
    }
    
    void add(vector<int> point) {
        points_.emplace_back(point);
        ++point_counts_[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        int result = 0;
        for (const auto& p : points_) {
            int x = p[0], y = p[1];
            if (!(point[0] != x && point[1] != y && abs(point[0] - x) == abs(point[1] - y))) {
                continue;
            }
            result += point_counts_[point[0]][y] * point_counts_[x][point[1]];
        }
        return result;
    }

private:
    vector<vector<int>> points_;
    unordered_map<int, unordered_map<int, int>> point_counts_;
};
