// Time:  O(1)
// Space: O(k)

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) :
        start_(0),
        size_(0),
        buffer_(k, 0) {
        
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        start_ = (start_ - 1 + buffer_.size()) % buffer_.size();
        buffer_[start_] = value;
        ++size_;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        buffer_[(start_ + size_) % buffer_.size()] = value;
        ++size_;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        start_ = (start_ + 1) % buffer_.size();
        --size_;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --size_;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : buffer_[start_];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : buffer_[(start_ + size_ - 1) % buffer_.size()];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size_ == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size_ == buffer_.size();
    }

private:
    int start_;
    int size_;
    vector<int> buffer_;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
 
