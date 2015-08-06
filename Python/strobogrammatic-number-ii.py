# Time:  O(n^2 * 5^(n/2))
# Space: O(n)

class Solution:
    lookup = {'0':'0', '1':'1', '6':'9', '8':'8', '9':'6'}

    # @param {integer} n
    # @return {string[]}
    def findStrobogrammatic(self, n):
        return self.findStrobogrammaticRecu(n, n)

    def findStrobogrammaticRecu(self, n, k):
        if k == 0:
            return ['']
        elif k == 1:
            return ['0', '1', '8']
        
        result = []
        for num in self.findStrobogrammaticRecu(n, k - 2):
            for key, val in self.lookup.iteritems():
                if n != k or key != '0':
                    result.append(key + num + val)

        return result
