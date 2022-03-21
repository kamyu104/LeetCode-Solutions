// Time:  O(nlogn)
// Space: O(n)

template <typename Node, typename T>
class SegmentTree {
 public:
    explicit SegmentTree(
        int N,
        const function<Node(const int&)>& build_fn,
        const function<Node(const T&)>& update_fn,
        const function<Node(const Node&, const Node&)>& query_fn)
      : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2),
        base_(N > 1 ? 1 << (__lg(N - 1) + 1) : 1),
        build_fn_(build_fn),
        query_fn_(query_fn),
        update_fn_(update_fn) {

        for (int i = base_; i < base_ + N; ++i) {
            tree[i] = build_fn_(i - base_);
        }
        for (int i = base_ - 1; i >= 1; --i) {
            tree[i] = query_fn_(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int i, const T& h) {
        int x = base_ + i;
        tree[x] = update_fn_(h);
        while (x > 1) {
            x /= 2;
            tree[x] = query_fn_(tree[x * 2], tree[x * 2 + 1]);
        }
    }

    vector<Node> tree;

private:
    int base_;
    const function<Node(const int&)> build_fn_;
    const function<Node(const T&)> update_fn_;
    const function<Node(const Node&, const Node&)> query_fn_;
};

// segment tree
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        struct Node {
            Node(char left = 0, char right = 0, int left_len = 0, int right_len = 0, int len = 0, int max_len = 0) 
             : left(left), right(right), left_len(left_len), right_len(right_len), len(len), max_len(max_len) {
            }

            char left;
            char right;
            int left_len;
            int right_len;
            int len;
            int max_len;
        };
        const auto& update = [] (const auto& c) {
            return Node(c, c, 1, 1, 1, 1);
        };
        const auto& build = [&s, &update] (const auto& i) {
            return update(s[i]);
        };
        const auto& query = [] (const auto& x, const auto& y) {
            if (y.len == 0) {
                return x;
            }
            return Node(x.left,
                        y.right,
                        x.left_len + ((x.left_len == x.len && x.right == y.left) ? y.left_len : 0),
                        y.right_len + ((y.right_len == y.len && y.left == x.right) ? x.right_len : 0),
                        x.len + y.len,
                        max({x.max_len, y.max_len, (x.right == y.left) ? x.right_len + y.left_len : 0}));
        };
        vector<int> result;
        SegmentTree<Node, char> st(size(s), build, update, query);
        for (int i = 0; i < size(queryCharacters); ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            result.emplace_back(st.tree[1].max_len);
        }
        return result;
    }
};
