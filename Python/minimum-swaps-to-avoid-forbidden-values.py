# Time:  O(n)
# Space: O(1)

# boyer-moore majority vote algorithm, greedy
class Solution(object):
    def minSwaps(self, nums, forbidden):
        """
        :type nums: List[int]
        :type forbidden: List[int]
        :rtype: int
        """
        def boyer_moore_majority_vote(arr):
            result, cnt = None, 0
            for x in arr:
                if not cnt:
                    result = x
                if x == result:
                    cnt += 1
                else:
                    cnt -= 1
            return result

        m = boyer_moore_majority_vote((nums[i] for i in xrange(len(nums)) if nums[i] == forbidden[i]))
        cnt = cnt_m = bal = 0
        for i in xrange(len(nums)):
            if nums[i] != forbidden[i]:
                if nums[i] != m != forbidden[i]:
                    bal += 1
                continue
            cnt += 1
            if nums[i] != m:
                bal += 1
            else:
                bal -= 1
                cnt_m += 1
        return max(cnt_m, (cnt+1)//2) if bal >= 0 else -1


# Time:  O(n)
# Space: O(n)
import collections


# freq table, greedy
class Solution2(object):
    def minSwaps(self, nums, forbidden):
        """
        :type nums: List[int]
        :type forbidden: List[int]
        :rtype: int
        """
        cnt1 = collections.defaultdict(int)
        for x in nums:
            cnt1[x] += 1
        cnt2 = collections.defaultdict(int)
        for x in forbidden:
            cnt2[x] += 1
        if any(cnt1[k]+cnt2[k] > len(nums) for k in cnt1.iterkeys()):
            return -1
        cnt3 = collections.defaultdict(int)
        cnt = cnt_m = 0
        for i in xrange(len(nums)):
            if nums[i] != forbidden[i]:
                continue
            cnt += 1
            cnt3[nums[i]] += 1
            cnt_m = max(cnt_m, cnt3[nums[i]])
        return max(cnt_m, (cnt+1)//2)
