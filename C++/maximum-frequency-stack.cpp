// Time:  O(1)
// Space: O(n)

class FreqStack {
public:
    FreqStack() 
        : max_freq_(0) {
        
    }
    
    void push(int x) {
        ++freq_[x];
        if (freq_[x] > max_freq_) {
            max_freq_ = freq_[x];
        }
        group_[freq_[x]].emplace_back(x);
    }
    
    int pop() {
        auto x = group_[max_freq_].back(); group_[max_freq_].pop_back();
        if (group_[max_freq_].empty()) {
            group_.erase(max_freq_);
            --max_freq_;
        }
        --freq_[x];
        if (freq_[x] == 0) {
            freq_.erase(x);
        }
        return x;
    }

private:
    unordered_map<int, int> freq_;
    unordered_map<int, vector<int>> group_;
    int max_freq_;
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
