# Time:  O(nlogn)
# Space: O(n)

# hash table
class Solution(object):
    def longestSquareStreak(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sorted_nums = sorted(set(nums))
        squares = {x for x in sorted_nums if x%2 < 2}  # squared_num % 4 in [0, 1] 
        result = 0
        for x in sorted_nums:
            square, cnt = x**2, 1
            while square in squares:
                squares.remove(square)
                cnt += 1
                square *= square
            result = max(result, cnt)
        return result if result != 1 else -1


# Time:  O(nlogn)
# Space: O(n)
# dp
class Solution2(object):
    def longestSquareStreak(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = collections.defaultdict(int)
        nums.sort()
        result = -1
        for x in nums:
            sqrt_x = int(x**0.5)
            if sqrt_x**2 == x:
                dp[x] = dp[sqrt_x]+1
            else:
                dp[x] = 1
            result = max(result, dp[x])
        return result if result != 1 else -1
