// Time:  O(1)
// Space: O(w)

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : size_(size), sum_(0) {
    }
    
    double next(int val) {
        if (q_.size() == size_) {
            sum_ -= q_.front();
            q_.pop();
        }
        q_.emplace(val);
        sum_ += val;
        return 1.0 * sum_ / q_.size();
    }

private:
    int size_;
    int sum_;
    queue<int> q_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
 
