# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


# iterative dfs, tree dp
class Solution(object):
    def amountOfTime(self, root, start):
        """
        :type root: Optional[TreeNode]
        :type start: int
        :rtype: int
        """
        def iter_dfs(root, start):
            result = -1
            stk = [(1, (root, [-1]*2))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    curr, ret = args
                    if curr is None:
                        continue
                    left, right = [-1]*2, [-1]*2
                    stk.append((2, (curr, left, right, ret)))
                    stk.append((1, (curr.right, right)))
                    stk.append((1, (curr.left, left)))
                elif step == 2:
                    curr, left, right, ret = args
                    d = -1
                    if curr.val == start:
                        d = 0
                        result = max(left[0], right[0])+1
                    elif left[1] >= 0:
                        d = left[1]+1
                        result = max(result, right[0]+1+d)
                    elif right[1] >= 0:
                        d = right[1]+1
                        result = max(result, left[0]+1+d)
                    ret[:] = [max(left[0], right[0])+1, d]  # [height, dist_to_start]
            return result

        return iter_dfs(root, start)


# Time:  O(n)
# Space: O(h)
# dfs, tree dp
class Solution2(object):
    def amountOfTime(self, root, start):
        """
        :type root: Optional[TreeNode]
        :type start: int
        :rtype: int
        """
        def dfs(curr, start, result):
            if curr is None:
                return [-1, -1]
            left = dfs(curr.left, start, result)
            right = dfs(curr.right, start, result)
            d = -1
            if curr.val == start:
                d = 0
                result[0] = max(left[0], right[0])+1
            elif left[1] >= 0:
                d = left[1]+1
                result[0] = max(result[0], right[0]+1+d)
            elif right[1] >= 0:
                d = right[1]+1
                result[0] = max(result[0], left[0]+1+d)
            return [max(left[0], right[0])+1, d]  # [height, dist_to_start]

        result = [-1]
        dfs(root, start, result)
        return result[0]


# Time:  O(n)
# Space: O(n)
# bfs
class Solution3(object):
    def amountOfTime(self, root, start):
        """
        :type root: Optional[TreeNode]
        :type start: int
        :rtype: int
        """
        def bfs(root):
            adj = collections.defaultdict(list)
            q = [root]
            while q:
                new_q = []
                for u in q:
                    for v in (u.left, u.right):
                        if v is None:
                            continue
                        adj[u.val].append(v.val)
                        adj[v.val].append(u.val)
                        new_q.append(v)
                q = new_q
            return adj

        def bfs2(adj, start):
            result = -1
            q = [start]
            lookup = {start}
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if v in lookup:
                            continue
                        lookup.add(v)
                        new_q.append(v)
                q = new_q
                result += 1
            return result

        adj = bfs(root)
        return bfs2(adj, start)
