// Time:  seat:  O(logn),
//        leave: O(logn)
// Space: O(n)

// bst solution, inspired by zqzwxec
class ExamRoom {
public:
    ExamRoom(int N)
      : num_(N)
      , max_bst_(Compare(N))
    {
        seats_.emplace(-1);
        seats_.emplace(num_);
        max_bst_.emplace(-1, num_);
    }
    
    int seat() {
        const auto top = *max_bst_.cbegin();
        max_bst_.erase(top);
        const auto& mid = top.first == -1 ? 0
                          : top.second == num_ ? num_ - 1
                          : (top.first + top.second) / 2;
        seats_.emplace(mid);
        max_bst_.emplace(top.first, mid);
        max_bst_.emplace(mid, top.second);
        return mid;
    }
    
    void leave(int p) {
        const auto& it = seats_.find(p);
        const auto& left = *prev(it), &right = *next(it);
        max_bst_.erase({left, p});
        max_bst_.erase({p, right});
        seats_.erase(p);
        max_bst_.emplace(left, right);
    }

private:
    class Compare {
    public:
        Compare(int N) : num_(N) {}

        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            const auto& dist_a = distance(a), &dist_b = distance(b);
            return dist_a == dist_b ? less<int>()(a.first, b.first)
                   : greater<int>()(dist_a, dist_b);
        }
    
    private:
        int distance(const pair<int, int>& segment) const {
            return segment.first == -1 || segment.second == num_
                   ? segment.second - segment.first - 1
                   : (segment.second - segment.first) / 2;
        }

        int num_;
    };
    
    int num_;
    set<pair<int, int>, Compare> max_bst_;
    set<int> seats_;
};

// Time:  seat:  O(logn),
//        leave: O(logn)
// Space: O(n)
// bst solution, inspired by zqzwxec
class ExamRoom2 {
public:
    ExamRoom2(int N)
      : num_(N)
      , max_bst_(Compare(N))
    {
        seats_[-1] = {-1, num_};
        seats_[num_] = {-1, num_};
        max_bst_.emplace(-1, num_);
    }
    
    int seat() {
        const auto top = *max_bst_.cbegin();
        max_bst_.erase(top);
        const auto& mid = top.first == -1 ? 0
                          : top.second == num_ ? num_ - 1
                          : (top.first + top.second) / 2;
        seats_[mid] = top;
        seats_[top.first].second = mid;
        seats_[top.second].first = mid;
        max_bst_.emplace(top.first, mid);
        max_bst_.emplace(mid, top.second);
        return mid;
    }
    
    void leave(int p) {
        const auto left = seats_[p].first, right = seats_[p].second;
        max_bst_.erase({left, p});
        max_bst_.erase({p, right});
        seats_.erase(p);
        seats_[left].second = right;
        seats_[right].first = left;
        max_bst_.emplace(left, right);
    }

private:
    class Compare {
    public:
        Compare(int N) : num_(N) {}

        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            const auto& dist_a = distance(a), &dist_b = distance(b);
            return dist_a == dist_b ? less<int>()(a.first, b.first)
                   : greater<int>()(dist_a, dist_b);
        }
    
    private:
        int distance(const pair<int, int>& segment) const {
            return segment.first == -1 || segment.second == num_
                   ? segment.second - segment.first - 1
                   : (segment.second - segment.first) / 2;
        }

        int num_;
    };
    
    int num_;
    set<pair<int, int>, Compare> max_bst_;
    unordered_map<int, pair<int, int>> seats_;
};

// Time:  seat:  O(logn) on average,
//        leave: O(logn)
// Space: O(n)
// heap solution
class ExamRoom3 {
public:
    ExamRoom3(int N)
      : num_(N)
      , max_heap_(Compare(N))
     {
        seats_[-1] = {-1, num_};
        seats_[num_] = {-1, num_};
        max_heap_.emplace(-1, num_);
    }
    
    int seat() {
        while (!seats_.count(max_heap_.top().first) ||
               !seats_.count(max_heap_.top().second) ||
               seats_[max_heap_.top().first].second != max_heap_.top().second ||
               seats_[max_heap_.top().second].first != max_heap_.top().first) {
            max_heap_.pop();  // lazy deletion
        }
        
        const auto top = max_heap_.top(); max_heap_.pop();
        const auto& mid = top.first == -1 ? 0
                          : top.second == num_ ? num_ - 1
                          : (top.first + top.second) / 2;
        seats_[mid] = top;
        seats_[top.first].second = mid;
        seats_[top.second].first = mid;
        max_heap_.emplace(top.first, mid);
        max_heap_.emplace(mid, top.second);
        return mid;
    }
    
    void leave(int p) {
        const auto left = seats_[p].first, right = seats_[p].second;
        seats_.erase(p);
        seats_[left].second = right;
        seats_[right].first = left;
        max_heap_.emplace(left, right);
    }
    
private:
    class Compare {
    public:
        Compare(int N) : num_(N) {}

        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            const auto& dist_a = distance(a), &dist_b = distance(b);
            return dist_a == dist_b ? greater<int>()(a.first, b.first)
                   : less<int>()(dist_a, dist_b);
        }
    
    private:
        int distance(const pair<int, int>& segment) const {
            return segment.first == -1 || segment.second == num_
                   ? segment.second - segment.first - 1
                   : (segment.second - segment.first) / 2;
        }

        int num_;
    };
    
    int num_;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> max_heap_;
    unordered_map<int, pair<int, int>> seats_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
