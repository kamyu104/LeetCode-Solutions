// Time:  seat:  O(logn),
//        leave: O(logn)
// Space: O(n)

class ExamRoom {
public:
    ExamRoom(int N) : num_(N) {
        max_heap.emplace(make_shared<Segment>(-1, num_, num_, 0));
        seats[-1] = make_pair(-1, num_);
        seats[num_] = make_pair(-1, num_);
    }
    
    int seat() {
        while (!seats.count(max_heap.top()->l) ||
               !seats.count(max_heap.top()->r) ||
               seats.count(max_heap.top()->pos)) {
            max_heap.pop();  // lazy deletion
        }
        const auto curr = max_heap.top(); max_heap.pop();
        if (curr->l == -1 && curr->r == num_) {
            max_heap.emplace(
                make_shared<Segment>(curr->l + 1, curr->r,
                                     curr->r - 1,
                                     curr->r - 1));
            seats[curr->l + 1] = make_pair(curr->l, curr->r);
        } else if (curr->l == -1) {
            max_heap.emplace(
                make_shared<Segment>(curr->l + 1, curr->r,
                                     curr->r / 2,
                                     curr->r / 2));
            seats[curr->l + 1] = make_pair(curr->l, curr->r);
            seats[curr->r].first = curr->l + 1;
        } else if (curr->r == num_) {
            max_heap.emplace(
                make_shared<Segment>(curr->l, curr->r - 1,
                                     (curr->r - 1 - curr->l) / 2,
                                     (curr->r - 1 - curr->l) / 2 + curr->l)); 
            seats[curr->r - 1] = make_pair(curr->l, curr->r);
            seats[curr->l].second = curr->r - 1;
        } else {
            max_heap.emplace(
                make_shared<Segment>(curr->l, curr->pos,
                                     (curr->pos - curr->l) / 2,
                                     (curr->pos - curr->l) / 2 + curr->l));
            max_heap.emplace(
                make_shared<Segment>(curr->pos, curr->r,
                                     (curr->r - curr->pos) / 2,
                                     (curr->r - curr->pos) / 2 + curr->pos));
            seats[curr->pos] = make_pair(curr->l, curr->r);
            seats[curr->l].second = curr->pos;
            seats[curr->r].first = curr->pos;
        }
        return curr->pos;
    }
    
    void leave(int p) {
        const auto neighbors = seats[p];
        seats.erase(p);
        if (neighbors.first == -1 && neighbors.second == num_) {
            max_heap.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     neighbors.second,
                                     neighbors.first + 1));
        } else if (neighbors.first == -1) {
            max_heap.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     neighbors.second,
                                     neighbors.first + 1));
            seats[neighbors.second].first = -1;
        } else if (neighbors.second == num_) {
            max_heap.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     neighbors.second - 1 - neighbors.first,
                                     neighbors.second - 1));
            seats[neighbors.first].second = neighbors.second;
        } else {
            max_heap.emplace(
                make_shared<Segment>(neighbors.first, neighbors.second,
                                     (neighbors.second - neighbors.first) / 2,
                                     (neighbors.second - neighbors.first) / 2 + neighbors.first));
            seats[neighbors.first].second = neighbors.second;
            seats[neighbors.second].first = neighbors.first;
        }
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
    priority_queue<S, vector<S>, Compare<S>> max_heap;
    unordered_map<int, pair<int, int>> seats;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
