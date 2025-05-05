// Time:  O(n + qlogn)
// Space: O(n)

// template from: https://cp-algorithms.com/data_structures/treap.html
using pTreapNode = struct TreapNode *;

struct TreapNode {
    int prior, value, cnt;
    int xor_sum;  // added
    bool rev;
    pTreapNode l, r;

    TreapNode (int v) : value(v), prior(rand()), cnt(1), xor_sum(v), rev(false), l(nullptr), r(nullptr) {}  // added
};

int cnt(pTreapNode t) {
    return t ? t->cnt : 0;
}

int xor_sum(pTreapNode t) {  // added
    return t ? t->xor_sum : 0;
}

void upd_cnt(pTreapNode t) {
    if (t) {
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
        t->xor_sum = t->value ^ xor_sum(t->l) ^ xor_sum(t->r);  // added
    }
}

void push(pTreapNode t) {
    if (t && t->rev) {
        t->rev = false;
        swap(t->l, t->r);
        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
    }
}

void merge(pTreapNode& t, pTreapNode l, pTreapNode r) {
    push(l);
    push(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd_cnt(t);
}

void split(pTreapNode t, pTreapNode& l, pTreapNode& r, int key, int add = 0) {
    if (!t)
        return void(l = r = 0);
    push(t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split(t->l, l, t->l, key, add), r = t;
    else
        split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
    upd_cnt(t);
}

void reverse(pTreapNode t, int l, int r) {
    pTreapNode t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= true;
    merge(t, t1, t2);
    merge(t, t, t3);
}

void heapify(pTreapNode t) {
    if (!t) return;
    pTreapNode max = t;
    if (t->l && t->l->prior > max->prior)
        max = t->l;
    if (t->r && t->r->prior > max->prior)
        max = t->r;
    if (max != t) {
        swap(t->prior, max->prior);
        heapify(max);
    }
}

pTreapNode build(const vector<int>& a, int i, int n) {
    if (n == 0) return nullptr;
    int mid = n / 2;
    auto t = new TreapNode(a[i + mid]);
    t->l = build(a, i, mid);
    t->r = build(a, i + mid + 1, n - mid - 1);
    heapify(t);
    upd_cnt(t);
    return t;
}

// treap
class Solution {
public:
    vector<int> getResults(vector<int>& nums, vector<vector<int>>& queries) {
        pTreapNode root = build(nums, 0, size(nums));
        const auto& update = [&](int index, int value) {
            pTreapNode left, mid, right;
            split(root, left, mid, index);
            split(mid, mid, right, 1);
            mid->value = value;
            upd_cnt(mid);
            merge(root, left, mid);
            merge(root, root, right);
        };

        const auto& query = [&](int left, int right) {
            pTreapNode t1, t2, t3;
            split(root, t1, t2, left);
            split(t2, t2, t3, right - left + 1);
            int result = xor_sum(t2);
            merge(root, t1, t2);
            merge(root, root, t3);
            return result;
        };

        vector<int> result;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                update(q[1], q[2]);
            } else if (q[0] == 2) {
                result.emplace_back(query(q[1], q[2]));
            } else if (q[0] == 3) {
                reverse(root, q[1], q[2]);
            }
        }
        return result;
    }
};
