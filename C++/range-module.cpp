// Time:  addRange:    O(n)
//        removeRange: O(n)
//        queryRange:  O(logn)
// Space: O(n)

class RangeModule {
public:
    RangeModule() {
        
    }
    
    // Time:  O(n)
    void addRange(int left, int right) {
        vector<pair<int, int>> tmp;
        int i = 0;
        for (const auto& interval: intervals_) {
            if (right < interval.first ) {
                tmp.emplace_back(left, right);
                break;
            } else if (interval.second < left) {
                tmp.emplace_back(interval);
            } else {
                left = min(left, interval.first);
                right = max(right, interval.second);
            }
            ++i;
        }
        if (i == intervals_.size()) {
            tmp.emplace_back(left, right);
        }
        while (i < intervals_.size()) {
            tmp.emplace_back(intervals_[i++]);
        }
        swap(intervals_, tmp);
    }
    
    // Time:  O(logn)
    bool queryRange(int left, int right) {
        const auto it = lower_bound(intervals_.begin(), intervals_.end(), make_pair(left, right),
                                    [](const pair<int, int>& lhs,
                                       const pair<int, int>& rhs) {
                                           return less<int>{}(lhs.second, rhs.first);
                                    });
        return it != intervals_.end() && it->first <= left && it->second >= right;
    }

    // Time:  O(logn)
    bool queryRange2(int left, int right) {
        auto it = lower_bound(intervals_.begin(), intervals_.end(), make_pair(left, numeric_limits<int>::max()));
        if (it != intervals_.begin()) {
            it = prev(it);
        }
        return it != intervals_.end() && it->first <= left && it->second >= right;
    }
    
    // Time:  O(n)
    void removeRange(int left, int right) {
        vector<pair<int, int>> tmp;
        for (const auto& interval : intervals_) {
            if (interval.second <= left || interval.first >= right) {
                tmp.emplace_back(interval);
            } else {
                if (interval.first < left) {
                    tmp.emplace_back(interval.first, left);
                }
                if (right < interval.second) {
                    tmp.emplace_back(right, interval.second);
                }
            }
        }
        swap(intervals_, tmp);
    }
    
private:
    vector<pair<int, int>> intervals_;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
