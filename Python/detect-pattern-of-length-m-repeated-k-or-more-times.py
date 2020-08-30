# Time:  O(n)
# Space: O(1)

class Solution(object):
    def containsPattern(self, arr, m, k):
        """
        :type arr: List[int]
        :type m: int
        :type k: int
        :rtype: bool
        """
        cnt = 0
        for i in xrange(len(arr)-m):
            if arr[i] != arr[i+m]:
                cnt = 0
                continue
            cnt += 1
            if cnt == (k-1)*m:
                return True
        return False
