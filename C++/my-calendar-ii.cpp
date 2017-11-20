// Time:  O(n^2)
// Space: O(n)

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& p : overlaps_) {
            if (start < p.second && end > p.first) {
                return false;
            }
        }
        for (const auto& p : calendar_) {
            if (start < p.second && end > p.first) {
                overlaps_.emplace_back(max(start, p.first), min(end, p.second));
            }
        }
        calendar_.emplace_back(start, end);
        return true;
    }

private:
    vector<pair<int, int>> overlaps_;
    vector<pair<int, int>> calendar_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
