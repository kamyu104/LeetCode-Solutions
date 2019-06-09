# Time:  O(n^2)
# Space: O(n)

import collections


class Solution(object):
    def numTilePossibilities(self, tiles):
        """
        :type tiles: str
        :rtype: int
        """
        fact = [0.0]*(len(tiles)+1)
        fact[0] = 1.0;
        for i in xrange(1, len(tiles)+1):
            fact[i] = fact[i-1]*i
        count = collections.Counter(tiles)

        # 1. we can represent each alphabet 1..26 as generating functions:
        #    G1(x) = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^count1/count1!
        #    G2(x) = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^count2/count2!
        #    ...
        #    G26(x) = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^count26/count26!
        #
        # 2. let G1(x)*G2(x)*...*G26(x) = c0 + c1*x1 + ... + ck*x^k, k is the max number s.t. ck != 0
        #    => ci (1 <= i <= k) is the number we need to divide when permuting i letters
        #    => the answer will be : c1*1! + c2*2! + ... + ck*k!
        
        coeff = [0.0]*(len(tiles)+1)
        coeff[0] = 1.0
        for i in count.itervalues():
            new_coeff = [0.0]*(len(tiles)+1)
            for j in xrange(len(coeff)):
                for k in xrange(i+1):
                    if k+j >= len(new_coeff):
                        break
                    new_coeff[j+k] += coeff[j]*1.0/fact[k]
            coeff = new_coeff

        result = 0
        for i in xrange(1, len(coeff)):
            result += int(round(coeff[i]*fact[i]))
        return result


# Time:  O(r), r is the value of result
# Space: O(n)
class Solution2(object):
    def numTilePossibilities(self, tiles):
        """
        :type tiles: str
        :rtype: int
        """
        def backtracking(counter):
            total = 0
            for k, v in counter.iteritems():
                if not v:
                    continue
                counter[k] -= 1
                total += 1+backtracking(counter)
                counter[k] += 1
            return total

        return backtracking(collections.Counter(tiles))
