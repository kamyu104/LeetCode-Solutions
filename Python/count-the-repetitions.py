# Time:  O(s1 * min(s2, n1))
# Space: O(s2)

class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        """
        :type s1: str
        :type n1: int
        :type s2: str
        :type n2: int
        :rtype: int
        """
        repeat_count = [0] * (len(s2)+1)
        lookup = {}
        j, count = 0, 0
        for k in xrange(1, n1+1):
            for i in xrange(len(s1)):
                if s1[i] == s2[j]:
                    j = (j + 1) % len(s2)
                    count += (j == 0)

            if j in lookup:   # cyclic
                i = lookup[j]
                prefix_count = repeat_count[i]
                pattern_count = (count - repeat_count[i]) * ((n1 - i) // (k - i))
                suffix_count = repeat_count[i + (n1 - i) % (k - i)] - repeat_count[i]
                return (prefix_count + pattern_count + suffix_count) / n2
            lookup[j] = k
            repeat_count[k] = count

        return repeat_count[n1] / n2  # not cyclic iff n1 <= s2

