# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def reformat(self, s):
        """
        :type s: str
        :rtype: str
        """
        def char_gen(start, end, count):
            for c in xrange(ord(start), ord(end)+1):
                c = chr(c)
                for i in xrange(count[c]):
                    yield c
            yield ''
    
        count = collections.defaultdict(int)
        alpha_cnt = 0
        for c in s:
            count[c] += 1
            if c.isalpha():
                alpha_cnt += 1
        if abs(len(s)-2*alpha_cnt) > 1:
            return ""

        result = []
        it1, it2 = char_gen('a', 'z', count), char_gen('0', '9', count)
        if alpha_cnt < len(s)-alpha_cnt:
            it1, it2 = it2, it1
        while len(result) < len(s):
            result.append(next(it1))
            result.append(next(it2))
        return "".join(result)
