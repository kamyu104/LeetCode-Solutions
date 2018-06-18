// Time:  seat:  O(logn),
//        leave: O(logn)
// Space: O(n)

class ExamRoom {
public:
    ExamRoom(int N) : num_(N) {
        segment_iters_[make_pair(-1, num_)] = 
            max_bst_.emplace(make_shared<Segment>(num_, 0, -1, num_));
        seats_[-1] = make_pair(-1, num_);
        seats_[num_] = make_pair(-1, num_);
    }
    
    int seat() {
        const auto curr = *max_bst_.begin(); max_bst_.erase(max_bst_.begin());
        segment_iters_.erase(make_pair(curr->l, curr->r));
        if (curr->l == -1 && curr->r == num_) {
            segment_iters_[make_pair(curr->l + 1, curr->r)] = max_bst_.emplace(
                make_shared<Segment>(curr->r - 1,
                                     curr->r - 1,
                                     curr->l + 1, curr->r));
        } else if (curr->l == -1) {
            segment_iters_[make_pair(curr->l + 1, curr->r)] = max_bst_.emplace(
                make_shared<Segment>(curr->r / 2,
                                     curr->r / 2,
                                     curr->l + 1, curr->r));
        } else if (curr->r == num_) {
            segment_iters_[make_pair(curr->l, curr->r - 1)] = max_bst_.emplace(
                make_shared<Segment>((curr->r - 1 - curr->l) / 2,
                                     (curr->r - 1 - curr->l) / 2 + curr->l,
                                     curr->l, curr->r - 1)); 
        } else {
            segment_iters_[make_pair(curr->l, curr->pos)] = max_bst_.emplace(
                make_shared<Segment>((curr->pos - curr->l) / 2,
                                     (curr->pos - curr->l) / 2 + curr->l,
                                     curr->l, curr->pos));
            segment_iters_[make_pair(curr->pos, curr->r)] = max_bst_.emplace(
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
        const auto& left_segment = make_pair(neighbors.first, p);
        if (segment_iters_.count(left_segment)) {
            max_bst_.erase(segment_iters_[left_segment]); segment_iters_.erase(left_segment);
        }
        const auto& right_segment = make_pair(p, neighbors.second);
        if (segment_iters_.count(right_segment)) {
            max_bst_.erase(segment_iters_[right_segment]); segment_iters_.erase(right_segment);
        }
        
        if (neighbors.first == -1 && neighbors.second == num_) {
            segment_iters_[neighbors] = max_bst_.emplace(
                make_shared<Segment>(neighbors.second,
                                     neighbors.first + 1, 
                                     neighbors.first, neighbors.second));
        } else if (neighbors.first == -1) {
            segment_iters_[neighbors] = max_bst_.emplace(
                make_shared<Segment>(neighbors.second,
                                     neighbors.first + 1,
                                     neighbors.first, neighbors.second));
        } else if (neighbors.second == num_) {
            segment_iters_[neighbors] = max_bst_.emplace(
                make_shared<Segment>(neighbors.second - 1 - neighbors.first,
                                     neighbors.second - 1, 
                                     neighbors.first, neighbors.second));
        } else {
            segment_iters_[neighbors] = max_bst_.emplace(
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
                less<int>()(a->l, b->l) :
                greater<int>()(a->dis, b->dis);
        }
    };
    
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
    
    int num_;
    using S = shared_ptr<Segment>;
    multiset<S, Compare<S>> max_bst_;
    unordered_map<int, pair<int, int>> seats_;
    unordered_map<pair<int, int>, multiset<S, Compare<S>>::iterator, PairHash<int>> segment_iters_;
};

// Time:  seat:  O(logn) on average,
//        leave: O(logn)
// Space: O(n)
class ExamRoom2 {
public:
    ExamRoom2(int N) : num_(N) {
        max_bst_.emplace(make_shared<Segment>(num_, 0, -1, num_));
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
                make_shared<Segment>(curr->r - 1,
                                     curr->r - 1,
                                     curr->l + 1, curr->r));
        } else if (curr->l == -1) {
            max_bst_.emplace(
                make_shared<Segment>(curr->r / 2,
                                     curr->r / 2,
                                     curr->l + 1, curr->r));
        } else if (curr->r == num_) {
            max_bst_.emplace(
                make_shared<Segment>((curr->r - 1 - curr->l) / 2,
                                     (curr->r - 1 - curr->l) / 2 + curr->l,
                                     curr->l, curr->r - 1)); 
        } else {
            max_bst_.emplace(
                make_shared<Segment>((curr->pos - curr->l) / 2,
                                     (curr->pos - curr->l) / 2 + curr->l,
                                     curr->l, curr->pos));
            max_bst_.emplace(
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
            max_bst_.emplace(
                make_shared<Segment>(neighbors.second,
                                     neighbors.first + 1,
                                     neighbors.first, neighbors.second));
        } else if (neighbors.first == -1) {
            max_bst_.emplace(
                make_shared<Segment>(neighbors.second,
                                     neighbors.first + 1,
                                     neighbors.first, neighbors.second));
        } else if (neighbors.second == num_) {
            max_bst_.emplace(
                make_shared<Segment>(neighbors.second - 1 - neighbors.first,
                                     neighbors.second - 1,
                                     neighbors.first, neighbors.second));
        } else {
            max_bst_.emplace(
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
class ExamRoom3 {
public:
    ExamRoom3(int N) : num_(N) {
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
