# Time:  O(logb)
# Space: O(1)

# hash table, bitmasks, combinatorics
class Solution(object):
    def numberCount(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        def popcount(x):
            return bin(x).count('1')

        def count2(n):
            if n == 0:
                return 0
            result = cnt = 1
            for i in xrange(n-1):
                cnt *= 9-i
                result += cnt
            return 9*result

        def count(x):
            n = base = 1
            while x//(base*10):
                base *= 10
                n += 1
            result = count2(n-1)
            lookup = 0
            cnt = reduce(lambda accu, i: accu*(9-i), xrange(n-1), 1)
            for i in xrange(n):
                d = (x//base)%10
                base //= 10
                mask = lookup&(((1<<d)-1)-int(i == 0))
                result += ((d-int(i == 0))-popcount(mask))*cnt
                cnt //= 9-i
                if lookup&(1<<d):
                    break
                lookup |= 1<<d
            return result

        return count(b+1)-count(a)


# Time:  O(logb)
# Space: O(logb)
# hash table, bitmasks, combinatorics
class Solution2(object):
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
        
        def popcount(x):
            return bin(x).count('1')

        def count(x):
            digits = map(int, str(x))
            result = 9*sum(nPr(9, i) for i in xrange(len(digits)-1))
            lookup = 0
            for i, d in enumerate(digits):
                mask = lookup&(((1<<d)-1)-int(i == 0))
                result += ((d-int(i == 0))-popcount(mask))*nPr(10-(i+1), len(digits)-(i+1))
                if lookup&(1<<d):
                    break
                lookup |= 1<<d
            return result

        return count(b+1)-count(a)


# Time:  O(blogb)
# Space: O(1)
# brute force, hash table, bitmasks
class Solution3(object):
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
# brute force, hash table
class Solution4(object):
    def numberCount(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        return sum(len(set(str(x))) == len(str(x)) for x in xrange(a, b+1))
