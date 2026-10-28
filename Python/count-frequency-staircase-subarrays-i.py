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


# Time:  O(n^2)
# Space: O(n)
# brute force, freq table, hash table
class Solution2(object):
    def countStaircase(self, nums):
        result = 0
        for left in xrange(len(nums)):
            cnt, rank, d, bal = {}, {}, 0, 0
            for right in xrange(left, len(nums)):
                if nums[right] not in cnt:
                    d += 1
                    rank[nums[right]] = d
                    cnt[nums[right]] = 1
                    bal += d-1
                else:
                    cnt[nums[right]] += 1
                    bal -= 1
                    if cnt[nums[right]] > rank[nums[right]]:
                        break
                if bal == 0:
                    result += 1
        return result
