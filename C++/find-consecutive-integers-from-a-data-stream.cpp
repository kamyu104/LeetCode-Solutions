// Time:  O(1)
// Space: O(1)

// array
class DataStream {
public:
    DataStream(int value, int k) : value_(value), k_(k) {
        
    }
    
    bool consec(int num) {
        if (num == value_) {
            ++cnt_;
        } else {
            cnt_ = 0;
        }
        return cnt_ >= k_;
    }

private:
    int value_;
    int k_;
    int cnt_ = 0;
};
