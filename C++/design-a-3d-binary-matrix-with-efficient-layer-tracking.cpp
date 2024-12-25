// Time:  ctor:          O(1)
//        setCell:       O(logn)
//        unsetCell:     O(logn)
//        largestMatrix: O(logn)
// Space: O(n^3)

// bst
class Matrix3D {
private:
    int n_;
    unordered_map<int, unordered_map<int, unordered_set<int>>> matrix_;
    unordered_map<int, int> cnt_;
    map<int, set<int>> bst_;

public:
    Matrix3D(int n) : n_(n) {
        bst_[0].emplace(n - 1);
    }
    
    void setCell(int x, int y, int z) {
        if (matrix_[x][y].count(z)) {
            return;
        }
        matrix_[x][y].emplace(z);
        if (cnt_[x] || x == n_ - 1) {
            bst_[cnt_[x]].erase(x);
            if (empty(bst_[cnt_[x]])) {
                bst_.erase(cnt_[x]);
            }
        }
        ++cnt_[x];
        bst_[cnt_[x]].emplace(x);
    }
    
    void unsetCell(int x, int y, int z) {
        if (!matrix_.count(x) || !matrix_[x].count(y) || !matrix_[x][y].count(z)) {
            return;
        }
        matrix_[x][y].erase(z);
        if (empty(matrix_[x][y])) {
            matrix_[x].erase(y);
            if (empty(matrix_[x])) {
                matrix_.erase(x);
            }
        }
        bst_[cnt_[x]].erase(x);
        if (empty(bst_[cnt_[x]])) {
            bst_.erase(cnt_[x]);
        }
        --cnt_[x];
        if (cnt_[x] || x == n_ - 1) {
            bst_[cnt_[x]].emplace(x);
        }
    }
    
    int largestMatrix() {
        return *rbegin(rbegin(bst_)->second);
    }
};

// Time:  ctor:          O(1)
//        setCell:       O(logn)
//        unsetCell:     O(logn)
//        largestMatrix: O(logn) on average
// Space: O(n^3)
// heap
class Matrix3D_2 {
private:
    unordered_map<int, unordered_map<int, unordered_set<int>>> matrix_;
    unordered_map<int, int> cnt_;
    priority_queue<pair<int, int>> max_heap_;

public:
    Matrix3D_2(int n) {
        max_heap_.emplace(cnt_[n - 1], n - 1);
    }
    
    void setCell(int x, int y, int z) {
        if (matrix_[x][y].count(z)) {
            return;
        }
        matrix_[x][y].emplace(z);
        ++cnt_[x];
        max_heap_.emplace(cnt_[x], x);
    }
    
    void unsetCell(int x, int y, int z) {
        if (!matrix_.count(x) || !matrix_[x].count(y) || !matrix_[x][y].count(z)) {
            return;
        }
        matrix_[x][y].erase(z);
        if (empty(matrix_[x][y])) {
            matrix_[x].erase(y);
            if (empty(matrix_[x])) {
                matrix_.erase(x);
            }
        }
        --cnt_[x];
        max_heap_.emplace(cnt_[x], x);
    }
    
    int largestMatrix() {
        while (!empty(max_heap_) && max_heap_.top().first != cnt_[max_heap_.top().second]) {
            max_heap_.pop();
        }
        return max_heap_.top().second;
    }
};

