# Time:  O(n^2)
# Space: O(n)

# sort, coordinate compression, freq table
class Solution(object):
    def getLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        val_to_idx = {x:i for i, x in enumerate(sorted(set(nums)))}
        arr = [val_to_idx[x] for x in nums]
        result = 0
        for left in xrange(len(arr)):
            cnt, cnt2 = [0]*len(arr), [0]*(len(arr)+1)
            distinct = total = c = 0
            for right in xrange(left, len(arr)):
                if cnt[arr[right]]:
                    cnt2[cnt[arr[right]]] -= 1
                    if cnt2[cnt[arr[right]]] == 0:
                        c -= 1
                        total -= cnt[arr[right]]
                cnt[arr[right]] += 1
                if cnt[arr[right]] == 1:
                    distinct += 1
                cnt2[cnt[arr[right]]] += 1
                if cnt2[cnt[arr[right]]] == 1:
                    total += cnt[arr[right]]
                    c += 1
                if distinct == 1 or (c == 2 and total%3 == 0 and cnt2[total//3]):
                    result = max(result, right-left+1)
        return result


# Time:  O(n^2)
# Space: O(n)
import collections


# freq table
class Solution2(object):
    def getLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for left in xrange(len(nums)):
            cnt, cnt2 = collections.defaultdict(int), collections.defaultdict(int)
            distinct = total = c = 0
            for right in xrange(left, len(nums)):
                if cnt[nums[right]]:
                    cnt2[cnt[nums[right]]] -= 1
                    if cnt2[cnt[nums[right]]] == 0:
                        c -= 1
                        total -= cnt[nums[right]]
                cnt[nums[right]] += 1
                if cnt[nums[right]] == 1:
                    distinct += 1
                cnt2[cnt[nums[right]]] += 1
                if cnt2[cnt[nums[right]]] == 1:
                    total += cnt[nums[right]]
                    c += 1
                if distinct == 1 or (c == 2 and total%3 == 0 and cnt2[total//3]):
                    result = max(result, right-left+1)
        return result
