# Time:  O(nlogr), r = max(max(a), max(b), max(c))
# Space: O(1)

# bit manipulation, parity
class Solution(object):
    def tripletCount(self, a, b, c):
        """
        :type a: List[int]
        :type b: List[int]
        :type c: List[int]
        :rtype: int
        """
        def popcount(x):
            return bin(x).count('1')

        def count(a):
            odd = sum(popcount(x)&1 for x in a)
            return [len(a)-odd, odd]
        
        cnt = map(count, (a, b, c))
        return sum(cnt[0][0 if i == 0 or i == 1 else 1]*cnt[1][0 if i == 0 or i == 2 else 1]*cnt[2][0 if i == 0 or i == 3 else 1] for i in xrange(4))
    

# Time:  O(nlogr), r = max(max(a), max(b), max(c))
# Space: O(1)
# bit manipulation, parity
class Solution2(object):
    def tripletCount(self, a, b, c):
        """
        :type a: List[int]
        :type b: List[int]
        :type c: List[int]
        :rtype: int
        """
        def popcount(x):
            return bin(x).count('1')

        def count(a):
            odd = sum(popcount(x)&1 for x in a)
            return [len(a)-odd, odd]
        
        even1, odd1 = count(a)
        even2, odd2 = count(b)
        even3, odd3 = count(c)
        return even1*even2*even3 + even1*odd2*odd3 + odd1*even2*odd3 + odd1*odd2*even3


# Time:  O(n^3 * logr), r = max(max(a), max(b), max(c))
# Space: O(1)
# brute force, bit manipulation
class Solution3(object):
    def tripletCount(self, a, b, c):
        """
        :type a: List[int]
        :type b: List[int]
        :type c: List[int]
        :rtype: int
        """
        def popcount(x):
            return bin(x).count('1')

        return sum(popcount(x^y^z)%2 == 0 for x in a for y in b for z in c)
