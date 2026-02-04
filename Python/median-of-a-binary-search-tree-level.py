# Time:  O(n)
# Space: O(n)

# bfs
class Solution(object):
    def levelMedian(self, root, level):
        """
        :type root: Optional[TreeNode]
        :type level: int
        :rtype: int
        """
        def bfs(root, level):
            q = [root]
            d = 0
            while q:
                if d == level:
                    return q
                new_q = []
                for u in q:
                    if u.left:
                        new_q.append(u.left)
                    if u.right:
                        new_q.append(u.right)
                q = new_q
                d += 1
            return []
    
        arr = bfs(root, level)
        return arr[len(arr)//2].val if arr else -1
