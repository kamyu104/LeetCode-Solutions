// Time:  push: O(logn)
//        pop:  O(1), amortized
//        popAtStack: O(logn)
// Space: O(n * c)

class DinnerPlates {
public:
    DinnerPlates(int capacity) : c_(capacity) {
    }
    
    void push(int val) {
        if (!min_heap_.empty()) {
            const auto l = min_heap_.top(); min_heap_.pop();
            if (l < stks_.size()) {
                stks_[l].emplace_back(val);
                return;
            }
            min_heap_ = {};  // nothing is valid in min heap
        }
        if (stks_.empty() || stks_.back().size() == c_) {
            stks_.emplace_back();
        }
        stks_.back().emplace_back(val);
    }
    
    int pop() {
        while (!stks_.empty() && stks_.back().empty()) {
            stks_.pop_back();
        }
        if (stks_.empty()) {
            return -1;
        }
        auto result = stks_.back().back(); stks_.back().pop_back();
        return result;
    }
    
    int popAtStack(int index) {
        if (index >= stks_.size() || stks_[index].empty()) {
            return -1;
        }
        min_heap_.emplace(index);
        auto result = stks_[index].back(); stks_[index].pop_back();
        return result;
    }

private:
    vector<vector<int>> stks_;
    int c_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;
};
