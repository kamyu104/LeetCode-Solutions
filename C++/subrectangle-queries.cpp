// Time:  ctor:   O(1)
//        update: O(1)
//        get:    O(u), u is the number of updates
// Space: O(u)

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle)
      : rectangle_(rectangle) {
        
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates_.emplace_back(row1, col1, row2, col2, newValue);
    }
    
    int getValue(int row, int col) {
        for (int i = updates_.size() - 1; i >= 0; --i) {
            const auto& [row1, col1, row2, col2, newValue] = updates_[i];
            if (row1 <= row && row <= row2 &&
                col1 <= col && col <= col2) {
                return newValue;
            }
        }
        return rectangle_[row][col];
    }

private:
    const vector<vector<int>>& rectangle_;
    vector<tuple<int, int, int, int, int>> updates_;
};

// Time:  ctor:   O(1)
//        update: O(m * n)
//        get:    O(1)
// Space: O(1)
class SubrectangleQueries2 {
public:
    SubrectangleQueries2(vector<vector<int>>& rectangle)
      : rectangle_(rectangle) {
        
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int r = row1; r <= row2; ++r) {
            for (int c = col1; c <= col2; ++c) {
                rectangle_[r][c] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rectangle_[row][col];
    }

private:
    vector<vector<int>>& rectangle_;
};
