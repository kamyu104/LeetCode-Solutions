// Time:  ctor:    O(1)
//        update:  O(logn)
//        current: O(1)
//        max:     O(1)
//        min:     O(1)
// Space: O(n)

class StockPrice {
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (timestamp > curr_) {
            curr_ = timestamp;
        }
        if (lookup_.count(timestamp)) {
            min_bst_.erase(min_bst_.find(lookup_[timestamp]));
        }
        lookup_[timestamp] = price;
        min_bst_.emplace(price);
    }
    
    int current() {
        return lookup_[curr_];
    }
    
    int maximum() {
        return *prev(cend(min_bst_));
    }
    
    int minimum() {
        return *cbegin(min_bst_);
    }

private:
    int curr_ = 0;
    unordered_map<int, int> lookup_;
    multiset<int> min_bst_;
};
