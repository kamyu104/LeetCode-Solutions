# Time:  O(n + 26)
# Space: O(26)

# counting sort, greedy
class Solution(object):
    def makeAntiPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        if max(cnt) > len(s)//2:
            return "-1"
        result = [i for i, x in enumerate(cnt) for _ in xrange(x)]
        l = next(l for l in xrange((len(s)//2)//2+1) if result[len(s)//2+l] != result[len(s)//2-1])
        if l:
            for i in xrange(cnt[result[len(s)//2-1]]-l):
                result[len(s)//2+i], result[len(s)//2+i+l] = result[len(s)//2+i+l], result[len(s)//2+i]
        return "".join(map(lambda x: chr(ord('a')+x), result))


# Time:  O(n + 26)
# Space: O(26)
# counting sort, greedy, two pointers
class Solution2(object):
    def makeAntiPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        if max(cnt) > len(s)//2:
            return "-1"
        result = [i for i, x in enumerate(cnt) for _ in xrange(x)]
        left = len(s)//2
        right = left+1
        while right < len(s) and result[right] == result[left]:
            right += 1 
        while result[left] == result[len(s)-1-left]:
            result[left] , result[right] = result[right], result[left]
            left += 1
            right += 1
        return "".join(map(lambda x: chr(ord('a')+x), result))
    

# Time:  O(n * 26)
# Space: O(26)
# freq table, greedy
class Solution3(object):
    def makeAntiPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        if max(cnt) > len(s)//2:
            return "-1"
        result = [-1]*len(s)
        for i in xrange(len(s)//2):
            j = next(j for j in xrange(len(cnt)) if cnt[j])
            cnt[j] -= 1
            result[i] = j
        for i in xrange(len(s)//2, len(s)):
            j = next(j for j in xrange(len(cnt)) if cnt[j] and result[(len(s)-1)-i] != j)
            cnt[j] -= 1
            result[i] = j
        return "".join(map(lambda x: chr(ord('a')+x), result))
