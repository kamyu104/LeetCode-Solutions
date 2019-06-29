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
        
        int distance(const pair<int, int>& segment) const {
            return segment.first == -1 || segment.second == num_
                   ? segment.second - segment.first - 1
                   : (segment.second - segment.first) / 2;
        }

    private:
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
        
        int distance(const pair<int, int>& segment) const {
            return segment.first == -1 || segment.second == num_
                   ? segment.second - segment.first - 1
                   : (segment.second - segment.first) / 2;
        }

    private:
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
    ExamRoom3(int N) : num_(N) {
        seats_[-1] = {-1, num_};
        seats_[num_] = {-1, num_};
        max_heap_.emplace(make_shared<Segment>(num_, 0, -1, num_));
    }
    
    int seat() {
        while (!seats_.count(max_heap_.top()->l) ||
               !seats_.count(max_heap_.top()->r) ||
               seats_[max_heap_.top()->l].second != max_heap_.top()->r ||
               seats_[max_heap_.top()->r].first != max_heap_.top()->l) {
            max_heap_.pop();  // lazy deletion
        }
        
        const auto curr = max_heap_.top(); max_heap_.pop();
        if (curr->l == -1 && curr->r == num_) {
            max_heap_.emplace(
                make_shared<Segment>(curr->r - 1,
                                     curr->r - 1,
                                     curr->l + 1, curr->r));
        } else if (curr->l == -1) {
            max_heap_.emplace(
                make_shared<Segment>(curr->r / 2,
                                     curr->r / 2,
                                     curr->l + 1, curr->r));
        } else if (curr->r == num_) {
            max_heap_.emplace(
                make_shared<Segment>((curr->r - 1 - curr->l) / 2,
                                     (curr->r - 1 - curr->l) / 2 + curr->l,
                                     curr->l, curr->r - 1)); 
        } else {
            max_heap_.emplace(
                make_shared<Segment>((curr->mid - curr->l) / 2,
                                     (curr->mid - curr->l) / 2 + curr->l,
                                     curr->l, curr->mid));
            max_heap_.emplace(
                make_shared<Segment>((curr->r - curr->mid) / 2,
                                     (curr->r - curr->mid) / 2 + curr->mid,
                                     curr->mid, curr->r));
        }
        seats_[curr->mid] = {curr->l, curr->r};
        seats_[curr->l].second = curr->mid;
        seats_[curr->r].first = curr->mid;
        return curr->mid;
    }
    
    void leave(int p) {
        const auto neighbors = seats_[p];
        seats_.erase(p);
        if (neighbors.first == -1 && neighbors.second == num_) {
            max_heap_.emplace(
                make_shared<Segment>(neighbors.second,
                                     neighbors.first + 1,
                                     neighbors.first, neighbors.second));
        } else if (neighbors.first == -1) {
            max_heap_.emplace(
                make_shared<Segment>(neighbors.second,
                                     neighbors.first + 1,
                                     neighbors.first, neighbors.second));
        } else if (neighbors.second == num_) {
            max_heap_.emplace(
                make_shared<Segment>(neighbors.second - 1 - neighbors.first,
                                     neighbors.second - 1,
                                     neighbors.first, neighbors.second));
        } else {
            max_heap_.emplace(
                make_shared<Segment>((neighbors.second - neighbors.first) / 2,
                                     (neighbors.second - neighbors.first) / 2 + neighbors.first,
                                     neighbors.first, neighbors.second));
        }
        seats_[neighbors.first].second = neighbors.second;
        seats_[neighbors.second].first = neighbors.first;
    }
    
private:
    struct Segment {
        int dis;
        int mid;
        int l;
        int r;
        Segment(int dis, int mid, int l, int r) : 
            dis(dis), mid(mid), l(l), r(r) {
        }
    };
    
    template <typename T>
    struct Compare {
        bool operator()(const T& a, const T& b) {
            return a->dis == b->dis ?
                greater<int>()(a->l, b->l) :
                less<int>()(a->dis, b->dis);
        }
    };
    
    int num_;
    using S = shared_ptr<Segment>;
    priority_queue<S, vector<S>, Compare<S>> max_heap_;
    unordered_map<int, pair<int, int>> seats_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
