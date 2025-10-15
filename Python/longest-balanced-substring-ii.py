# Time:  O(n)
# Space: O(n)

import collections


# hash table, prefix sum
class Solution(object):
    def longestBalanced(self, s):
        """
        :type s: str
        :rtype: int
        """
        def count1():
            result = cnt = 0
            for i in xrange(len(s)):
                cnt += 1
                if i+1 == len(s) or s[i+1] != s[i]:
                    result = max(result, cnt)
                    cnt = 0
            return result

        def count2(a, b):
            result = cnt = 0
            lookup = collections.defaultdict(int, {cnt:-1})
            for i, x in enumerate(s):
                if x == a:
                    cnt += 1
                elif x == b:
                    cnt -= 1
                else:
                    cnt = 0
                    lookup = collections.defaultdict(int, {cnt:i})
                    continue
                if cnt in lookup:
                    result = max(result, i-lookup[cnt])
                else:
                    lookup[cnt] = i
            return result
    
        def count3():
            result = a = b = 0
            lookup = collections.defaultdict(int, {(a, b):-1})
            for i, x in enumerate(s):
                if x == 'a':
                    a += 1
                elif x == 'b':
                    b += 1
                else:
                    a -= 1
                    b -= 1
                if (a, b) in lookup:
                    result = max(result, i-lookup[a, b])
                else:
                    lookup[a, b] = i
            return result
        
        return max(count1(), 
                   count2('a', 'b'), count2('b', 'c'), count2('c', 'a'),
                   count3())
