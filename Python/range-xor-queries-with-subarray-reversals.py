# Time:  O(nlogn + qlogn)
# Space: O(n)

import random


# template from: https://cp-algorithms.com/data_structures/treap.html
class TreapNode(object):
    def __init__(self, value):
        self.value = value
        self.prior = random.randint(1, 1 << 30)
        self.cnt = 1
        self.xor_sum = value
        self.rev = False
        self.l = None
        self.r = None

def cnt(t):
    return t.cnt if t else 0

def xor_sum(t):
    return t.xor_sum if t else 0

def upd_cnt(t):
    if t:
        t.cnt = 1 + cnt(t.l) + cnt(t.r)
        t.xor_sum = t.value ^ xor_sum(t.l) ^ xor_sum(t.r)

def push(t):
    if t and t.rev:
        t.rev = False
        t.l, t.r = t.r, t.l
        if t.l:
            t.l.rev ^= True
        if t.r:
            t.r.rev ^= True

def merge(l, r):
    push(l)
    push(r)
    if not l or not r:
        return l or r
    if l.prior > r.prior:
        l.r = merge(l.r, r)
        upd_cnt(l)
        return l
    else:
        r.l = merge(l, r.l)
        upd_cnt(r)
        return r

def split(t, key, add=0):
    if not t:
        return (None, None)
    push(t)
    cur_key = add + cnt(t.l)
    if key <= cur_key:
        l, t.l = split(t.l, key, add)
        upd_cnt(t)
        return (l, t)
    else:
        t.r, r = split(t.r, key, add + 1 + cnt(t.l))
        upd_cnt(t)
        return (t, r)

def reverse(t, l, r):
    t1, t2 = split(t, l)
    t2, t3 = split(t2, r - l + 1)
    if t2:
        t2.rev ^= True
    return merge(merge(t1, t2), t3)

def heapify(t) {
    if not t:
        return
    pTreapNode max = t;
    if (t->l != NULL && t->l->prior > max->prior)
        max = t->l;
    if (t->r != NULL && t->r->prior > max->prior)
        max = t->r;
    if (max != t) {
        swap(t->prior, max->prior);
        heapify(max);
    }
}

pTreapNode build(const vector<int>& a, int i, int n) {
    if (n == 0) return NULL;
    int mid = n / 2;
    auto t = new TreapNode(a[i + mid]);
    t->l = build (a, i, mid);
    t->r = build (a, i + mid + 1, n - mid - 1);
    heapify(t);
    upd_cnt(t);
    return t;
}
# treap
class Solution_TLE(object):
    def getResults(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def build():
            root = None
            for x in nums:
                root = merge(root, TreapNode(x))
            return root

        def update(root, index, value):
            left, mid = split(root, index)
            mid, right = split(mid, 1)
            if mid:
                mid.value = value
                upd_cnt(mid)
            return merge(merge(left, mid), right)

        def query(root, left, right):
            t1, t2 = split(root, left)
            t2, t3 = split(t2, right - left + 1)
            result = xor_sum(t2)
            return merge(merge(t1, t2), t3), result

        result = []
        root = build()
        for q in queries:
            if q[0] == 1:
                root = update(root, q[1], q[2])
            elif q[0] == 2:
                root, x = query(root, q[1], q[2])
                result.append(x)
            elif q[0] == 3:
                root = reverse(root, q[1], q[2])
        return result
