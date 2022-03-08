# Time:  O(nlogn)
# Space: O(n)

# greedy
class Solution(object):
    def minimalKSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = k*(k+1)//2
        curr = k+1
        for x in sorted(set(nums)):
            if x < curr:
                result += curr-x
                curr += 1
        return result


# Time:  O(nlogn)
# Space: O(n)
# greedy
class Solution2(object):
    def minimalKSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = prev = 0
        nums.append(float("inf"))
        for x in sorted(set(nums)):
            if not k:
                break
            cnt = min((x-1)-prev, k)
            k -= cnt
            result += ((prev+1)+(prev+cnt))*cnt//2
            prev = x
        return result
