# Time:  O(m + n)
# Space: O(1)

class Solution(object):
    def findRLEArray(self, encoded1, encoded2):
        """
        :type encoded1: List[List[int]]
        :type encoded2: List[List[int]]
        :rtype: List[List[int]]
        """
        result = []
        i = j = remain1 = remain2 = 0
        while (remain1 or i < len(encoded1)) and (remain2 or j < len(encoded2)):
            if not remain1:
                remain1 = encoded1[i][1]
                i += 1
            if not remain2:
                remain2 = encoded2[j][1]
                j += 1
            cnt = min(remain1, remain2)
            remain1 -= cnt
            remain2 -= cnt
            if result and result[-1][0] == encoded1[i-1][0]*encoded2[j-1][0]:
                result[-1][1] += cnt
            else:
                result.append([encoded1[i-1][0]*encoded2[j-1][0], cnt])
        return result
