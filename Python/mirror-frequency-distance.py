# Time:  O(n + 36)
# Space: O(36)

# freq table
class Solution(object):
    def mirrorFrequency(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        cnt1, cnt2 = [0]*10, [0]*26
        for x in s:
            if x.isdigit():
                cnt1[ord(x)-ord('0')] += 1
            else:
                cnt2[ord(x)-ord('a')] += 1
        return sum(abs(cnt1[i]-cnt1[~i]) for i in xrange(len(cnt1)//2))+sum(abs(cnt2[i]-cnt2[~i]) for i in xrange(len(cnt2)//2))
