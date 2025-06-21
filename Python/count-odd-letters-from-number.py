# Time:  O(logn)
# Space: O(26)

# freq table
class Solution(object):
    def countOddLetters(self, n):
        """
        :type n: int
        :rtype: int
        """
        lookup = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
        cnt = [0]*26
        while n:
            n, d = divmod(n, 10)
            for x in lookup[d]:
                cnt[ord(x)-ord('a')] += 1
        return sum(v%2 for v in cnt)
