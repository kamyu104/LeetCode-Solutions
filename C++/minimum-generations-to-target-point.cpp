// Time:  O(7^6)
// Space: O(7^3)

// bfs
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        const auto& encode = [](const auto& p) {
            return p[0] * 7 * 7 + p[1] * 7 + p[2];
        };

        vector<bool> lookup(7 * 7 * 7);
        int k = 0, total = 0;
        for (const auto& p : points) {
            if (lookup[encode(p)]) {
                continue;
            }
            if (p == target) {
                return k;
            }
            lookup[encode(p)] = true;
        }
        for (int i = 0; i < size(points); ++i) {
            if (i == total) {
                total = size(points);
                ++k;
            }
            for (int j = 0; j < i; ++j) {
                const auto& p = vector<int>{(points[i][0] + points[j][0]) / 2, (points[i][1] + points[j][1]) / 2, (points[i][2] + points[j][2]) / 2};
                if (lookup[encode(p)]) {
                    continue;
                }
                if (p == target) {
                    return k;
                }
                lookup[encode(p)] = true;
                points.emplace_back(p);
            }
        }
        return -1;
    }
};

// Time:  O(7^6)
// Space: O(7^3)
// bfs
class Solution2 {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        const auto& encode = [](const auto& p) {
            return p[0] * 7 * 7 + p[1] * 7 + p[2];
        };

        vector<bool> lookup(7 * 7 * 7);
        for (const auto& p : points) {
            if (lookup[encode(p)]) {
                continue;
            }
            lookup[encode(p)] = true;
        }
        for (int i = 0, k = 0; i < size(points); ++k) {
            if (lookup[encode(target)]) {
                return k;
            }
            const auto& total = size(points);
            for (; i < total; ++i) {
                for (int j = 0; j < i; ++j) {
                    const auto& p = vector<int>{(points[i][0] + points[j][0]) / 2, (points[i][1] + points[j][1]) / 2, (points[i][2] + points[j][2]) / 2};
                    if (lookup[encode(p)]) {
                        continue;
                    }
                    lookup[encode(p)] = true;
                    points.emplace_back(p);
                }
            }
        }
        return -1;
    }
};

// Time:  O(7^6)
// Space: O(7^3)
// bfs
class Solution3 {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        const auto& encode = [](const auto& p) {
            return p[0] * 7 * 7 + p[1] * 7 + p[2];
        };

        vector<vector<int>> q;
        vector<bool> lookup(7 * 7 * 7);
        for (const auto& p : points) {
            if (lookup[encode(p)]) {
                continue;
            }
            lookup[encode(p)] = true;
            q.emplace_back(p);
        }
        for (int k = 0; !empty(q); ++k) {
            if (lookup[encode(target)]) {
                return k;
            }
            vector<vector<int>> new_q;
            for (int i = size(points) - size(q); i < size(points); ++i) {
                for (int j = 0; j < i; ++j) {
                    const auto& p = vector<int>{(points[i][0] + points[j][0]) / 2, (points[i][1] + points[j][1]) / 2, (points[i][2] + points[j][2]) / 2};
                    if (lookup[encode(p)]) {
                        continue;
                    }
                    lookup[encode(p)] = true;
                    new_q.emplace_back(p);
                }
            }
            ranges::copy(new_q, std::back_inserter(points));
            q = move(new_q);
        }
        return -1;
    }
};
