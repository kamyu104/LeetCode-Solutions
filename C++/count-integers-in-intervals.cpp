// Time:  ctor:  O(1)
//        add:   O(logn), amortized
//        count: O(1)
// Space: O(n)

// design, bst
class CountIntervals {
public:
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = bst_.upper_bound({left});
        if (it != begin(bst_) && (*prev(it))[1] + 1 >= left) {
            --it;
            left = (*it)[0];
        }
        for (; it != end(bst_) && right + 1 >= (*it)[0]; it = bst_.erase(it)) {
            right = max(right, (*it)[1]);
            cnt_ -= (*it)[1] - (*it)[0] + 1;
        }
        bst_.insert({left, right});
        cnt_ += right - left + 1;
    }
    
    int count() {
        return cnt_;
    }

private:
    set<vector<int>> bst_;
    int cnt_ = 0;
};
