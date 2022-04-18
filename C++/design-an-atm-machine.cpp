// Time:  ctor:     O(1)
//        deposit:  O(1)
//        withdraw: O(1)
// Space: O(1)

// greedy
class ATM {
public:
    ATM()
     :  vals_{20, 50, 100, 200, 500}
     ,  cnt_(size(vals_)) {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < size(cnt_); ++i) {
            cnt_[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> result(size(cnt_));
        for (int i = size(vals_) - 1; i >= 0; --i) {
            result[i] = min(static_cast<int64_t>(amount) / vals_[i], cnt_[i]);
            amount -= result[i] * vals_[i];
        }
        if (amount) {
            return {-1};
        }
        for (int i = 0; i < size(result); ++i) {
            cnt_[i] -= result[i];
        }
        return result;
    }

private:
    const vector<int> vals_;
    vector<int64_t> cnt_;
};
