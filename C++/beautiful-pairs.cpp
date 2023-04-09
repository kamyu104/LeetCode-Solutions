// Time:  O(nlogn)
// Space: O(n)

// divide and conquer, merge sort, variant of closest pair
// reference: https://www.baeldung.com/cs/minimal-manhattan-distance
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
        static const int MAX_NEIGHBOR_COUNT = 8 - 1;

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
            return points[a] < points[b];
        });
        const auto& manhattan_distance = [](const auto& a, const auto& b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };

        const function<void (int, int)> merge_sort = [&](int left, int right) {
            const auto& update = [&](const auto& arr, int i) {  // added
                for (int j = size(arr) - 1; j >= 0; --j) {
                    if (points[i][1] - points[arr[j]][1] > result[0]) {
                        break;
                    }
                    assert((size(arr) - 1) - j + 1 <= MAX_NEIGHBOR_COUNT);
                    int x = i, y = arr[j];
                    if (x > y) {
                        swap(x, y);
                    }
                    result = min(result, vector<int>{manhattan_distance(points[x], points[y]), x, y});
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
        static const int MAX_NEIGHBOR_COUNT = 8 - 1;

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
            return points[a] < points[b];
        });
        const auto& manhattan_distance = [](const auto& a, const auto& b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
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
                    if (x > y) {
                        swap(x, y);
                    }
                    result = min(result, vector<int>{manhattan_distance(points[x], points[y]), x, y});
                }
            }      
        };
        
        merge_sort(0, size(points) - 1);
        return {result[1], result[2]};
    }
};
