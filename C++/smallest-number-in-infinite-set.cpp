// Time:  ctor:        O(1)
//        popSmallest: O(logn)
//        addBack:     O(logn)
// Space: O(n)

// bst
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if (!empty(bst_)) {
            const int result = *cbegin(bst_);
            bst_.erase(result);
            return result;
        }
        return n_++;
    }
    
    void addBack(int num) {
        if (num >= n_) {
            return;
        }
        bst_.emplace(num);
    }

private:
    int n_ = 1;
    set<int> bst_;
};
