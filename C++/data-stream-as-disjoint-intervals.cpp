// Time:  addNum: O(logn), getIntervals: O(n)
// Space: O(n)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        nums_.emplace(val);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        if (nums_.empty()) {
            return result;
        }
        auto start = *nums_.begin(), end = *nums_.begin();
        for (auto it = next(nums_.begin()); it != nums_.end(); ++it) {
            if (it != nums_.end() && *it == end + 1) {
                end = *it;
            } else  {
                result.emplace_back(start, end);
                if (it != nums_.end()) {
                    start = end = *it;
                }
            }
        }
        result.emplace_back(start, end);
        return result;
    }

private:
    set<int> nums_;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
 
