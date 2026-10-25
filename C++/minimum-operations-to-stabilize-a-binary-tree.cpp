// Time:  O(nlogn)
// Space: O(n)

class Treap {
public:
    Treap() : t{{.key = 0, .lazy = 0, .sum = 0, .l = 0, .r = 0, .size = 0, .pri = 0}},  // Time: O(1), Space: O(1)
              rng(0x9E3779B9u) {}

    int make(int v) {  // Time: O(1), Space: O(1)
        t.push_back({.key = v, .lazy = 0, .sum = v, .l = 0, .r = 0, .size = 1,
                     .pri = static_cast<uint32_t>(rng())});
        return size(t) - 1;
    }

    int size_of(int x) const {  // Time: O(1), Space: O(1)
        return t[x].size;
    }

    int64_t sum_of(int x) const {  // Time: O(1), Space: O(1)
        return t[x].sum;
    }

    void apply(int x, int d) {  // Time: O(1), Space: O(1)
        if (x) {
            t[x].key += d; t[x].sum += static_cast<int64_t>(d) * t[x].size; t[x].lazy += d;
        }
    }

    pair<int, int> split_key(int x, int key, int id) {  // Time: O(logn), Space: O(logn)
        if (!x) {
            return {0, 0};
        }
        push(x);
        if (t[x].key < key || (t[x].key == key && x < id)) {
            const auto [a, b] = split_key(t[x].r, key, id);
            t[x].r = a; pull(x);
            return {x, b};
        }
        const auto [a, b] = split_key(t[x].l, key, id);
        t[x].l = b; pull(x);
        return {a, x};
    }

    pair<int, int> split_size(int x, int k) {  // Time: O(logn), Space: O(logn)
        if (!x) {
            return {0, 0};
        }
        push(x);
        const int ls = t[t[x].l].size;
        if (k <= ls) {
            const auto [a, b] = split_size(t[x].l, k);
            t[x].l = b; pull(x);
            return {a, x};
        }
        const auto [a, b] = split_size(t[x].r, k - ls - 1);
        t[x].r = a; pull(x);
        return {x, b};
    }

    int join(int a, int b) {  // Time: O(logn), Space: O(logn)
        if (!a || !b) {
            return a ? a : b;
        }
        if (t[a].pri > t[b].pri) {
            push(a); t[a].r = join(t[a].r, b); pull(a);
            return a;
        }
        push(b); t[b].l = join(a, t[b].l); pull(b);
        return b;
    }

    int unite(int a, int b) {  // Time: O(m * log(n / m)), Space: O(logn), m = min(|a|,|b|), n = max(|a|,|b|)
        if (!a || !b) {
            return a ? a : b;
        }
        if (t[a].pri < t[b].pri) {
            swap(a, b);
        }
        push(a);
        const auto [bl, br] = split_key(b, t[a].key, a);
        t[a].l = unite(t[a].l, bl);
        t[a].r = unite(t[a].r, br);
        pull(a);
        return a;
    }

private:
    struct Node {
        int key, lazy;
        int64_t sum;
        int l, r, size;
        uint32_t pri;
    };
    vector<Node> t;
    mt19937 rng;

    void push(int x) {  // Time: O(1), Space: O(1)
        if (t[x].lazy) {
            apply(t[x].l, t[x].lazy); apply(t[x].r, t[x].lazy); t[x].lazy = 0;
        }
    }

    void pull(int x) {  // Time: O(1), Space: O(1)
        t[x].size = 1 + t[t[x].l].size + t[t[x].r].size;
        t[x].sum = t[x].key + t[t[x].l].sum + t[t[x].r].sum;
    }
};

// tree dp, slope trick, treap
class Solution {
public:
    long long stabilizeBinaryTree(TreeNode* root) {
        struct State {
            int treap = 0;
            int64_t cost = 0;
        };

        Treap tr;

        const auto& widen = [&](auto& state) {  // Time: O(logn), Space: O(logn)
            const auto& k = tr.size_of(state.treap) / 2;
            const auto& [left, right] = tr.split_size(state.treap, k);
            tr.apply(left, -1);
            tr.apply(right, +1);
            state.treap = tr.join(left, right);
            state.cost -= k;
        };

        const auto& merge = [&](State u, const State& v) {  // Time: O(m * log(n / m)), Space: O(m), Total Time: O(nlogn), Total Space: O(n)
            u.treap = tr.unite(u.treap, v.treap);
            u.cost += v.cost;
            return u;
        };

        const auto& min_value = [&](const State& state) {  // Time: O(logn), Space: O(logn)
            const auto& [left, right] = tr.split_size(state.treap, tr.size_of(state.treap) / 2);
            return state.cost + (tr.sum_of(right) - tr.sum_of(left)) / 2;
        };

        vector<pair<TreeNode*, bool>> stk{{root, false}};
        vector<State> dp;
        while (!empty(stk)) {
            const auto [node, visited] = stk.back(); stk.pop_back();
            vector<TreeNode*> children;
            for (const auto& c : {node->left, node->right}) {
                if (c) {
                    children.emplace_back(c);
                }
            }
            if (!visited) {
                stk.emplace_back(node, true);
                for (const auto& x : children | std::views::reverse) {
                    stk.emplace_back(x, false);
                }
                continue;
            }
            State state{tr.join(tr.make(node->val), tr.make(node->val)), 0};
            for (const auto& _ : children | std::views::reverse) {
                auto child = dp.back(); dp.pop_back();
                widen(child);
                state = merge(state, child);
            }
            dp.emplace_back(state);
        }
        return min_value(dp[0]);
    }
};

// Time:  O(n * (logn)^2)
// Space: O(n)
// tree dp, slope trick, heap, small-to-large merging
class Solution2 {
public:
    long long stabilizeBinaryTree(TreeNode* root) {
        struct State {
            priority_queue<int> left;
            priority_queue<int, vector<int>, greater<>> right;
            int left_offset = 0, right_offset = 0;
            int64_t cost = 0;
        };

        const auto& add_left = [](auto& state, int x) {
            if (state.right.top() + state.right_offset < x) {
                auto y = state.right.top() + state.right_offset; state.right.pop();
                state.cost += x - y;
                state.right.emplace(x - state.right_offset);
                x = y;
            }
            state.left.emplace(x - state.left_offset);
        };

        const auto& add_right = [](auto& state, int x) {
            if (state.left.top() + state.left_offset > x) {
                auto y = state.left.top() + state.left_offset; state.left.pop();
                state.cost += y - x;
                state.left.emplace(x - state.left_offset);
                x = y;
            }
            state.right.emplace(x - state.right_offset);
        };

        auto small_to_large_merge = [&](unique_ptr<State> u, unique_ptr<State> v) {
            if (size(u->left) < size(v->left)) {
                swap(u, v);
            }
            u->cost += v->cost;
            while (!empty(v->left))  {
                add_left(*u, v->left.top() + v->left_offset);
                v->left.pop();
            }
            while (!empty(v->right)) {
                add_right(*u, v->right.top() + v->right_offset);
                v->right.pop();
            }
            return u;
        };

        vector<pair<TreeNode*, bool>> stk{{root, false}};
        vector<unique_ptr<State>> dp;
        while (!empty(stk)) {
            const auto [node, visited] = stk.back(); stk.pop_back();
            vector<TreeNode*> children;
            for (const auto& c : {node->left, node->right}) {
                if (c) {
                    children.emplace_back(c);
                }
            }
            if (!visited) {
                stk.emplace_back(node, true);
                for (const auto& x : children | std::views::reverse) {
                    stk.emplace_back(x, false);
                }
                continue;
            }
            auto state = make_unique<State>();
            state->left.emplace(node->val);
            state->right.emplace(node->val);
            for (const auto& _ : children | std::views::reverse) {
                auto child = move(dp.back()); dp.pop_back();
                --child->left_offset;
                ++child->right_offset;
                state = small_to_large_merge(move(state), move(child));
            }
            dp.emplace_back(move(state));
        }
        return dp[0]->cost;
    }
};
