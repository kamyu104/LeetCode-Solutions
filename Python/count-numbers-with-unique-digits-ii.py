# Time:  O(logb)
# Space: O(logb)

# combinatorics
class Solution(object):
    def numberCount(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        fact = [1]*2
        def nPr(n, k):
            while len(fact) <= n:  # lazy initialization
                fact.append(fact[-1]*len(fact))
            return fact[n]//fact[n-k]

        def count(x):
            digits = map(int, str(x))
            result = 9*sum(nPr(9, i) for i in xrange(len(digits)-1))
            lookup = 0
            for i, d in enumerate(digits):
                result += sum(lookup&(1<<j) == 0 for j in xrange(int(i == 0), d))*nPr(10-(i+1), len(digits)-(i+1))
                if lookup&(1<<d):
                    break
                lookup |= 1<<d
            return result

        return count(b+1)-count(a)


# Time:  O(blogb)
# Space: O(1)
# hash table
class Solution2(object):
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
class Solution3(object):
    def numberCount(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        return sum(len(set(str(x))) == len(str(x)) for x in xrange(a, b+1))
