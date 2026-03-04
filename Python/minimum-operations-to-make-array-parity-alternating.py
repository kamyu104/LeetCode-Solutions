# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def makeParityAlternating(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        POS_INF = float("inf")
        NEG_INF = float("-inf")
        def count(target):
            cnt = 0
            mn, mx = POS_INF, NEG_INF
            for i, x in enumerate(nums):
                if (x%2) == (i%2)^target:
                    mn = min(mn, x)
                    mx = max(mx, x)
                else:
                    cnt += 1
                    mn = min(mn, x+1)
                    mx = max(mx, x-1)
            return (cnt, 0 if len(nums) == 1 else 1 if max(nums) == min(nums) else mx-mn)
        
        return min(count(0), count(1))


# Time:  O(n)
# Space: O(1)
# greedy
class Solution2(object):
    def makeParityAlternating(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        POS_INF = float("inf")
        NEG_INF = float("-inf")
        def count(target):
            cnt = 0
            mn, mx = min(nums), max(nums)
            mn2, mx2 = POS_INF, NEG_INF
            for i, x in enumerate(nums):
                if (x%2) == (i%2)^target:
                    mn2 = min(mn2, x)
                    mx2 = max(mx2, x)
                else:
                    cnt += 1
                    if x == mn:
                        mn2 = min(mn2, x+1)
                        mx2 = max(mx2, x+1)
                    elif x == mx:
                        mn2 = min(mn2, x-1)
                        mx2 = max(mx2, x-1)
            return (cnt, mx2-mn2)
        
        return min(count(0), count(1))
