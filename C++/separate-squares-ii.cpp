// Time:  O(nlogn)
// Space: O(n)

// sort, line sweep, segment tree
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        unordered_set<int> x_set;
        for (const auto& s : squares) {
            events.emplace_back(s[1], +1, s[0], s[0] + s[2]);
            events.emplace_back(s[1] + s[2], -1, s[0], s[0] + s[2]);
            x_set.emplace(s[0]);
            x_set.emplace(s[0] + s[2]);
        }
        sort(begin(events), end(events), [](const auto& a, const auto& b) {
            return get<0>(a) < get<0>(b);
        });
        vector<int> sorted_x(cbegin(x_set), cend(x_set));
        sort(begin(sorted_x), end(sorted_x));
        unordered_map<int, int> x_to_idx;
        for (int i = 0; i < size(sorted_x); ++i) {  // coordinate compression
            x_to_idx[sorted_x[i]] = i;
        }
        auto st = SegmentTreeRecu(sorted_x);
        int prev = get<0>(events[0]);
        vector<tuple<int, int, double>> intervals;
        for (const auto& [y, v, x1, x2] : events) {
            if (y != prev) {
                intervals.emplace_back(prev, y, st.tree[1]);
                prev = y;
            }
            st.update(x_to_idx[x1], x_to_idx[x2], v, 0, size(sorted_x) - 1, 1);
        }
        double expect = 0;
        for (const auto& [y1, y2, curr] : intervals) {
            expect += (y2 - y1) * curr;
        }
        expect /= 2;
        double total = 0;
        for (const auto& [y1, y2, curr] : intervals) {
            if (total + (y2 - y1) * curr >= expect) {
                return y1 + (expect - total) / curr;
            }
            total += (y2 - y1) * curr;
        }
        return -1;
    }

private:
    class SegmentTreeRecu {
    public:
        SegmentTreeRecu(const vector<int>& sorted_x) : sorted_x(sorted_x) {
            const int n = size(sorted_x) - 1;
            const int l = n > 1 ? 1 << (__lg(n - 1) + 2) : 2;
            tree.assign(l, 0);
            cnt.assign(l, 0);
        }

        void update(int ql, int qr, int v, int l, int r, int i) {  // update [ql, qr) by v, interval [l, r) in sorted_x is covered by i
            if (ql >= r || qr <= l) {
                return;
            }
            if (ql <= l && r <= qr) {
                cnt[i] += v;
            } else {
                const auto m = l + (r - l) / 2;
                update(ql, qr, v, l, m, 2 * i);
                update(ql, qr, v, m, r, 2 * i + 1);
            }
            if (cnt[i] > 0) {
                tree[i] = sorted_x[r] - sorted_x[l];
            } else {
                if (r - l == 1) {
                    tree[i] = 0;
                } else {
                    tree[i] = tree[2 * i] + tree[2 * i + 1];
                }
            }
        }

    public:
        vector<int> sorted_x;
        vector<int> tree;
        vector<int> cnt;
    };
};
