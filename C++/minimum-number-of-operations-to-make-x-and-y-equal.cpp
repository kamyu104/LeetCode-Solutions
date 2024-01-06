// Time:  O(x)
// Space: O(x)

// memoization
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_map<int, int> lookup;
        const function<int (int)> memoization = [&](int x) {
            if (y >= x) {
                return y - x;
            }
            if (!lookup.count(x)) {
                lookup[x] = x - y;
                for (const auto& d : {5, 11}) {
                    lookup[x] = min(lookup[x], min(x % d, d - x % d) + memoization(x / d + (d - x % d < x % d ? 1 : 0)) + 1);
                }
            }
            return lookup[x];
        };

        return memoization(x);
    }
};

// Time:  O(x)
// Space: O(x)
// bfs
class Solution2 {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (y >= x) {
            return y - x;
        }
        const int upper_bound = x + (x - y);
        unordered_set<int> lookup = {x};
        vector<int> q = {x};
        for (int d = 0; !empty(q); ++d) {
            vector<int> new_q;
            for (const auto& x: q) {
                if (x == y) {
                    return d;
                }
                vector<int> candidates = {x + 1, x - 1};
                for (const auto& d : {5, 11}) {
                    if (x % d == 0) {
                        candidates.emplace_back(x / d);
                    }
                }
                for (const auto& new_x : candidates) {
                    if (!(0 <= new_x && new_x <= upper_bound && !lookup.count(new_x))) {
                        continue;
                    }
                    lookup.emplace(new_x);
                    new_q.emplace_back(new_x);
                }
            }
            q = move(new_q);
        }
        return -1;
    }
};
