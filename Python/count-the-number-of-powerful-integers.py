# Time:  O(logf)
# Space: O(1)

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
            def length(x):
                result = 0
                while x:
                    x //= 10
                    result += 1
                return result

            result = 0
            n = length(x)
            base = 10**n
            l = n-len(s)
            cnt = (limit+1)**l
            for i in xrange(l):
                base //= 10
                curr = x//base%10
                cnt //= limit+1
                result += (min(curr-1, limit)-0+1)*cnt
                if curr > limit:
                    break
            else:
                if x%base >= int(s):
                    result += 1
            return result

        return count(finish)-count(start-1)


# Time:  O(logf)
# Space: O(logf)
# math, combinatorics
class Solution2(object):
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
            cnt = (limit+1)**l
            for i in xrange(l):
                cnt //= limit+1
                result += (min(int(str_x[i])-1, limit)-0+1)*cnt
                if int(str_x[i]) > limit:
                    break
            else:
                if int(str_x[-len(s):]) >= int(s):
                    result += 1
            return result

        return count(finish)-count(start-1)
