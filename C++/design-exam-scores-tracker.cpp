// Time:  ctor:        O(1)
//        record:      O(1)
//        totalScore: O(logn)
// Space: O(n)

// prefix sum, binary search
class ExamTracker {
public:
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        times_.emplace_back(time);
        prefix_.emplace_back(prefix_.back() + score);
    }
    
    long long totalScore(int startTime, int endTime) {
        const int i = distance(begin(times_), lower_bound(begin(times_), end(times_), startTime));
        const int j = distance(begin(times_), upper_bound(begin(times_), end(times_), endTime)) - 1;
        return prefix_[j + 1] - prefix_[i];
    }

private:
    vector<int> times_;
    vector<int64_t> prefix_ = {0};
};
