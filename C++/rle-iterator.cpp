// Time:  O(n)
// Space: O(1)

class RLEIterator {
public:
    RLEIterator(vector<int> A)
        : A_(move(A)), 
          i_{0},
          cnt_{0} {
        
    }
    
    int next(int n) {
        while (i_ < A_.size()) {
            if (n > A_[i_] - cnt_) {
                n -= A_[i_] - cnt_;
                cnt_ = 0;
                i_ += 2;
            } else {
                cnt_ += n;
                return A_[i_ + 1];
            }
        }
        return -1;
    }

private:
    const vector<int> A_;
    int i_;
    int cnt_;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
