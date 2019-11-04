// Time:  O(w * b * 2^b)
// Space: O(w * b * 2^b)

// if w = b, we can even apply Hungarian algorithm (see https://en.wikipedia.org/wiki/Hungarian_algorithm),
// it can be improved to O(w^3), see https://github.com/t3nsor/codebook/blob/master/bipartite-mincost.cpp
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<double>> dp(2,
                                  vector<double>(1 << bikes.size(),
                                                 numeric_limits<double>::infinity()));
        dp[0][0] = 0;
        for (int i = 0; i < workers.size(); ++i) {
            dp[(i + 1) % 2] = vector<double>(1 << bikes.size(),
                                             numeric_limits<double>::infinity());
            for (int j = 0; j < bikes.size(); ++j) {
                for (int taken = 0; taken < (1 << bikes.size()); ++taken) {
                    if (taken & (1 << j)) {
                        continue;
                    }
                    dp[(i + 1) % 2][taken | (1 << j)] =
                        min(dp[(i + 1) % 2][taken | (1 << j)],
                            dp[i % 2][taken] + manhattan(workers[i], bikes[j]));
                }
            }
        }
        return *min_element(dp[workers.size() % 2].cbegin(), dp[workers.size() % 2].cend());
    }

private:
    int manhattan(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};

// Time:  O((w * b * 2^b) * log(w * b * 2^b))
// Space: O(w * b * 2^b)
class Solution2 {
public:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        using P = vector<int>;
        priority_queue<P, vector<P>, greater<P>> min_heap;
        min_heap.push({0, 0, 0});
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        while (!min_heap.empty()) {
            const auto cost = min_heap.top()[0];
            const auto i = min_heap.top()[1];
            const auto taken = min_heap.top()[2];
            min_heap.pop();
            if (lookup.count(make_pair(i, taken))) {
                continue;
            }
            lookup.emplace(i, taken);
            if (i == workers.size()) {
                return cost;
            }
            for (int j = 0; j < bikes.size(); ++j) {
                if (taken & (1 << j)) {
                    continue;
                }
                min_heap.push({cost + +manhattan(workers[i], bikes[j]),  // O(b)
                               i + 1,  // O(w)
                               taken | (1 << j)});  // O(2^b)
            }
        }
        return -1;
    }

private:
    int manhattan(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
