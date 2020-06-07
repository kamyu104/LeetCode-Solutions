// Time:  ctor  : O(1)
//        visit : O(1)
//        back  : O(1)
//        foward: O(1)
// Space: O(n)

class BrowserHistory {
public:
    BrowserHistory(string homepage)
      : history_(1, homepage)
      , curr_{0} {
        
    }
    
    void visit(string url) {
        history_.resize(++curr_);
        history_.emplace_back(url);
    }
    
    string back(int steps) {
        curr_ = max(curr_ - steps, 0);
        return history_[curr_];
    }
    
    string forward(int steps) {
        curr_ = min(curr_ + steps, int(history_.size()) - 1);
        return history_[curr_];
    }

private:
    vector<string> history_;
    int curr_;
};
