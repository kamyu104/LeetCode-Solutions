// Time:  O(n + qlogn)
// Space: O(n)

// online solution, segment tree, binary search
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> result(size(queries), -1);
        SegmentTree st(heights);
        for (int i = 0; i < size(queries); ++i) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) {
                swap(a, b);
            }
            if (a == b || heights[a] < heights[b]) {
                result[i] = b;
                continue;
            }
            result[i] = st.binary_search(b + 1, size(heights) - 1, 0, size(heights) - 1, 1, heights[a]);
        }
        return result;
    }

private:
    class SegmentTree {
    public:
        explicit SegmentTree(const vector<int>& heights)
          : tree(size(heights) > 1 ? 1 << (__lg(size(heights) - 1) + 2) : 2),
            heights(heights) {
            
            build(0, size(heights) - 1, 1);
        }

        void build(int left, int right, int idx) {
            if (left == right) {
                tree[idx] = heights[left];
                return;
            }
            const int mid = left + (right - left) / 2;
            build(left, mid, idx * 2);
            build(mid + 1, right, idx * 2 + 1);
            tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
        }

        int binary_search(int L, int R, int left, int right, int idx, int h) {
            if (right < L || left > R) {
                return -1;
            }
            if (L <= left && right <= R) {
                if (!(tree[idx] > h)) {
                    return -1;
                }
                if (left == right) {
                    return left;
                }
            }
            const int mid = left + (right - left) / 2;
            const int i = binary_search(L, R, left, mid, idx * 2, h);
            return i != -1 ? i : binary_search(L, R, mid + 1, right, idx * 2 + 1, h);
        }

        vector<int> tree;
        const vector<int>& heights;
    };
};

// Time:  O(n + qlogq)
// Space: O(n + q)
// offline solution, heap
class Solution2 {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> result(size(queries), -1);
        vector<vector<pair<int, int>>> qs(size(heights));
        for (int i = 0; i < size(queries); ++i) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) {
                swap(a, b);
            }
            if (a == b || heights[a] < heights[b]) {
                result[i] = b;
            } else {
                qs[b].emplace_back(heights[a], i);
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (int i = 0; i < size(heights); ++i) {
            for (const auto& q : qs[i]) {
                min_heap.emplace(q);
            }
            while (!empty(min_heap) && min_heap.top().first < heights[i]) {
                const auto [_, j] = min_heap.top(); min_heap.pop();
                result[j] = i;
            }
        }
        return result;
    }
};

// Time:  O(n + qlogn)
// Space: O(n + q)
// offline solution, mono stack, binary search
class Solution3 {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> result(size(queries), -1);
        vector<vector<pair<int, int>>> qs(size(heights));
        for (int i = 0; i < size(queries); ++i) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) {
                swap(a, b);
            }
            if (a == b || heights[a] < heights[b]) {
                result[i] = b;
            } else {
                qs[b].emplace_back(heights[a], i);
            }
        }
        vector<pair<int, int>> stk;
        const auto& binary_search_right = [&](int left, int right, const auto& check) {
            while (left <= right) {
                const int mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        for (int b = size(heights) - 1; b >= 0; --b) {
            while (!empty(stk) && stk.back().first <= heights[b]) {
                stk.pop_back();
            }
            stk.emplace_back(heights[b], b);
            for (const auto& [ha, i] : qs[b]) {
                const int j = binary_search_right(0, size(stk) - 1, [&, &ha = ha](int x) {
                    return stk[x].first > ha;
                });
                if (j >= 0) {
                    result[i] = stk[j].second;
                }
            }
        }
        return result;
    }
};
