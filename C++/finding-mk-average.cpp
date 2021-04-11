// Time:  ctor:           O(1)
//        add_element:    O(logn)
//        calc_mkaverage: O(1)
// Space: O(m)

class MKAverage {
public:
    MKAverage(int m, int k)
     : m_{m}
     , k_{k} {
        
    }
    
    void addElement(int num) {
        if (size(dq_) == m_) {
            remove(dq_.front());
            dq_.pop_front();
        }
        dq_.emplace_back(num);
        add(num);
    }
    
    int calculateMKAverage() {
        if (size(dq_) < m_) {
            return -1;
        }
        return total_ / (m_ - 2 * k_);
    }

private:
    void add(int num) {
        left_.emplace(num);
        if (size(left_) > k_) {
            const auto it = prev(end(left_));
            mid_.emplace(*it);
            total_ += *it;
            left_.erase(it);
        }
        if (size(mid_) > (m_ - 2 * k_)) {
            const auto it = prev(end(mid_));
            total_ -= *it;
            right_.emplace(*it);
            mid_.erase(it);
        }
    }

    void remove(int num) {
        if (num <= *rbegin(left_)) {
            left_.erase(left_.find(num));
        } else if (num <= *rbegin(mid_)) {
            auto it = mid_.find(num); 
            total_ -= *it;
            mid_.erase(it);
        } else {
            right_.erase(right_.find(num));
        }
        if (size(left_) < k_) {
            left_.emplace(*begin(mid_));
            total_ -= *begin(mid_);
            mid_.erase(begin(mid_));
        }
        if (size(mid_) < (m_ - 2 * k_)) {
            mid_.emplace(*begin(right_));
            total_ += *begin(right_);
            right_.erase(begin(right_));
        }
    }

    int m_;
    int k_;
    deque<int> dq_;
    multiset<int> left_, mid_, right_;
    int64_t total_ = 0;
};
