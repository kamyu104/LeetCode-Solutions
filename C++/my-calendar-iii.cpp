// Time:  O(nlogn) ~ O(n^2)
// Space: O(n)

class MyCalendarThree {
public:
    MyCalendarThree() {
        events_.emplace(-1, 0);
    }
    
    int book(int start, int end) {
        auto sit = events_.emplace(start, prev(events_.upper_bound(start))->second).first;
        auto eit = events_.emplace(end, prev(events_.upper_bound(end))->second).first;
        for (; sit != eit; ++sit) {
            count_ = max(count_, ++(sit->second));
        }
        return count_;
    }
    
private:
    map<int, int> events_;
    int count_ = 0;
};

// Time:  O(n^2)
// Space: O(n)
class MyCalendarThree2 {
public:
    MyCalendarThree2() {
        
    }
    
    int book(int start, int end) {
        ++books_[start];
        --books_[end];
        int result = 0;
        int cnt = 0;
        for (const auto &book : books_) {
            cnt += book.second;
            result = max(result, cnt);
        }
        return result;
    }

private:
    map<int, int> books_;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
