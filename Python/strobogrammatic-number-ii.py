# Time:  O(n * 5^(n/2))
# Space: O(n)

class Solution(object):
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        lookup = {'0':'0', '1':'1', '6':'9', '8':'8', '9':'6'}
        result = ['0', '1', '8'] if n%2 else ['']
        for i in xrange(n%2, n, 2):
            result = [a + num + b for a, b in lookup.iteritems() if i != n-2 or a != '0' for num in result]
        return result


# Time:  O(n * 5^(n/2))
# Space: O(n)
class Solution2(object):
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        lookup = {'0':'0', '1':'1', '6':'9', '8':'8', '9':'6'}
        def findStrobogrammaticRecu(n, k):
            if k == 0:
                return ['']
            elif k == 1:
                return ['0', '1', '8']
            result = []
            for num in findStrobogrammaticRecu(n, k - 2):
                for key, val in lookup.iteritems():
                    if n != k or key != '0':
                        result.append(key + num + val)
            return result

        return findStrobogrammaticRecu(n, n)

