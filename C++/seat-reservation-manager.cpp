// Time:  ctor:      O(n)
//        reserve:   O(logn)
//        unreserve: O(logn)
// Space: O(n)

class SeatManager {
public:
    SeatManager(int n) 
     : min_heap_(n) {
        iota(begin(min_heap_), end(min_heap_), 1);
        // make_heap(begin(min_heap_), end(min_heap_), greater<>());  // no need for sorted vector
    }
    
    int reserve() {
        int x = min_heap_.front();
        pop_heap(begin(min_heap_), end(min_heap_), greater<>()); min_heap_.pop_back();
        return x;
    }
    
    void unreserve(int seatNumber) {
        min_heap_.emplace_back(seatNumber); push_heap(begin(min_heap_), end(min_heap_), greater<>());
    }

private:
    vector<int> min_heap_;
};
