// Time:  ctor:           O(n)
//        updatePriority: O(logn), amortized
//        pollHightest:   O(logn), amortized
// Space: O(n)

// heap, hash table
class EventManager {
public:
    EventManager(vector<vector<int>>& events) {
        vector<pair<int, int>> pairs;
        for (const auto& e : events) {
            lookup_[e[0]] = e[1];
            pairs.emplace_back(e[1], -e[0]);
        }
        priority_queue<pair<int, int>> tmp(cbegin(pairs), cend(pairs));
        max_heap_.swap(tmp);
    }
    
    void updatePriority(int eventId, int newPriority) {
        lookup_[eventId] = newPriority;
        max_heap_.emplace(newPriority, -eventId);
        if (size(max_heap_) > 2 * size(lookup_)) {
            rebuild();
        }
    }
    
    int pollHighest() {
        for (; !empty(max_heap_); max_heap_.pop()) {
            const auto [p, i] = max_heap_.top();
            if (lookup_.count(-i) && lookup_[-i] == p) {
                lookup_.erase(-i);
                return -i;
            }
        }
        return -1;
    }

private:
    void rebuild() {
         unordered_map<int, int> lookup;
         priority_queue<pair<int, int>> max_heap;
         for (; !empty(max_heap_); max_heap_.pop()) {
            const auto [p, i] = max_heap_.top();
            if (lookup_.count(-i) && lookup_[-i] == p) {
                lookup_.erase(-i);
                lookup[-i] = p;
                max_heap.emplace(p, i);
            }
        }
        lookup_.swap(lookup);
        max_heap_.swap(max_heap);
    }

    unordered_map<int, int> lookup_;
    priority_queue<pair<int, int>> max_heap_;
};

// Time:  ctor:           O(nlogn)
//        updatePriority: O(logn)
//        pollHightest:   O(logn)
// Space: O(n)
// bst, hash table
class EventManager2 {
public:
    EventManager2(vector<vector<int>>& events) {
        for (const auto& e : events) {
            lookup_[e[0]] = e[1];
            bst_.emplace(e[1], -e[0]);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        bst_.erase(pair(lookup_[eventId], -eventId));
        lookup_[eventId] = newPriority;
        bst_.emplace(newPriority, -eventId);
    }
    
    int pollHighest() {
        if (empty(bst_)) {
            return -1;
        }
        auto it = prev(cend(bst_));
        const int result = -it->second;
        bst_.erase(it);
        lookup_.erase(result);
        return result;
    }

private:
    unordered_map<int, int> lookup_;
    set<pair<int, int>> bst_;
};
