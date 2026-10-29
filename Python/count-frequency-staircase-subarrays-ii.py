# Time:  O(n * sqrt(n))
# Space: O(n)

# hash table
class Solution(object):
    def countStaircase(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, lookup = 0, collections.defaultdict(list)
        for left in reversed(xrange(len(nums))):
            lookup[nums[left]].append(left)
            right, d, l, r = left, 0, -1, len(nums)
            while right < r and l <= r:  # each right is visited by O(sqrt(n)) lefts
                idxs = lookup[nums[right]]
                if idxs[-1] == right:
                    d += 1
                    if len(idxs) < d:
                        break
                    if len(idxs) >= d+1:
                        r = min(r, idxs[-1-d])
                    l = max(l, idxs[-d])
                result += l <= right
                right += 1
        return result
