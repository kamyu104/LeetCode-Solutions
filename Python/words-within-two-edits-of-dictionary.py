# Time:  O(25 * l * (n + q))
# Space: O(25 * l * n)

import string


# hash
class Solution(object):
    def twoEditWords(self, queries, dictionary):
        """
        :type queries: List[str]
        :type dictionary: List[str]
        :rtype: List[str]
        """
        MOD = (1<<64)-59  # largest 64-bit prime
        BASE = 113
        POW = [1]
        def add(a, b):
            return (a+b)%MOD

        def mult(a, b):
            return (a*b)%MOD

        def pow(i):
            while not (i < len(POW)):
                POW.append(mult(POW[-1], BASE))
            return POW[i]
    
        lookup = set()
        for w in dictionary:
            h = reduce(lambda h, i: add(h, mult(ord(w[i])-ord('a'), pow(i))), xrange(len(w)), 0)
            for i, c in enumerate(w):
                for x in string.ascii_lowercase:
                    if x == c:
                        continue
                    lookup.add(add(h, mult(ord(x)-ord(c), pow(i))))
        result = []
        for w in queries:
            h = reduce(lambda h, i: add(h, mult(ord(w[i])-ord('a'), pow(i))), xrange(len(w)), 0)
            for i, c in enumerate(w):
                for x in string.ascii_lowercase:
                    if x == c:
                        continue
                    if add(h, mult(ord(x)-ord(c), pow(i))) in lookup:
                        break
                else:
                    continue
                result.append(w)
                break
        return result


# Time:  O(q * n * l)
# Space: O(1)
import itertools


# brute force
class Solution2(object):
    def twoEditWords(self, queries, dictionary):
        """
        :type queries: List[str]
        :type dictionary: List[str]
        :rtype: List[str]
        """
        return [q for q in queries if any(sum(c1 != c2 for c1, c2 in itertools.izip(q, d)) <= 2 for d in dictionary)]
