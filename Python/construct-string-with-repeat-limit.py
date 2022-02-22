# Time:  O(26 * n)
# Space: O(26)

import collections


# greedy
class Solution(object):
    def repeatLimitedString(self, s, repeatLimit):
        """
        :type s: str
        :type repeatLimit: int
        :rtype: str
        """
        cnt = collections.Counter(map(lambda x: ord(x)-ord('a'), s))
        result = []
        top1 = 25
        while True:
            top1 = next((i for i in reversed(xrange(top1+1)) if cnt[i]), -1)
            if top1 == -1:
                break
            c = min(cnt[top1], repeatLimit-int(len(result) > 0 and result[-1] == top1))
            cnt[top1] -= c
            result.extend([top1]*c)
            top2 = next((j for j in reversed(xrange(top1)) if cnt[j]), -1)
            if top2 == -1:
                break
            cnt[top2] -= 1
            result.append(top2)
        return "".join(map(lambda x: chr(x+ord('a')), result))
