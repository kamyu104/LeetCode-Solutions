// Time:  ctor:                   O(1)
//        addNumber:              O(logn)
//        removeFirstAddedNumber: O(logn)
//        getMean:                O(1)
//        getMedian:              O(1)
//        getMode:                O(1)
// Space: O(n)

// deque, freq table, bst
class StatisticsTracker {
public:
    StatisticsTracker() {
        
    }
    
    void addNumber(int number) {
        total_ += number;
        dq_.emplace_back(number);
        update(number, +1);
        if (empty(bst2_) || *begin(bst2_) <= number) {
            bst2_.emplace(number);
        } else {
            bst1_.emplace(number);
        }
        rebalance();
    }
    
    void removeFirstAddedNumber() {
        const int number = dq_.front(); dq_.pop_front();
        total_ -= number;
        update(number, -1);
        if (bst2_.count(number)) {
            bst2_.erase(bst2_.find(number));
        } else {
            bst1_.erase(bst1_.find(number));
        }
        rebalance();
    }
    
    int getMean() {
        return total_ / size(dq_);
    }
    
    int getMedian() {
        return *begin(bst2_);
    }
    
    int getMode() {
        return *begin(rbegin(freq_to_nums_)->second);
    }

private:
    void update(int number, int d) {
        if (num_to_freq_.count(number)) {
            freq_to_nums_[num_to_freq_[number]].erase(freq_to_nums_[num_to_freq_[number]].find(number));
            if (empty(freq_to_nums_[num_to_freq_[number]])) {
                freq_to_nums_.erase(num_to_freq_[number]);
            }
        }
        num_to_freq_[number] += d;
        if (!num_to_freq_[number]) {
            num_to_freq_.erase(number);
        } else {
            freq_to_nums_[num_to_freq_[number]].emplace(number);
        }
    }

    void rebalance() {
        if (size(bst2_)  == size(bst1_) + 2) {
            bst1_.emplace(*begin(bst2_));
            bst2_.erase(begin(bst2_));
        } else if (size(bst2_) + 1 == size(bst1_)) {
            bst2_.emplace(*prev(end(bst1_)));
            bst1_.erase(prev(end(bst1_)));
        }
    }

    int64_t total_ = 0;
    deque<int> dq_;
    unordered_map<int, int> num_to_freq_;
    map<int, multiset<int>> freq_to_nums_;
    multiset<int> bst1_, bst2_;
};
