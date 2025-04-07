// Time:  ctor:          O(1)
//        addPacket:     O(logn)
//        forwardPacket: O(logn)
//        getCount:      O(logn)
// Space: O(n)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// queue, ordered set
class Router {
public:
    Router(int memoryLimit) : size_(memoryLimit) {
    }

    bool addPacket(int src, int dest, int timestamp) {
        if (!lookup_[dest].insert({timestamp, src}).second) {
            return false;
        }
        if (size(q_) == size_){
            const auto [s, d, t] = q_.front(); q_.pop();
            lookup_[d].erase({t, s});
        }
        q_.emplace(src, dest, timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (empty(q_)) {
            return {};
        }
        const auto [s, d, t] = q_.front(); q_.pop();
        lookup_[d].erase({t, s});
        return {s, d, t};
    }

    int getCount(int dest, int startTime, int endTime) {
        return lookup_[dest].order_of_key({endTime + 1, 0}) -
               lookup_[dest].order_of_key({startTime, 0});
    }

private:
    using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
    queue<tuple<int, int, int>> q_;
    unordered_map<int, ordered_set> lookup_;
    int size_;
};
