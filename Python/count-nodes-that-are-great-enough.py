# Time:  O(k * h)
# Space: O(k + h)

import bisect


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


# merge sort
class Solution(object):
    def countGreatEnoughNodes(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        def merge_at_most_k(a, b):
            result = []
            i = j = 0
            while i < len(a) or j < len(b):
                if j == len(b) or (i < len(a) and a[i] < b[j]):
                    result.append(a[i])
                    i += 1
                else:
                    result.append(b[j])
                    j += 1
                if len(result) == k:
                    break
            return result

        def merge_sort(node):
            if not node:
                return []
            left, right = merge_sort(node.left), merge_sort(node.right)
            smallest_k = merge_at_most_k(left, right)
            i = bisect.bisect_left(smallest_k, node.val)
            if i == k:
                result[0] += 1
            else:
                smallest_k.insert(i, node.val)
                if len(smallest_k) == k+1:
                    smallest_k.pop()
            return smallest_k

        result = [0]
        merge_sort(root)
        return result[0]
