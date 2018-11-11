// Time:  O(1) on average
// Space: O(w), w means the size of the last milliseconds

class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        q_.emplace(t);
        while (q_.front() < t - 3000) {
            q_.pop();
        }
        return q_.size();
    }

private:
    queue<int> q_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
 
