// Time:  ctor:     O(1)
//        allocate: O(logn)
//        free:     O(logn)
// Space: O(n)

// bst
class Allocator {
public:
    Allocator(int n) : avails_{{0, n}} {
    }
    
    int allocate(int size, int mID) {
        for (const auto [l, s] : avails_) {
            if (s < size) {
                continue;
            }
            avails_.erase(l);
            lookup_[mID].emplace_back(l, size);
            if (s - size > 0) {
                avails_.emplace(l + size, s - size);
            }
            return l;
        }
        return -1;
    }
    
    int free(int mID) {
        if (!lookup_.count(mID)) {
            return 0;
        }
        int result = 0;
        for (const auto& [l, s] : lookup_[mID]) {
            auto it = avails_.emplace(l, s).first;
            if (next(it) != end(avails_) && it->first + it->second == next(it)->first) {
                it->second += next(it)->second;
                avails_.erase(next(it));
            }
            if (it != begin(avails_) && prev(it)->first + prev(it)->second == it->first) {
                prev(it)->second += it->second;
                avails_.erase(it);
            }
            result += s;
        }
        lookup_.erase(mID);
        return result;
    }

private:
    map<int, int> avails_;
    unordered_map<int, vector<pair<int, int>>> lookup_;
};
