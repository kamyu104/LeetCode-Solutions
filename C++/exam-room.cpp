// Time:  seat:  O(logn),
//        leave: O(logn)
// Space: O(n)

// bst solution, inspired by zqzwxec
class ExamRoom {
public:
    ExamRoom(int N)
      : N_(N)
      , max_bst_(Compare(N))
    {
        seats_.emplace(-1);
        seats_.emplace(N_);
        max_bst_.emplace(-1, N_);
    }
    
    int seat() {
        const auto top = *max_bst_.cbegin();
        max_bst_.erase(top);
        const auto mid = top.first == -1 ? 0
                         : top.second == N_ ? N_ - 1
                         : (top.first + top.second) / 2;
        seats_.emplace(mid);
        max_bst_.emplace(top.first, mid);
        max_bst_.emplace(mid, top.second);
        return mid;
    }
    
    void leave(int mid) {
        const auto left = *prev(seats_.lower_bound(mid));
        const auto right = *seats_.upper_bound(mid);
        max_bst_.erase({left, mid});
        max_bst_.erase({mid, right});
        seats_.erase(mid);
        max_bst_.emplace(left, right);
    }

private:
    class Compare {
    public:
        Compare(int i) : N_(i) {}

        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            return distance(a) == distance(b) ? less<int>()(a.first, b.first)
                   : greater<int>()(distance(a), distance(b));
        }
        
        int distance(const pair<int,int>& a) const {
            if (a.first == -1 || a.second == N_) {
                return a.second - a.first - 1;
            }
            return (a.second - a.first) / 2;
        }

    private:
        int N_;
    };
    
    int N_;
    set<pair<int,int>, Compare> max_bst_;
    set<int> seats_;
};

// Time:  seat:  O(logn) on average,
//        leave: O(logn)
// Space: O(n)
// heap solution
class ExamRoom2 {
public:
    ExamRoom2(int N) : num_(N) {
        max_heap_.emplace(make_shared<Segment>(num_, 0, -1, num_));
        seats_[-1] = make_pair(-1, num_);
        seats_[num_] = make_pair(-1, num_);
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
                make_shared<Segment>((curr->pos - curr->l) / 2,
                                     (curr->pos - curr->l) / 2 + curr->l,
                                     curr->l, curr->pos));
            max_heap_.emplace(
                make_shared<Segment>((curr->r - curr->pos) / 2,
                                     (curr->r - curr->pos) / 2 + curr->pos,
                                     curr->pos, curr->r));
        }
        seats_[curr->pos] = make_pair(curr->l, curr->r);
        seats_[curr->l].second = curr->pos;
        seats_[curr->r].first = curr->pos;
        return curr->pos;
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
        int pos;
        int l;
        int r;
        Segment(int dis, int pos, int l, int r) : 
            dis(dis), pos(pos), l(l), r(r) {
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
