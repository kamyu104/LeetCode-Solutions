# Time:  O(n)
# Space: O(n)

# line sweep
class Solution(object):
    def meetRequirement(self, n, lights, requirement):
        """
        :type n: int
        :type lights: List[List[int]]
        :type requirement: List[int]
        :rtype: int
        """
        cnt = [0]*(n+1)
        for p, r in lights:
            cnt[max(p-r, 0)] += 1
            cnt[min(p+r, n-1)+1] -= 1
        result = curr = 0
        for i, r in enumerate(requirement):
            curr += cnt[i]
            if curr >= r:
                result += 1
        return result
