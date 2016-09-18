# Time:  O(n)
# Space: O(n)

# A frog is crossing a river. The river is divided into x units and
# at each unit there may or may not exist a stone. 
# The frog can jump on a stone, but it must not jump into the water.
#
# Given a list of stones' positions (in units) in sorted ascending order,
# determine if the frog is able to cross the river by landing on the last stone.
# Initially, the frog is on the first stone and assume the first jump must be 1 unit.
#
# If the frog has just jumped k units, then its next jump must be
# either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.
#
# Note:
#
# The number of stones is >= 2 and is < 1,100.
# Each stone's position will be a non-negative integer < 231.
# The first stone's position is always 0.
# Example 1:
#
# [0,1,3,5,6,8,12,17]
#
# There are a total of 8 stones.
# The first stone at the 0th unit, second stone at the 1st unit,
# third stone at the 3rd unit, and so on...
# The last stone at the 17th unit.
#
# Return true. The frog can jump to the last stone by jumping 
# 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
# 2 units to the 4th stone, then 3 units to the 6th stone, 
# 4 units to the 7th stone, and 5 units to the 8th stone.
# Example 2:
#
# [0,1,2,3,4,8,9,11]
#
# Return false. There is no way to jump to the last stone as 
# the gap between the 5th and 6th stone is too large.

# DP with hash table
class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        def findStones(stones, lookup, i):
            result = []
            if i == 0:
                if stones[1] == stones[0] + 1:
                    result.append(1)
            else:
                for k in (i-1, i, i+1):
                    if stones[i] + k in lookup:
                        result.append(lookup[stones[i] + k])
            return result

        lookup = {}
        for i in xrange(len(stones)):
            lookup[stones[i]] = i

        dp = [False for _ in xrange(len(stones))]
        dp[0] = True
        for i in xrange(len(stones)-1):
            if dp[i]:
                for j in findStones(stones, lookup, i):
                    dp[j] = True
        return dp[-1]


# Time:  O(nlogn)
# Space: O(n)
# DP with binary search
class Solution2(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        def findStones(stones, i):
            result = []
            if i == 0:
                if stones[1] == 1:
                    result.append(1)
            else:
                for k in (i-1, i, i+1):
                    j = bisect.bisect_left(stones, stones[i] + k)
                    if j != len(stones) and stones[j] == stones[i] + k:
                        result.append(j)
            return result
            
        dp = [False for _ in xrange(len(stones))]
        dp[0] = True
        for i in xrange(len(stones)-1):
            if dp[i]:
                for j in findStones(stones, i):
                    dp[j] = True
        return dp[-1]


# Time:  O(n^2)
# Space: O(n)
class Solution3(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        dp = [False for _ in xrange(len(stones))]
        dp[0] = True

        for i in xrange(1, len(stones)):
            for j in reversed(xrange(i)):
                if stones[i] - stones[j] > j + 1:
                    break
                if dp[j] and ((stones[i] - stones[j]) in ([j-1, j, j+1] if i != 1 else [1])):
                    dp[i] = True
                    break

        return dp[-1]
