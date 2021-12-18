# Time:  O(n)
# Space: O(n)

class Solution(object):
    def maxTotalFruits(self, fruits, startPos, k):
        """
        :type fruits: List[List[int]]
        :type startPos: int
        :type k: int
        :rtype: int
        """
        max_pos = max(startPos, fruits[-1][0])
        cnt = [0]*(1+max_pos)
        for p, a in fruits:
            cnt[p] = a
        prefix = [0]
        for x in cnt:
            prefix.append(prefix[-1]+x)
        result = 0
        for left_dist in xrange(min(startPos, k)+1):
            right_dist = max(k-2*left_dist, 0)            
            left, right = startPos-left_dist, min(startPos+right_dist, max_pos)
            result = max(result, prefix[right+1]-prefix[left])
        for right_dist in xrange(min(max_pos-startPos, k)+1):
            left_dist = max(k-2*right_dist, 0) 
            left, right = max(startPos-left_dist, 0), startPos+right_dist
            result = max(result, prefix[right+1]-prefix[left])
        return result
