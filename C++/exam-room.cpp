// Time:  seat:  O(logn) on average,
//        leave: O(logn)
// Space: O(n)

class ExamRoom {
public:
    ExamRoom(int N) : num_(N) {
        max_bst_.emplace(make_shared<Segment>(-1, num_, num_, 0));
        seats_[-1] = make_pair(-1, num_);
        seats_[num_] = make_pair(-1, num_);
    }
    
    int seat() {
        while (!seats_.count((*max_bst_.cbegin())->l) ||
               !seats_.count((*max_bst_.cbegin())->r) ||
               seats_[(*max_bst_.cbegin())->l].second != (*max_bst_.cbegin())->r ||
               seats_[(*max_bst_.cbegin())->r].first != (*max_bst_.cbegin())->l) {
            max_bst_.erase(max_bst_.begin());  // lazy deletion
        }
        
        const auto curr = *max_bst_.begin(); max_bst_.erase(max_bst_.begin());
        if (curr->l == -1 && curr->r == num_) {
            max_bst_.emplace(
                make_shared<Segment>(curr->l + 1, curr->r,
                                     curr->r - 1,
                                     curr->r - 1));
            seats_[curr->l + 1] = make_pair(curr->l, curr->r);
        } else if (curr->l == -1) {
            max_bst_.emplace(
                make_shared<Segment>(curr->l + 1, curr->r,
                                     curr->r / 2,
                                     curr->r / 2));
            seats_[curr->l + 1] = make_pair(curr->l, curr->r);
        } else if (curr->r == num_) {
            max_bst_.emplace(
                make_shared<Segment>(curr->l, curr->r - 1,
                                     (curr->r - 1 - curr->l) / 2,
                                     (curr->r - 1 - curr->l) / 2 + curr->l)); 
            seats_[curr->r - 1] = make_pair(curr->l, curr->r);
        } else {
            max_bst_.emplace(
                make_shared<Segment>(curr->l, curr->pos,
                                     (curr->pos - curr->l) / 2,
                                     (curr->pos - curr->l) / 2 + curr->l));
            max_bst_.emplace(
                make_shared<Segment>(curr->pos, curr->r,
                                     (curr->r - curr->pos) / 2,
                                     (curr->r - curr->pos) / 2 + curr->pos));
            seats_[curr->pos] = make_pair(curr->l, curr->r);
        }
        seats_[curr->l].second = curr->pos;
        seats_[curr->r].first = curr->pos;
        return curr->pos;
    }
    
    void leave(int p) {
        const auto neighbors = seats_[p];
        seats_.erase(p);
        if (neighbors.first == -1 && neighbors.second == num_) {
            max_bst_.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     neighbors.second,
                                     neighbors.first + 1));
        } else if (neighbors.first == -1) {
            max_bst_.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     neighbors.second,
                                     neighbors.first + 1));
        } else if (neighbors.second == num_) {
            max_bst_.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     neighbors.second - 1 - neighbors.first,
                                     neighbors.second - 1));
        } else {
            max_bst_.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     (neighbors.second - neighbors.first) / 2,
                                     (neighbors.second - neighbors.first) / 2 + neighbors.first));
        }
        seats_[neighbors.first].second = neighbors.second;
        seats_[neighbors.second].first = neighbors.first;
    }
    
private:
    struct Segment {
        int l;
        int r;
        int dis;
        int pos;
        Segment(int l, int r, int dis, int pos) : 
            l(l), r(r), dis(dis), pos(pos) {
        }
    };
    
    template <typename T>
    struct Compare {
        bool operator()(const T& a, const T& b) {
            return a->dis == b->dis ?
                less<int>()(a->l, b->l) :
                greater<int>()(a->dis, b->dis);
        }
    };
    
    int num_;
    using S = shared_ptr<Segment>;
    multiset<S, Compare<S>> max_bst_;
    unordered_map<int, pair<int, int>> seats_;
};

// Time:  seat:  O(logn) on average,
//        leave: O(logn)
// Space: O(n)
class ExamRoom2 {
public:
    ExamRoom(int N) : num_(N) {
        max_heap_.emplace(make_shared<Segment>(-1, num_, num_, 0));
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
                make_shared<Segment>(curr->l + 1, curr->r,
                                     curr->r - 1,
                                     curr->r - 1));
            seats_[curr->l + 1] = make_pair(curr->l, curr->r);
        } else if (curr->l == -1) {
            max_heap_.emplace(
                make_shared<Segment>(curr->l + 1, curr->r,
                                     curr->r / 2,
                                     curr->r / 2));
            seats_[curr->l + 1] = make_pair(curr->l, curr->r);
        } else if (curr->r == num_) {
            max_heap_.emplace(
                make_shared<Segment>(curr->l, curr->r - 1,
                                     (curr->r - 1 - curr->l) / 2,
                                     (curr->r - 1 - curr->l) / 2 + curr->l)); 
            seats_[curr->r - 1] = make_pair(curr->l, curr->r);
        } else {
            max_heap_.emplace(
                make_shared<Segment>(curr->l, curr->pos,
                                     (curr->pos - curr->l) / 2,
                                     (curr->pos - curr->l) / 2 + curr->l));
            max_heap_.emplace(
                make_shared<Segment>(curr->pos, curr->r,
                                     (curr->r - curr->pos) / 2,
                                     (curr->r - curr->pos) / 2 + curr->pos));
            seats_[curr->pos] = make_pair(curr->l, curr->r);
        }
        seats_[curr->l].second = curr->pos;
        seats_[curr->r].first = curr->pos;
        return curr->pos;
    }
    
    void leave(int p) {
        const auto neighbors = seats_[p];
        seats_.erase(p);
        if (neighbors.first == -1 && neighbors.second == num_) {
            max_heap_.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     neighbors.second,
                                     neighbors.first + 1));
        } else if (neighbors.first == -1) {
            max_heap_.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     neighbors.second,
                                     neighbors.first + 1));
        } else if (neighbors.second == num_) {
            max_heap_.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     neighbors.second - 1 - neighbors.first,
                                     neighbors.second - 1));
        } else {
            max_heap_.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     (neighbors.second - neighbors.first) / 2,
                                     (neighbors.second - neighbors.first) / 2 + neighbors.first));
        }
        seats_[neighbors.first].second = neighbors.second;
        seats_[neighbors.second].first = neighbors.first;
    }
    
private:
    struct Segment {
        int l;
        int r;
        int dis;
        int pos;
        Segment(int l, int r, int dis, int pos) : 
            l(l), r(r), dis(dis), pos(pos) {
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
