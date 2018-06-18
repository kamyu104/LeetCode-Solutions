// Time:  seat:  O(logn),
//        leave: O(logn)
// Space: O(n)

class ExamRoom {
public:
    ExamRoom(int N) : num_(N) {
        max_heap.emplace(make_shared<Segment>(-1, num_, num_, 0));
        neighbors[-1] = make_pair(-1, num_);
        neighbors[num_] = make_pair(-1, num_);
    }
    
    int seat() {
        while (!neighbors.count(max_heap.top()->l) ||
               !neighbors.count(max_heap.top()->r) ||
               neighbors.count(max_heap.top()->pos)) {
            max_heap.pop();  // lazy deletion
        }
        const auto curr = max_heap.top(); max_heap.pop();
        if (curr->l == -1 && curr->r == num_) {
            max_heap.emplace(
                make_shared<Segment>(curr->l + 1, curr->r,
                                     curr->r - 1,
                                     curr->r - 1));
            neighbors[curr->l + 1] = make_pair(curr->l, curr->r);
        } else if (curr->l == -1) {
            max_heap.emplace(
                make_shared<Segment>(curr->l + 1, curr->r,
                                     curr->r / 2,
                                     curr->r / 2));
            neighbors[curr->l + 1] = make_pair(curr->l, curr->r);
            neighbors[curr->r].first = curr->l + 1;
        } else if (curr->r == num_) {
            max_heap.emplace(
                make_shared<Segment>(curr->l, curr->r - 1,
                                     (curr->r - 1 - curr->l) / 2,
                                     (curr->r - 1 - curr->l) / 2 + curr->l)); 
            neighbors[curr->r - 1] = make_pair(curr->l, curr->r);
            neighbors[curr->l].second = curr->r - 1;
        } else {
            max_heap.emplace(
                make_shared<Segment>(curr->l, curr->pos,
                                     (curr->pos - curr->l) / 2,
                                     (curr->pos - curr->l) / 2 + curr->l));
            max_heap.emplace(
                make_shared<Segment>(curr->pos, curr->r,
                                     (curr->r - curr->pos) / 2,
                                     (curr->r - curr->pos) / 2 + curr->pos));
            neighbors[curr->pos] = make_pair(curr->l, curr->r);
            neighbors[curr->l].second = curr->pos;
            neighbors[curr->r].first = curr->pos;
        }
        return curr->pos;
    }
    
    void leave(int p) {
        const auto nei = neighbors[p];
        neighbors.erase(p);
        if (nei.first == -1 && nei.second == num_) {
            max_heap.emplace(
                make_shared<Segment>(nei.first, nei.second,
                                    nei.second,
                                    nei.first + 1));  
        } else if (nei.first == -1) {
            max_heap.emplace(
                make_shared<Segment>(nei.first, nei.second,
                                     nei.second,
                                     nei.first + 1));
            neighbors[nei.second].first = -1;
        } else if (nei.second == num_) {
            max_heap.emplace(
                make_shared<Segment>(nei.first, nei.second,
                                     nei.second - 1 - nei.first,
                                     nei.second - 1));
            neighbors[nei.first].second = nei.second;
        } else {
            max_heap.emplace(
                make_shared<Segment>(nei.first, nei.second,
                                     (nei.second - nei.first) / 2,
                                     (nei.second - nei.first) / 2 + nei.first));   
            neighbors[nei.first].second = nei.second;
            neighbors[nei.second].first = nei.first;
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
    unordered_map<int, pair<int, int>> neighbors;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
