# Time:  O(100 * n^2) = O(n^2)
# Space: O(1)

class Solution(object):
    def findLexSmallestString(self, s, a, b):
        """
        :type s: str
        :type a: int
        :type b: int
        :rtype: str
        """
        def less(s, i, j):
            for k in xrange(len(s)):
                if s[(k+i)%len(s)] != s[(k+j)%len(s)]:
                    return s[(k+i)%len(s)] < s[(k+j)%len(s)]
            return False

        s = list(s)
        result = s[:]
        even = [False]*10
        while not even[int(s[0])]:  # at most O(10) times
            even[int(s[0])] = True
            odd = [False]*10
            while not odd[int(s[1])]:  # at most O(10) times
                odd[int(s[1])] = True
                best_rotate = 0
                lookup = [False]*len(s)
                i = b
                while not lookup[i]:  # find best rotation, at most O(n) times
                    lookup[i] = True
                    if less(s, i, best_rotate):  # O(n) time
                        best_rotate = i
                    i = (i+b)%len(s)
                result = min(result, s[best_rotate:] + s[:best_rotate])
                for k in xrange(1, len(s), 2):  # flip odd index
                    s[k] = str((int(s[k])+a) % 10)
            if b%2:  # if rotate length is odd, even index could be also flipped
                for k in xrange(0, len(s), 2):  # flip even index
                    s[k] = str((int(s[k])+a) % 10)
        return "".join(result)


# Time:  O(100 * n^2), at most O(100n) strings and each compare costs O(n)
# Space: O(n^2)
import collections


class Solution2(object):
    def findLexSmallestString(self, s, a, b):
        """
        :type s: str
        :type a: int
        :type b: int
        :rtype: str
        """
        q, lookup, result = collections.deque([s]), {s}, s
        while q:
            curr = q.popleft()
            if curr < result:
                result = curr
            add_a = list(curr)    
            for i, c in enumerate(add_a):
                if i%2:
                    add_a[i] = str((int(c)+a) % 10)
            add_a = "".join(add_a)        
            if add_a not in lookup:
                lookup.add(add_a);
                q.append(add_a)
            rotate_b = curr[b:] + curr[:b]
            if rotate_b not in lookup:
                lookup.add(rotate_b)
                q.append(rotate_b)
        return result
