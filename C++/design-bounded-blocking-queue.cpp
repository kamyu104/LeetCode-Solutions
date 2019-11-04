// Time:  O(n)
// Space: O(1)

class BoundedBlockingQueue {
public:    
    BoundedBlockingQueue(int capacity)
      : cap_(capacity) {
        
    }
    
    void enqueue(int element) {
        {
            unique_lock<mutex> l(m_);
            cv_.wait(l, [this]() { return q_.size() != cap_; }) ;
            q_.emplace(element);
        }
        cv_.notify_all();
    }
    
    int dequeue() {
        int element;
        {
            unique_lock<mutex> l(m_);
            cv_.wait(l, [this]() { return !q_.empty(); }) ;
            element = q_.front(); q_.pop();
        }
        cv_.notify_all();
        return element;
    }
    
    int size() {
        unique_lock<mutex> l(m_);
        return q_.size();
    }

private:
    mutex m_;
    condition_variable cv_;
    queue<int> q_;
    int cap_;
};
