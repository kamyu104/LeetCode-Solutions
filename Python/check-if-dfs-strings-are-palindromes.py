# Time:  O(n)
# Space: O(n)

# iterative dfs, manacher's algorithm
class Solution(object):
    def findAnswer(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: List[bool]
        """
        def manacher(s):
            s = '^#' + '#'.join(s) + '#$'
            P = [0]*len(s)
            C, R = 0, 0
            for i in xrange(1, len(s)-1):
                i_mirror = 2*C-i
                if R > i:
                    P[i] = min(R-i, P[i_mirror])
                while s[i+1+P[i]] == s[i-1-P[i]]:
                    P[i] += 1
                if i+P[i] > R:
                    C, R = i, i+P[i]
            return P
    
        def iter_dfs(u):
            cnt = 0
            curr = []
            lookup = [None]*len(adj)
            stk = [(1, (0,))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u = args[0]
                    stk.append((2, (u, cnt)))
                    for v in reversed(adj[u]):
                        stk.append((1, (v,)))
                elif step == 2:
                    u, left = args
                    curr.append(s[u])
                    lookup[u] = (left, cnt)
                    cnt += 1
            return curr, lookup

        adj = [[] for _ in xrange(len(parent))]
        for v in xrange(1, len(parent)):
            adj[parent[v]].append(v)
        curr, lookup = iter_dfs(0)
        P = manacher(curr)
        return [P[(2*(left+1)+2*(right+1))//2] >= right-left+1 for left, right in lookup]


# Time:  O(n)
# Space: O(n)
# dfs, manacher's algorithm
class Solution2(object):
    def findAnswer(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: List[bool]
        """
        def manacher(s):
            s = '^#' + '#'.join(s) + '#$'
            P = [0]*len(s)
            C, R = 0, 0
            for i in xrange(1, len(s)-1):
                i_mirror = 2*C-i
                if R > i:
                    P[i] = min(R-i, P[i_mirror])
                while s[i+1+P[i]] == s[i-1-P[i]]:
                    P[i] += 1
                if i+P[i] > R:
                    C, R = i, i+P[i]
            return P
    
        def dfs(u):
            left = cnt[0]
            for v in adj[u]:
                dfs(v)
            curr.append(s[u])
            lookup[u] = (left, cnt[0])
            cnt[0] += 1

        adj = [[] for _ in xrange(len(parent))]
        for v in xrange(1, len(parent)):
            adj[parent[v]].append(v)
        cnt = [0]
        curr = []
        lookup = [None]*len(adj)
        dfs(0)
        P = manacher(curr)
        return [P[(2*(left+1)+2*(right+1))//2] >= right-left+1 for left, right in lookup]
