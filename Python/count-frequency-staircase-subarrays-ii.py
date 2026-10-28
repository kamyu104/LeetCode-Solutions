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
                pos = lookup[nums[right]]
                if pos[-1] == right:
                    d += 1
                    if len(pos) < d:
                        break
                    if len(pos) >= d+1:
                        r = min(r, pos[-1-d])
                    l = max(l, pos[-d])
                result += l <= right
                right += 1
        return result
