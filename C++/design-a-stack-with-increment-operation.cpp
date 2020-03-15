// Time:  cotr:      O(1)
//        push:      O(1)
//        pop:       O(1)
//        increment: O(1)
// Space: O(n)

class CustomStack {
public:
    CustomStack(int maxSize)
      : max_size_(maxSize) {
        
    }
    
    void push(int x) {
        if (stk_.size() == max_size_) {
            return;
        }
        stk_.emplace_back(x, 0);
    }
    
    int pop() {
        if (stk_.empty()) {
            return -1;
        }
        const auto[x, inc] = stk_.back(); stk_.pop_back();
        if (!stk_.empty()) {
            stk_.back().second += inc;
        }
        return x + inc;
    }
    
    void increment(int k, int val) {
        const auto& i = min(int(stk_.size()), k) - 1;
        if (i >= 0) {
            stk_[i].second += val;
        }
    }

private:
    const int max_size_;
    vector<pair<int, int>> stk_;
};
