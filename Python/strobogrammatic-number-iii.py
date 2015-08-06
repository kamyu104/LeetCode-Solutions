# Time:  O(5^(n/2))
# Space: O(n)

class Solution:
    lookup = {'0':'0', '1':'1', '6':'9', '8':'8', '9':'6'}

    # @param {string} low
    # @param {string} high
    # @return {integer}
    def strobogrammaticInRange(self, low, high):
        count = self.countStrobogrammaticUntil(high, False) - \
                self.countStrobogrammaticUntil(low, False) + \
                self.isStrobogrammatic(low)
        return count if count >= 0 else 0

    def countStrobogrammaticUntil(self, num,  canStartWith0):
        count = 0
        if len(num) == 1:
            for c in ['0', '1', '8']:
                if num[0] >= c:
                    count += 1
            return count
        
        for key, val in self.lookup.iteritems():
            if canStartWith0 or key != '0':
                if num[0] > key:
                    if len(num) == 2:  # num is like "21"
                        count += 1
                    else:  # num is like "201"
                        count += self.countStrobogrammaticUntil('9' * (len(num) - 2), True)
                elif num[0] == key:
                    if len(num) == 2:  # num is like 12".
                        if num[-1] >= val:
                            count += 1 
                    else:
                        if num[-1] >= val:  # num is like "102".
                            count += self.countStrobogrammaticUntil(self.getMid(num), True);
                        elif (self.getMid(num) != '0' * (len(num) - 2)):  # num is like "110".
                            count += self.countStrobogrammaticUntil(self.getMid(num), True) - \
                                     self.isStrobogrammatic(self.getMid(num))

        if not canStartWith0: # Sum up each length.
            for i in xrange(len(num) - 1, 0, -1):
                count += self.countStrobogrammaticByLength(i)

        return count

    def getMid(self, num):
        return num[1:len(num) - 1]

    def countStrobogrammaticByLength(self, n):
        if n == 1:
            return 3
        elif n == 2:
            return 4
        elif n == 3:
            return 4 * 3
        else:
            return 5 * self.countStrobogrammaticByLength(n - 2)

    def isStrobogrammatic(self, num):
        n = len(num)
        for i in xrange((n+1) / 2):
            if num[n-1-i] not in self.lookup or \
               num[i] != self.lookup[num[n-1-i]]:
                return False
        return True
