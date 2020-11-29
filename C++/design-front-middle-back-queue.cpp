// Time:  O(1)
// Space: O(n)

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        left_.emplace_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if (size(left_) > size(right_)) {
            right_.emplace_front(left_.back());
            left_.pop_back();
        }
        left_.emplace_back(val);
    }
    
    void pushBack(int val) {
        right_.emplace_back(val);
        balance();
    }
    
    int popFront() {
        int result = -1;
        if (!empty(left_)) {
            result = left_.front();
            left_.pop_front();
        }
        balance();
        return result;
    }
    
    int popMiddle() {
        int result = -1;
        if (!empty(left_)) {
            result = left_.back();
            left_.pop_back();
        }
        balance();
        return result;
    }
    
    int popBack() {
        int result = -1;
        if (!empty(right_)) {
            result = right_.back();
            right_.pop_back();
        } else if (!empty(left_)) {
            result = left_.back();
            left_.pop_back();
        }
        balance();
        return result;
    }

private:
    void balance() {
        if (size(left_) > size(right_) + 1) {
            right_.emplace_front(left_.back());
            left_.pop_back();
        } else if (size(left_) < size(right_) ) {
            left_.emplace_back(right_.front());
            right_.pop_front();
        }
    }

    // using list<int> is also fine but slower
    deque<int> left_;
    deque<int> right_;
};
