# Time:  O(min(t / c1, c2 / g), c1 = max(cost1, cost2)
#                             , c2 = min(cost1, cost2)
#                             ,  g = gcd(c1, c2)
# Space: O(1)

# math
class Solution(object):
    def waysToBuyPensPencils(self, total, cost1, cost2):
        """
        :type total: int
        :type cost1: int
        :type cost2: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        if cost1 < cost2:
            cost1, cost2 = cost2, cost1
        lcm = cost1*cost2//gcd(cost1, cost2)
        result = 0
        for x in reversed(xrange(total-lcm+cost1, total+1, cost1)):
            if x < 0:
                break
            # total, cost1, cost2 = 120, 7, 5
            # => arithmetic progressions of cnts are as follows
            #      ----- l -----  x
            #  |   24, 17, 10, 3 120
            #  |   22, 15,  8, 1 113
            # cnt  21, 14,  7,   106
            #  |   19, 12,  5,    99
            #  |   18, 11,  4,    92
            cnt = x//cost2+1
            l = (cnt+(lcm//cost2)-1)//(lcm//cost2)
            result += (cnt+(cnt-(l-1)*(lcm//cost2)))*l//2
        return result


# Time:  O(t / c1), c1 = max(cost1, cost2)
#                 , c2 = min(cost1, cost2)
# Space: O(1)
# math
class Solution2(object):
    def waysToBuyPensPencils(self, total, cost1, cost2):
        """
        :type total: int
        :type cost1: int
        :type cost2: int
        :rtype: int
        """
        if cost1 < cost2:
            cost1, cost2 = cost2, cost1
        return sum((total-i*cost1)//cost2+1 for i in xrange(total//cost1+1))
