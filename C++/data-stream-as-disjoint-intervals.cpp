// Time:  addNum: O(n), getIntervals: O(n), i is the number of disjoint intervals.
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
        Interval newInterval(val, val);
        size_t i = 0;
        vector<Interval> result;
        // Insert intervals appeared before newInterval.
        while (i < intervals_.size() && intervals_[i].end + 1 < newInterval.start) {
            result.emplace_back(intervals_[i++]);
        }

        // Merge intervals that overlap with newInterval.
        while (i < intervals_.size() && newInterval.end + 1 >= intervals_[i].start) {
            newInterval = {min(newInterval.start, intervals_[i].start),
                max(newInterval.end, intervals_[i].end)};
            ++i;
        }
        result.emplace_back(newInterval);

        // Insert intervals appearing after newInterval.
        result.insert(result.end(), intervals_.cbegin() + i, intervals_.cend());
        swap(result, intervals_);
    }
    
    vector<Interval> getIntervals() {
        return intervals_;
    }

private:
    vector<Interval> intervals_;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

// Time:  addNum: O(logs), getIntervals: O(s), s is the data stream's size.
// Space: O(s)
class SummaryRanges2 {
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
 
