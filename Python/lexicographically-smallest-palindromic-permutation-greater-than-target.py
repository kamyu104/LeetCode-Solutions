# Time:  O(26 * n)
# Space: O(26)

# freq table, greedy
class Solution(object):
    def lexPalindromicPermutation(self, s, target):
        """
        :type s: str
        :type target: str
        :rtype: str
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        if sum(c%2 for c in cnt) > 1:
            return ""
        x = -1
        if len(target)%2:
            x = next(x for x, c in enumerate(cnt) if c%2)
            cnt[x] -= 1
        result = []
        for i in xrange(len(target)//2):
            cnt[ord(target[i])-ord('a')] -= 2
            result.append(target[i])
            if cnt[ord(target[i])-ord('a')] < 0:
                break
        else:
            if len(target)%2:
                result.append(chr(ord('a')+x))
            ret = "".join(result)
            ret += ret[:len(target)//2][::-1]
            if ret > target:
                return ret
            if len(target)%2:
                result.pop()
        while result:
            c = ord(result.pop())-ord('a')
            cnt[c] += 2
            for i in xrange(c+1, len(cnt)):
                if not cnt[i]:
                    continue
                cnt[i] -= 2
                result.append(chr(ord('a')+i))
                for j in xrange(len(cnt)):
                    if not cnt[j]:
                        continue
                    while cnt[j]:
                        cnt[j] -= 2
                        result.append(chr(ord('a')+j))
                if len(target)%2:
                    result.append(chr(ord('a')+x))
                ret = "".join(result)
                ret += ret[:len(target)//2][::-1]
                return ret
        return ""
