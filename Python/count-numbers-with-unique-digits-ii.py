# Time:  O(blogb)
# Space: O(1)

# hash table
class Solution(object):
    def numberCount(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        def check(x):
            lookup = 0
            while x:
                if lookup&(1<<(x%10)):
                    return False
                lookup |= (1<<(x%10))
                x //= 10
            return True

        return sum(check(x) for x in xrange(a, b+1))


# Time:  O(blogb)
# Space: O(logb)
# hash table
class Solution2(object):
    def numberCount(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        return sum(len(set(str(x))) == len(str(x)) for x in xrange(a, b+1))
