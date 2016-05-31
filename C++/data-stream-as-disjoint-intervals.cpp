// Time:  addNum: O(n), getIntervals: O(n), n is the number of disjoint intervals.
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
        if (intervals_.empty()) {
            intervals_.emplace_back(val, val);
        } else {
            auto it = upper_bound(intervals_.begin(), intervals_.end(), val,
                                  [](int d, const Interval& x) { return d < x.start; });
            if (it == intervals_.end()) {
                if (prev(it)->end + 1 == val) {
                    prev(it)->end = val;
                } else if (prev(it)->end + 1 < val) {
                    intervals_.insert(it, Interval(val, val));
                }
            } else {
                if (it != intervals_.begin() && prev(it)->end + 1 == val) {
                    prev(it)->end = val;
                } else if (it == intervals_.begin() || prev(it)->end + 1 < val) {
                    intervals_.insert(it, Interval(val, val));
                }
                it = upper_bound(intervals_.begin(), intervals_.end(), val, ub_cmp);
                if (prev(it)->end + 1 == it->start) {
                    prev(it)->end = it->end;
                    intervals_.erase(it);
                }
            }
        }
    }
    
    vector<Interval> getIntervals() {
        return intervals_;
    }

private:
    vector<Interval> intervals_;
};


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
 
