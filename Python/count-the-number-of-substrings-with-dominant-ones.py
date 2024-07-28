# Time:  O(n * sqrt(n)) = O(n^(3/2))
# Space: O(n)

# two pointers, sliding window
class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        idxs = [-1]+[i for i, x in enumerate(s) if x == '0']+[len(s)]
        for c in xrange(int(len(s)**0.5)+1):
            cnt = 0
            left = right = 1
            for i in xrange(len(s)):
                if idxs[right] == i:
                    right += 1
                else:
                    cnt += 1
                if right-left == c+1:
                    cnt -= (idxs[left]-1)-idxs[left-1]
                    left += 1
                if not (right-left == c and cnt >= c**2):
                    continue     
                result += min((idxs[left] if c else i)-idxs[left-1], cnt-c**2+1)
        return result


# Time:  O(n * sqrt(n)) = O(n^(3/2))
# Space: O(1)
# two pointers, sliding window
class Solution_TLE(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        for c in xrange(int(len(s)**0.5)+1):
            cnt = [0]*2
            left = prev = 0
            for right in xrange(len(s)):
                cnt[s[right] == '1'] += 1
                while cnt[0] == c+1:
                    cnt[s[left] == '1'] -= 1
                    left += 1
                if not (cnt[0] == c and cnt[1] >= c**2):
                    continue
                for prev in xrange(max(prev, left), right):
                    if s[prev] == '0':
                        break
                else:
                    prev = right
                result += min(prev-left+1, cnt[1]-c**2+1)
        return result
