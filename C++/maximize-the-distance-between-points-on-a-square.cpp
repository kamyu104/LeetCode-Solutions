// Time:  O(nlogn + nlogs), s = side
// Space: O(n)

// sort, binary search, greedy, two pointers, sliding window
class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };
      
        vector<int64_t> p;
        for (const auto& x : points) {
            if (x[0] == 0) {
                p.emplace_back(0ll * side + x[1]);
            } else if(x[1] == side) {
                p.emplace_back(1ll * side + x[0]);
            } else if(x[0] == side) {
                p.emplace_back(2ll * side + (side - x[1]));
            } else {
                p.emplace_back(3ll * side + (side - x[0]));
            }
        }
        sort(begin(p), end(p));
        
        const auto& check = [&](int d) {
            vector<tuple<int, int, int>> intervals = {{0, 0, 1}};
            for (int right = 1, i = 0; right < size(p); ++right) {
                int left = right, cnt = 1;
                for (; i < size(intervals); ++i) {
                    const auto& [l, r, c] = intervals[i];
                    if (p[right] - p[r] < d) {
                        break;
                    }
                    if ((p[l] + 4ll * side) - p[right] >= d) {
                        if (c + 1 >= cnt) {
                            cnt = c + 1;
                            left = l;
                        }
                    }
                }
                intervals.emplace_back(left, right, cnt);
            }
            int mx = 0;
            for (const auto& [l, r, c] : intervals) {
                mx = max(mx, c);
            }
            return mx >= k;
        };

        return binary_search_right(1ll, 4ll * side / k, check);
    }
};

// Time:  O(nlogn + nlogs), s = side
// Space: O(n)
// sort, binary search, greedy, two pointers, sliding window
class Solution2 {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };
      
        vector<vector<pair<int, int>>> p(4);
        for (const auto& x : points) {
            if (x[0] == 0) {
                p[0].emplace_back(x[0], x[1]);
            } else if (x[1] == side) {
                p[1].emplace_back(x[0], x[1]);
            } else if (x[0] == side) {
                p[2].emplace_back(x[0], x[1]);
            } else {
                p[3].emplace_back(x[0], x[1]);
            }
        }
        sort(begin(p[0]), end(p[0]));
        sort(begin(p[1]), end(p[1]));
        sort(begin(p[2]), end(p[2]), greater<pair<int, int>>());
        sort(begin(p[3]), end(p[3]), greater<pair<int, int>>());
        vector<pair<int, int>> sorted_points;
        for (int i = 0; i < size(p); ++i) {
            for (const auto& x : p[i]) {
                sorted_points.emplace_back(x);
            }
        }
        
        const auto& check = [&](int d) {
            vector<tuple<int, int, int>> intervals = {{0, 0, 1}};
            for (int right = 1, i = 0; right < size(points); ++right) {
                int left = right, cnt = 1;
                for (; i < size(intervals); ++i) {
                    const auto& [l, r, c] = intervals[i];
                    if (abs(sorted_points[right].first - sorted_points[r].first) + abs(sorted_points[right].second - sorted_points[r].second) < d) {
                        break;
                    }
                    if (abs(sorted_points[right].first - sorted_points[l].first) + abs(sorted_points[right].second - sorted_points[l].second) >= d) {
                        if (c + 1 >= cnt) {
                            cnt = c + 1;
                            left = l;
                        }
                    }
                }
                intervals.emplace_back(left, right, cnt);
            }
            int mx = 0;
            for (const auto& [l, r, c] : intervals) {
                mx = max(mx, c);
            }
            return mx >= k;
        };

        return binary_search_right(1ll, 4ll * side / k, check);
    }
};

// Time:  O(nlogn + n * (k * logn) * logs), s = side
// Space: O(n)
// sort, binary search, greedy
class Solution3 {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        vector<int64_t> p;
        for (const auto& x : points) {
            if (x[0] == 0) {
                p.emplace_back(0ll * side + x[1]);
            } else if(x[1] == side) {
                p.emplace_back(1ll * side + x[0]);
            } else if(x[0] == side) {
                p.emplace_back(2ll * side + (side - x[1]));
            } else {
                p.emplace_back(3ll * side + (side - x[0]));
            }
        }
        sort(begin(p), end(p));
        int64_t result = 1;
        for (int i = 0; i < size(p) - k + 1; ++i) {
            if (p.back() - p[i] <= result * (k - 1ll)) { // to speed up
                break;
            }
            result = binary_search_right(result + 1ll, 4ll * side / k, [&](int d) { 
                int j = i;
                for (int _ = 0; _ < k - 1; ++_) {
                    j = distance(cbegin(p), lower_bound(cbegin(p) + j + 1, cend(p), p[j] + d));
                    if (j == size(p)) {
                        return false;
                    }
                }
                return (p[i] + 4ll * side) - p[j] >= d;
             });
        }
        return result;
    }
};

// Time:  O(nlogn + (n * k * logn) * logs), s = side
// Space: O(n)
// sort, binary search, greedy
class Solution4 {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        vector<int64_t> p;
        for (const auto& x : points) {
            if (x[0] == 0) {
                p.emplace_back(0ll * side + x[1]);
            } else if(x[1] == side) {
                p.emplace_back(1ll * side + x[0]);
            } else if(x[0] == side) {
                p.emplace_back(2ll * side + (side - x[1]));
            } else {
                p.emplace_back(3ll * side + (side - x[0]));
            }
        }
        sort(begin(p), end(p));
        for (int i = 0; i < size(points); ++i) {
            p.emplace_back(p[i] + 4ll * side);
        }
        const auto& check = [&](int d) {
            for (int i = 0; i < size(points); ++i) {
                int j = i;
                int cnt = 0;
                for (; cnt < k - 1; ++cnt) {
                    j = distance(cbegin(p), lower_bound(cbegin(p) + j + 1, cbegin(p) + (i + size(points)), p[j] + d));
                    if (j == i + size(points)) {
                        break;
                    }
                }
                if (cnt == k - 1) {
                    if ((p[i] + 4ll * side) - p[j] >= d) {
                        return true;
                    }
                }
            }
            return false;
        };

        return binary_search_right(1ll, 4ll * side / k, check);
    }
};
