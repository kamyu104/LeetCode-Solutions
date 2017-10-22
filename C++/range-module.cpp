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
        for (const auto& range: ranges_) {
            if (range.first > right) {
                tmp.emplace_back(left, right);
                break;
            } else if (range.second < left) {
                tmp.emplace_back(range);
            } else {
                left = min(left, range.first);
                right = max(right, range.second);
            }
            ++i;
        }
        if (i == ranges_.size()) {
            tmp.emplace_back(left, right);
        }
        while (i < ranges_.size()) {
            tmp.emplace_back(ranges_[i++]);
        }
        swap(ranges_, tmp);
    }
    
    // Time:  O(logn)
    bool queryRange(int left, int right) {
        const auto it = lower_bound(ranges_.begin(), ranges_.end(), make_pair(left, right),
                                    [](const pair<int, int>& lhs,
                                       const pair<int, int>& rhs) {
                                           return less<int>{}(lhs.second, rhs.first);
                                    });
        return it != ranges_.end() && it->first <= left && it->second >= right;
    }
    
    // Time:  O(n)
    void removeRange(int left, int right) {
        int n = ranges_.size();
        vector<pair<int, int>> tmp;
        for (const auto& range : ranges_) {
            if (range.second <= left || range.first >= right) {
                tmp.emplace_back(range);
            } else {
                if (range.first < left) {
                    tmp.emplace_back(range.first, left);
                }
                if (range.second > right) {
                    tmp.emplace_back(right, range.second);
                }
            }
        }
        swap(ranges_, tmp);
    }
    
private:
    vector<pair<int, int>> ranges_;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
