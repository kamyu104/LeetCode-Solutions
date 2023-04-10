// Time:  O(n) on average
// Space: O(n)

// random algorithms, variant of closest pair
// reference: https://github.com/jilljenn/tryalgo/blob/master/tryalgo/closest_points.py
class Solution {
private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<T>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        static const int INF = numeric_limits<int>::max();
        srand(time(0));

        vector<vector<int>> points;
        for (int i = 0; i < size(nums1); ++i) {
            points.push_back({nums1[i], nums2[i], i});
        }
        vector<int> result(3, INF);
        unordered_map<vector<int>, int, VectorHash<int>> lookup;
        for (int i = size(points) - 1; i >= 0; --i) {
            const auto& key = vector<int>{points[i][0], points[i][1]};
            if (lookup.count(key)) {
                result = min(result, vector<int>{0, i, lookup[key]});
            }
            lookup[key] = i;
        }
        if (result[0] == 0) {
            return {result[1], result[2]};
        }
        vector<int> order(size(points));
        iota(begin(order), end(order), 0);
        sort(begin(order), end(order), [&](const auto& a, const auto& b) {
            return points[a] < points[b];
        });
        const auto& dist = [&](auto a, auto b) {
            if (a[2] > b[2]) {
                swap(a, b);
            }
            return vector<int>{abs(a[0] - b[0]) + abs(a[1] - b[1]), a[2], b[2]};
        };

        const auto& improve = [&]() {
            unordered_map<vector<int>, vector<int>, VectorHash<int>> lookup;
            for (const auto& p : points) {
                const double size = result[0] / 2.0;
                const int i = floor(p[0] / size), j = floor(p[1] / size);
                for (int ni = i - 2; ni <= i + 2; ++ni) {
                    for (int nj = j - 2; nj <= j + 2; ++nj) {
                        const auto& key = vector<int>{ni, nj};
                        if (!lookup.count(key)) {
                            continue;
                        }
                        const auto& d = dist(p, lookup[key]);
                        if (d < result) {
                            result = d;
                            return true;
                        }
                    }
                }
                lookup[vector<int>{i, j}] = p;
            }
            return false;
        };

        random_shuffle(begin(points), end(points));
        result = dist(points[0], points[1]);
        while (improve());
        return {result[1], result[2]};
    }
};

// Time:  O(nlogn)
// Space: O(n)
// divide and conquer, merge sort, variant of closest pair
// reference: https://www.baeldung.com/cs/minimal-manhattan-distance
class Solution2 {
private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<T>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        static const int INF = numeric_limits<int>::max();
        static const int MAX_NEIGHBOR_COUNT = (8 + 2) / 2;

        vector<vector<int>> points;
        for (int i = 0; i < size(nums1); ++i) {
            points.push_back({nums1[i], nums2[i]});
        }
        vector<int> result(3, INF);
        unordered_map<vector<int>, int, VectorHash<int>> lookup;
        for (int i = size(points) - 1; i >= 0; --i) {
            if (lookup.count(points[i])) {
                result = min(result, vector<int>{0, i, lookup[points[i]]});
            }
            lookup[points[i]] = i;
        }
        if (result[0] == 0) {
            return {result[1], result[2]};
        }
        vector<int> order(size(points));
        iota(begin(order), end(order), 0);
        sort(begin(order), end(order), [&](const auto& a, const auto& b) {
            return points[a][0] < points[b][0];
        });
        const auto& dist = [&](auto a, auto b) {
            if (a > b) {
                swap(a, b);
            }
            return vector<int>{abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]), a, b};
        };

        const function<void (int, int)> merge_sort = [&](int left, int right) {
            const auto& update = [&](const auto& arr, int i) {  // added
                for (int j = size(arr) - 1; j >= 0; --j) {
                    if (points[i][1] - points[arr[j]][1] > result[0]) {
                        break;
                    }
                    assert((size(arr) - 1) - j + 1 <= MAX_NEIGHBOR_COUNT);
                    result = min(result, dist(i, arr[j]));
                }
            };
            
            if (left == right) {
                return;
            }
            const int mid = left + (right - left) / 2;
            const int x = points[order[mid]][0];  // added
            merge_sort(left, mid);
            merge_sort(mid + 1, right);
            vector<int> tmp, tmp_l, tmp_r;
            for (int l = left, r = mid + 1; l < mid + 1 || r < right + 1;) {
                if (r >= right + 1 || (l < mid + 1 && points[order[l]][1] <= points[order[r]][1])) {  // modified
                    update(tmp_r, order[l]);
                    if (x - points[order[l]][0] <= result[0]) {  // added
                        tmp_l.emplace_back(order[l]);
                    }
                    tmp.emplace_back(order[l++]);
                } else {
                    update(tmp_l, order[r]);
                    if (points[order[r]][0] - x <= result[0]) {  // added
                        tmp_r.emplace_back(order[r]);
                    }
                    tmp.emplace_back(order[r++]);
                }
            }
            copy(cbegin(tmp), cend(tmp), begin(order) + left);
        };
        
        merge_sort(0, size(points) - 1);
        return {result[1], result[2]};
    }
};

// Time:  O(nlogn)
// Space: O(n)
// divide and conquer, merge sort, variant of closest pair
// reference: https://www.baeldung.com/cs/minimal-manhattan-distance
class Solution3 {
private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<T>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        static const int INF = numeric_limits<int>::max();
        static const int MAX_NEIGHBOR_COUNT = 8;

        vector<vector<int>> points;
        for (int i = 0; i < size(nums1); ++i) {
            points.push_back({nums1[i], nums2[i]});
        }
        vector<int> result(3, INF);
        unordered_map<vector<int>, int, VectorHash<int>> lookup;
        for (int i = size(points) - 1; i >= 0; --i) {
            if (lookup.count(points[i])) {
                result = min(result, vector<int>{0, i, lookup[points[i]]});
            }
            lookup[points[i]] = i;
        }
        if (result[0] == 0) {
            return {result[1], result[2]};
        }
        vector<int> order(size(points));
        iota(begin(order), end(order), 0);
        sort(begin(order), end(order), [&](const auto& a, const auto& b) {
            return points[a][0] < points[b][0];
        });
        const auto& dist = [&](auto a, auto b) {
            if (a > b) {
                swap(a, b);
            }
            return vector<int>{abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]), a, b};
        };

        const function<void (int, int)> merge_sort = [&](int left, int right) {
            if (left == right) {
                return;
            }
            const int mid = left + (right - left) / 2;
            const int x = points[order[mid]][0];  // added
            merge_sort(left, mid);
            merge_sort(mid + 1, right);
            vector<int> tmp;
            for (int l = left, r = mid + 1; l <= mid; ++l) {
                while (r <= right && points[order[r]][1] < points[order[l]][1]) {  // modified
                    tmp.emplace_back(order[r++]);
                }
                tmp.emplace_back(order[l]);
            }
            copy(cbegin(tmp), cend(tmp), begin(order) + left);

            // added below
            vector<int> stripe;
            for (int i = left; i <= right; ++i) {
                if (abs(points[order[i]][0] - x) <= result[0]) {
                    stripe.emplace_back(order[i]);
                }
            }
            for (int i = 0; i + 1 < size(stripe); ++i) {
                for (int j = i + 1; j < size(stripe); ++j) {
                    int x = stripe[i], y = stripe[j];
                    if (points[y][1] - points[x][1] > result[0]) {
                        break;
                    }
                    assert(j - (i + 1) + 1 <= MAX_NEIGHBOR_COUNT);
                    result = min(result, dist(x, y));
                }
            }      
        };
        
        merge_sort(0, size(points) - 1);
        return {result[1], result[2]};
    }
};

// Time:  O(nlogn)
// Space: O(n)
// segment tree
class Solution4 {
private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<T>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        static const int INF = numeric_limits<int>::max();

        vector<vector<int>> points;
        for (int i = 0; i < size(nums1); ++i) {
            points.push_back({nums1[i], nums2[i]});
        }
        vector<int> result(3, INF);
        unordered_map<vector<int>, int, VectorHash<int>> lookup;
        for (int i = size(points) - 1; i >= 0; --i) {
            if (lookup.count(points[i])) {
                result = min(result, vector<int>{0, i, lookup[points[i]]});
            }
            lookup[points[i]] = i;
        }
        if (result[0] == 0) {
            return {result[1], result[2]};
        }
        vector<int> order(size(points));
        iota(begin(order), end(order), 0);
        sort(begin(order), end(order), [&](const auto& a, const auto& b) {
            return points[a][0] < points[b][0];
        });
        const auto& dist = [&](auto a, auto b) {
            if (a > b) {
                swap(a, b);
            }
            return vector<int>{abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]), a, b};
        };

        unordered_set<int> y_set;
        for (const auto& p : points) {
            y_set.emplace(p[1]);
        }
        vector<int> sorted_y(cbegin(y_set), cend(y_set));
        sort(begin(sorted_y), end(sorted_y));
        unordered_map<int, int> y_to_idx;
        for (int i = 0; i < size(sorted_y); ++i) {  // coordinate compression
            y_to_idx[sorted_y[i]] = i;
        }
        SegmentTree st1(size(y_to_idx)), st2(size(y_to_idx));
        for (const auto& i : order) {
            int j = -st1.query(0, y_to_idx[points[i][1]] - 1)[1];  // min((xi-xj)+(yi-yj) for j in range(y_to_idx[points[i][1])) = (xi+yi)-max((xj+yj) for j in range(y_to_idx[points[i][1]))
            if (j != INF) {
                assert(points[j][1] < points[i][1]);
                result = min(result, dist(i, j));
            }
            st1.update(y_to_idx[points[i][1]], vector<int>{points[i][0] + points[i][1], -i});
            j = -st2.query(y_to_idx[points[i][1]], size(y_to_idx) - 1)[1];   // min((xi-xj)+(yj-yi) for j in range(y_to_idx[points[i][1], len(y_to_idx))) = (xi-yi)-max((xj-yj) for j in range(y_to_idx[points[i][1], len(y_to_idx))
            if (j != INF) {
                assert(points[j][1] >= points[i][1]);
                result = min(result, dist(i, j));
            }
            st2.update(y_to_idx[points[i][1]], vector<int>{points[i][0] - points[i][1], -i});
        }
        return {result[1], result[2]};
    }

private:
    class SegmentTree {
    private:
        static const int INF = numeric_limits<int>::max();
      
    public:
        explicit SegmentTree(int N)
          : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2, vector<int>{-INF, -INF}),
            base(N > 1 ? 1 << (__lg(N - 1) + 1) : 1) {

        }

        void update(int i, const vector<int>& h) {
            int x = base + i;
            tree[x] = h;
            while (x > 1) {
                x /= 2;
                tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
            }
        }

        vector<int> query(int L, int R) {
            vector<int> result = {-INF, -INF};
            if (L > R) {
                return result;
            }
            L += base;
            R += base;
            for (; L <= R; L /= 2, R /= 2) {
                if (L & 1) {
                    result = max(result, tree[L]);
                    ++L;
                }
                if ((R & 1) == 0) {
                    result = max(tree[R], result);
                    --R;
                }
            }
            return result;
        }

        vector<vector<int>> tree;
        int base;
    };
};
