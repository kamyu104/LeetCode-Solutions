// Time:  O(n^2)
// Space: O(n)

class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++books_[start];
        --books_[end];
        int result = 0;
        int cnt = 0;
        for (auto &book : books_) {
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
