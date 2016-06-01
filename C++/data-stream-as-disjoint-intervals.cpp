// Time:  addNum: O(logn), getIntervals: O(n), n is the number of disjoint intervals.
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
// Using map.
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (intervals_.empty()) {
            intervals_.emplace(val, val);
        } else {
            auto it = intervals_.upper_bound(val);
            if (it == intervals_.end()) {
                if (prev(it)->second + 1 == val) {
                    prev(it)->second = val;
                } else if (prev(it)->second + 1 < val) {
                    intervals_[val] = val;
                }
            } else {
                if (it != intervals_.begin() && prev(it)->second + 1 == val) {
                    prev(it)->second = val;
                } else if (it == intervals_.begin() || prev(it)->second + 1 < val) {
                    intervals_[val] = val;
                }
                if (prev(it)->second + 1 == it->first) {
                    prev(it)->second = it->second;
                    intervals_.erase(it);
                }
            }
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for (const auto& kvp : intervals_) {
            result.emplace_back(kvp.first, kvp.second);
        }
        return result;
    }

private:
    map<int, int> intervals_;
};


// Using set.
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = intervals_.upper_bound(Interval(val, val));
        int start = val, end = val;
        if (it != intervals_.begin() && prev(it)->end + 1 >= val) {
            --it;
        }
        while (it != intervals_.end() && end + 1 >= it->start) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = intervals_.erase(it);
        }
        intervals_.insert(it, Interval(start, end));
    }

    vector<Interval> getIntervals() {
        return vector<Interval>(intervals_.begin(), intervals_.end());
    }

private:
    struct Compare {
        bool operator() (const Interval& a, const Interval& b) {
            return a.start < b.start;
        }
    };
    set<Interval, Compare> intervals_;
};


// Time:  addNum: O(n), getIntervals: O(n), n is the number of disjoint intervals.
// Space: O(n)
class SummaryRanges2 {
public:
public:
    /** Initialize your data structure here. */
    SummaryRanges2() {
        
    }
    
    void addNum(int val) {
        auto it = upper_bound(intervals_.begin(), intervals_.end(), Interval(val, val), Compare());
        int start = val, end = val;
        if (it != intervals_.begin() && prev(it)->end + 1 >= val) {
            --it;
        }
        while (it != intervals_.end() && end + 1 >= it->start) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = intervals_.erase(it);
        }
        intervals_.insert(it, Interval(start, end));
    }

    vector<Interval> getIntervals() {
        return intervals_;
    }

private:
    struct Compare {
        bool operator() (const Interval& a, const Interval& b) {
            return a.start < b.start;
        }
    };
    vector<Interval> intervals_;
};


// Time:  addNum: O(logs), getIntervals: O(s), s is the data stream's size.
// Space: O(s)
class SummaryRanges3 {
public:
    /** Initialize your data structure here. */
    SummaryRanges3() {
        
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
 
