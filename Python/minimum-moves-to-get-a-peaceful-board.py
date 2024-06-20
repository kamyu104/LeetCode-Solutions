# Time:  O(n)
# Space: O(n)
# greedy, prefix sum

class Solution(object):
    def minMoves(self, rooks):
        """
        :type rooks: List[List[int]]
        :rtype: int
        """
        def count(cnt):
            result = prefix = 0
            for i in xrange(len(rooks)):
                prefix += cnt[i]
                result += abs(prefix-(i+1))
            return result

        cnt1 = [0]*len(rooks)
        cnt2 = [0]*len(rooks)
        for r, c in rooks:
            cnt1[r] += 1
            cnt2[c] += 1
        return count(cnt1)+count(cnt2)
    
