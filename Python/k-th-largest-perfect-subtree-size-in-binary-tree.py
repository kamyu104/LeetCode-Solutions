# Time:  O(n)
# Space: O(n)

import random


# iterative dfs, quick select
class Solution(object):
    def kthLargestPerfectSubtree(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        def nth_element(nums, left, n, right, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target):
                i = left
                while i <= right:
                    if compare(nums[i], target):
                        nums[i], nums[left] = nums[left], nums[i]
                        left += 1
                        i += 1
                    elif compare(target, nums[i]):
                        nums[i], nums[right] = nums[right], nums[i]
                        right -= 1
                    else:
                        i += 1
                return left, right

            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx])
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        def iter_dfs():
            result = []
            stk = [(1, (root, [0]))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    curr, ret = args
                    if not curr:
                        ret[0] = 0
                        result.append(ret[0])
                        continue
                    new_ret = [[0] for _ in xrange(2)]
                    stk.append((2, (curr, new_ret, ret)))
                    stk.append((1, (curr.right, new_ret[1])))
                    stk.append((1, (curr.left, new_ret[0])))
                elif step == 2:
                    curr, new_ret, ret = args
                    ret[0] = new_ret[0][0]+new_ret[1][0]+1 if new_ret[0][0] == new_ret[1][0] != -1 else -1
                    result.append(ret[0])
            return result
                        
        result = iter_dfs()
        nth_element(result, 0, k-1, len(result)-1, lambda a, b: a > b)
        return result[k-1] if k-1 < len(result) and result[k-1] > 0 else -1


# Time:  O(n)
# Space: O(n)
import random


# dfs, quick select
class Solution2(object):
    def kthLargestPerfectSubtree(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        def nth_element(nums, left, n, right, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target):
                i = left
                while i <= right:
                    if compare(nums[i], target):
                        nums[i], nums[left] = nums[left], nums[i]
                        left += 1
                        i += 1
                    elif compare(target, nums[i]):
                        nums[i], nums[right] = nums[right], nums[i]
                        right -= 1
                    else:
                        i += 1
                return left, right

            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx])
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        def dfs(curr):
            if not curr:
                result.append(0)
                return
            dfs(curr.left)
            left = result[-1]
            dfs(curr.right)
            right = result[-1]
            result.append(left+right+1 if left == right != -1 else -1)

        result = []
        dfs(root)
        nth_element(result, 0, k-1, len(result)-1, lambda a, b: a > b)
        return result[k-1] if k-1 < len(result) and result[k-1] > 0 else -1
