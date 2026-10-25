# Time:  O(n * (logn^2))
# Space: O(n)

import heapq


# tree dp, slope trick, heap, small-to-large merging
class Solution(object):
    def stabilizeBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        LEFT, RIGHT, LEFT_OFFSET, RIGHT_OFFSET, COST = range(5)
        def add_left(state, x):
            if state[RIGHT][0]+state[RIGHT_OFFSET] < x:
                y = heapq.heappop(state[RIGHT])+state[RIGHT_OFFSET]
                state[COST] += x-y
                heapq.heappush(state[RIGHT], x-state[RIGHT_OFFSET])
                x = y
            heapq.heappush(state[LEFT], -(x-state[LEFT_OFFSET]))

        def add_right(state, x):
            if -(state[LEFT][0]-state[LEFT_OFFSET]) > x:
                y = -(heapq.heappop(state[LEFT])-state[LEFT_OFFSET])
                state[COST] += y-x
                heapq.heappush(state[LEFT], -(x-state[LEFT_OFFSET]))
                x = y
            heapq.heappush(state[RIGHT], x-state[RIGHT_OFFSET])

        def small_to_large_merge(u, v):
            if len(u[LEFT]) < len(v[LEFT]):
                u, v = v, u
            u[COST] += v[COST]
            for x in v[LEFT]:
                add_left(u, -x+v[LEFT_OFFSET])
            for x in v[RIGHT]:
                add_right(u, x+v[RIGHT_OFFSET])
            return u

        stk, dp = [(root, False)], []
        while stk:
            node, visited = stk.pop()
            children = [c for c in (node.left, node.right) if c]
            if not visited:
                stk.append((node, True))
                for c in reversed(children):
                    stk.append((c, False))
                continue
            state = [[-node.val], [node.val], 0, 0, 0]
            for _ in reversed(children):
                child = dp.pop()
                child[LEFT_OFFSET] -= 1
                child[RIGHT_OFFSET] += 1
                state = small_to_large_merge(state, child)
            dp.append(state)
        return dp[0][COST]


# Time:  O(nlogn)
# Space: O(n)
import random


class Treap(object):
    def __init__(self):  # Time: O(1), Space: O(1)
        self.K, self.S, self.Z = [0], [0], [0]   # key, subtree sum, lazy add
        self.L, self.R, self.SZ = [0], [0], [0]  # children, subtree size; index 0 is null
        self.P = [0]                             # priority

    def make(self, v):  # Time: O(1), Space: O(1)
        self.K.append(v); self.S.append(v); self.Z.append(0)
        self.L.append(0); self.R.append(0); self.SZ.append(1)
        self.P.append(random.getrandbits(30))
        return len(self.K)-1

    def size(self, x):  # Time: O(1), Space: O(1)
        return self.SZ[x]

    def sum(self, x):  # Time: O(1), Space: O(1)
        return self.S[x]

    def apply(self, x, d):  # Time: O(1), Space: O(1)
        if x:
            self.K[x] += d; self.S[x] += d*self.SZ[x]; self.Z[x] += d
    def __push(self, x):  # Time: O(1), Space: O(1)
        if self.Z[x]:
            self.apply(self.L[x], self.Z[x]); self.apply(self.R[x], self.Z[x]); self.Z[x] = 0

    def __pull(self, x):  # Time: O(1), Space: O(1)
        self.SZ[x] = 1+self.SZ[self.L[x]]+self.SZ[self.R[x]]
        self.S[x] = self.K[x]+self.S[self.L[x]]+self.S[self.R[x]]

    def __split(self, x, go_left):  # Time: O(logn), Space: O(logn)
        L, R = self.L, self.R
        path, lres, rres, lp, rp = [], 0, 0, 0, 0
        while x:
            self.__push(x); path.append(x)
            if go_left(x):
                if lp:
                    R[lp] = x
                else:
                    lres = x
                lp, x = x, R[x]
            else:
                if rp:
                    L[rp] = x
                else:
                    rres = x
                rp, x = x, L[x]
        if lp:
            R[lp] = 0
        if rp:
            L[rp] = 0
        for x in reversed(path):
            self.__pull(x)
        return lres, rres

    def split_key(self, x, key, id):  # Time: O(logn), Space: O(logn)
        K = self.K
        return self.__split(x, lambda y: K[y] < key or (K[y] == key and y < id))

    def split_size(self, x, k):  # Time: O(logn), Space: O(logn)
        L, SZ = self.L, self.SZ
        cnt = [k]
        def go_left(y):
            if cnt[0] > SZ[L[y]]:
                cnt[0] -= SZ[L[y]]+1
                return True
            return False
        return self.__split(x, go_left)

    def join(self, a, b):  # Time: O(logn), Space: O(logn)
        if not a or not b:
            return a or b
        L, R, P = self.L, self.R, self.P
        path, rt, par, side = [], 0, 0, 0
        while a and b:
            if P[a] > P[b]:
                x, a, nside = a, R[a], 1
            else:
                x, b, nside = b, L[b], 2
            self.__push(x); path.append(x)
            if not par:
                rt = x
            elif side == 1:
                R[par] = x
            else:
                L[par] = x
            par, side = x, nside
        if side == 1:
            R[par] = a or b
        else:
            L[par] = a or b
        for x in reversed(path):
            self.__pull(x)
        return rt

    def unite(self, a, b):  # Time: O(m * log(n / m)), Space: O(m), m = min(|a|,|b|), n = max(|a|,|b|)
        K, L, R, P = self.K, self.L, self.R, self.P
        work, settled = [(a, b, 0, 2)], []
        while work:
            a, b, par, side = work.pop()
            if a and b:
                if P[a] < P[b]:
                    a, b = b, a
                self.__push(a)
                bl, br = self.split_key(b, K[a], a)
                settled.append(a)
                work.append((L[a], bl, a, 2))
                work.append((R[a], br, a, 1))
                res = a
            else:
                res = a or b
            if side == 1:
                R[par] = res
            else:
                L[par] = res
        for x in reversed(settled):
            self.__pull(x)
        rt, L[0] = L[0], 0
        return rt


# tree dp, slope trick, treap
class Solution_TLE(object):
    def stabilizeBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        TREAP, COST = range(2)
        def widen(state):   # Time: O(logn), Space: O(logn)
            k = tr.size(state[TREAP])//2
            left, right = tr.split_size(state[TREAP], k)
            tr.apply(left, -1)
            tr.apply(right, +1)
            state[TREAP] = tr.join(left, right)
            state[COST] -= k

        def merge(u, v):  # Time: O(m * log(n / m)), Space: O(m), Total Time: O(nlogn), Total Space: O(n)
            u[TREAP] = tr.unite(u[TREAP], v[TREAP])
            u[COST] += v[COST]
            return u

        def min_value(state):  # Time: O(logn), Space: O(logn)
            left, right = tr.split_size(state[TREAP], tr.size(state[TREAP])//2)
            return state[COST]+(tr.sum(right)-tr.sum(left))//2

        tr = Treap()
        stk, dp = [(root, False)], []
        while stk:
            node, visited = stk.pop()
            children = [c for c in (node.left, node.right) if c]
            if not visited:
                stk.append((node, True))
                for c in reversed(children):
                    stk.append((c, False))
                continue
            state = [tr.join(tr.make(node.val), tr.make(node.val)), 0]
            for _ in reversed(children):
                child = dp.pop()
                widen(child)
                state = merge(state, child)
            dp.append(state)
        return min_value(dp[0])
