# Time:  O(logf)
# Space: O(logf)

# math, combinatorics
class Solution(object):
    def numberOfPowerfulInt(self, start, finish, limit, s):
        """
        :type start: int
        :type finish: int
        :type limit: int
        :type s: str
        :rtype: int
        """
        def count(x):
            result = 0
            str_x = str(x)
            l = len(str_x)-len(s)
            base = (limit+1)**max(l-1, 0)
            for i in xrange(l):
                result += (min(int(str_x[i])-1, limit)-0+1)*base
                if int(str_x[i]) > limit:
                    break
                base //= limit+1
            else:
                if int(str_x[-len(s):]) >= int(s):
                    result += 1
            return result

        return count(finish)-count(start-1)
