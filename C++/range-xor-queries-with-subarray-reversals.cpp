// Time:  O(nlogn + qlogn)
// Space: O(n)

// template from: https://cp-algorithms.com/data_structures/treap.html
typedef struct item* pitem;

struct item {
    int prior, value, cnt;
    int xor_sum;  // added
    bool rev;
    pitem l, r;

    item(int v) : value(v), prior(rand()), cnt(1), xor_sum(v), rev(false), l(nullptr), r(nullptr) {}  // added
};

int cnt(pitem it) {
    return it ? it->cnt : 0;
}

int xor_sum(pitem it) {  // added
    return it ? it->xor_sum : 0;
}

void upd_cnt(pitem it) {
    if (it) {
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
        it->xor_sum = it->value ^ xor_sum(it->l) ^ xor_sum(it->r);  // added
    }
}

void push(pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap(it->l, it->r);
        if (it->l) it->l->rev ^= true;
        if (it->r) it->r->rev ^= true;
    }
}

void merge(pitem & t, pitem l, pitem r) {
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

void split(pitem t, pitem & l, pitem & r, int key, int add = 0) {
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

void reverse(pitem t, int l, int r) {
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= true;
    merge(t, t1, t2);
    merge(t, t, t3);
}

// treap
class Solution {
public:
    vector<int> getResults(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        pitem root = nullptr;
        const auto& build = [&]() {
            for (const auto& x : nums) {
                merge(root, root, new item(x));
            };
        };

        const auto& update = [&](int index, int value) {
            pitem left, mid, right;
            split(root, left, mid, index);
            split(mid, mid, right, 1);
            mid->value = value;
            upd_cnt(mid);
            merge(root, left, mid);
            merge(root, root, right);
        };

        const auto& query = [&](int left, int right) {
            pitem t1, t2, t3;
            split(root, t1, t2, left);
            split(t2, t2, t3, right - left + 1);
            int result = xor_sum(t2);
            merge(root, t1, t2);
            merge(root, root, t3);
            return result;
        };

        build();
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
