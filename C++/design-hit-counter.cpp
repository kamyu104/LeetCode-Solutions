// Time:  O(1), amortized
// Space: O(k), k is the count of seconds.

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() : count_(0) {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        getHits(timestamp);
        if (!dq_.empty() && dq_.back().first == timestamp) {
            ++dq_.back().second;
        } else {
            dq_.emplace_back(timestamp, 1);
        }
        ++count_;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!dq_.empty() && dq_.front().first <= timestamp - k_) {
            count_ -= dq_.front().second;
            dq_.pop_front();
        }
        return count_;
    }

private:
    const int k_ = 300;
    int count_;
    deque<pair<int, int>> dq_;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
 
