# Time:  O(n)
# Space: O(n)

# z-function
class Solution(object):
    def minimumTimeToInitialState(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b
    
        def z_function(s):  # Time: O(n), Space: O(n)
            z = [0]*len(s)
            l, r = 0, 0
            for i in xrange(1, len(z)):
                if i <= r:
                    z[i] = min(r-i+1, z[i-l])
                while i+z[i] < len(z) and s[z[i]] == s[i+z[i]]:
                    z[i] += 1
                if i+z[i]-1 > r:
                    l, r = i, i+z[i]-1
            return z

        z = z_function(word)
        for i in xrange(k, len(word), k):
            if z[i] == len(word)-i:
                return i//k
        return ceil_divide(len(word), k)


# Time:  O(n^2)
# Space: O(1)
# brute force
class Solution2(object):
    def minimumTimeToInitialState(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        for i in xrange(k, len(word), k):
            if all(word[i+j] == word[j] for j in xrange(len(word)-i)):
                return i//k
        return ceil_divide(len(word), k)
