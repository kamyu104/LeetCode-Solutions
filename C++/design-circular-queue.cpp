// Time:  O(1)
// Space: O(k)

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) :
        start_(0),
        size_(0),
        buffer_(k, 0) {
        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        buffer_[(start_ + size_) % buffer_.size()] = value;
        ++size_;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        start_ = (start_ + 1) % buffer_.size();
        --size_;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : buffer_[start_];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : buffer_[(start_ + size_ - 1) % buffer_.size()];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size_ == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size_ == buffer_.size();
    }

private:
    int start_;
    int size_;
    vector<int> buffer_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
 
