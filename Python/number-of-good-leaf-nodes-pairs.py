# Time:  O(n)
# Space: O(h)

import collections


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def countPairs(self, root, distance):
        """
        :type root: TreeNode
        :type distance: int
        :rtype: int
        """
        def iter_dfs(distance, root):
            result = 0
            stk = [(1, (root, [collections.Counter()]))]
            while stk:
                step, params = stk.pop()
                if step == 1:
                    node, ret = params
                    if not node:
                        continue
                    if not node.left and not node.right:
                        ret[0][0] = 1
                        continue
                    left, right = [collections.Counter()], [collections.Counter()]
                    stk.append((2, (left, right, ret)))
                    stk.append((1, (node.right, right)))
                    stk.append((1, (node.left, left)))
                else:
                    left, right, ret = params
                    for left_d, left_c in left[0].iteritems():
                        for right_d,right_c in right[0].iteritems():
                            if left_d+right_d+2 <= distance:
                                result += left_c*right_c
                    ret[0] = collections.Counter({k+1:v for k,v in (left[0]+right[0]).iteritems()})
            return result
        
        return iter_dfs(distance, root)


# Time:  O(n)
# Space: O(h)
import collections


class Solution2(object):
    def countPairs(self, root, distance):
        """
        :type root: TreeNode
        :type distance: int
        :rtype: int
        """
        def dfs(distance, node):
            if not node:
                return 0, collections.Counter()
            if not node.left and not node.right:
                return 0, collections.Counter([0])
            left, right = dfs(distance, node.left), dfs(distance, node.right)
            result = left[0]+right[0]
            for left_d, left_c in left[1].iteritems():
                for right_d,right_c in right[1].iteritems():
                    if left_d+right_d+2 <= distance:
                        result += left_c*right_c
            return result, collections.Counter({k+1:v for k,v in (left[1]+right[1]).iteritems()})
        
        return dfs(distance, root)[0]
