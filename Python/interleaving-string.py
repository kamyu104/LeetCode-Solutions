# Time:  O(m * n)
# Space: O(m + n)

class Solution(object):
    # @return a boolean
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3):
            return False
        if len(s1) > len(s2):
            return self.isInterleave(s2, s1, s3)
        match = [False for i in xrange(len(s1) + 1)]
        match[0] = True
        for i in xrange(1, len(s1) + 1):
            match[i] = match[i -1] and s1[i - 1] == s3[i - 1]
        for j in xrange(1, len(s2) + 1):
            match[0] = match[0] and s2[j - 1] == s3[j - 1]
            for i in xrange(1, len(s1) + 1):
                match[i] = (match[i - 1] and s1[i - 1] == s3[i + j - 1]) \
                                       or (match[i] and s2[j - 1] == s3[i + j - 1])
        return match[-1]

# Time:  O(m * n)
# Space: O(m * n)
# Dynamic Programming
class Solution2(object):
    # @return a boolean
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3):
            return False
        match = [[False for i in xrange(len(s2) + 1)] for j in xrange(len(s1) + 1)]
        match[0][0] = True
        for i in xrange(1, len(s1) + 1):
            match[i][0] = match[i - 1][0] and s1[i - 1] == s3[i - 1]
        for j in xrange(1, len(s2) + 1):
            match[0][j] = match[0][j - 1] and s2[j - 1] == s3[j - 1]
        for i in xrange(1, len(s1) + 1):
            for j in xrange(1, len(s2) + 1):
                match[i][j] = (match[i - 1][j] and s1[i - 1] == s3[i + j - 1]) \
                                       or (match[i][j - 1] and s2[j - 1] == s3[i + j - 1])
        return match[-1][-1]

# Time:  O(m * n)
# Space: O(m * n)
# Recursive + Hash
class Solution3(object):
    # @return a boolean
    def isInterleave(self, s1, s2, s3):
        self.match = {}
        if len(s1) + len(s2) != len(s3):
            return False
        return self.isInterleaveRecu(s1, s2, s3, 0, 0, 0)

    def isInterleaveRecu(self, s1, s2, s3, a, b, c):
        if repr([a, b]) in self.match.keys():
            return self.match[repr([a, b])]

        if c == len(s3):
            return True

        result = False
        if a < len(s1) and s1[a] == s3[c]:
            result = result or self.isInterleaveRecu(s1, s2, s3, a + 1, b, c + 1)
        if b < len(s2) and s2[b] == s3[c]:
            result = result or self.isInterleaveRecu(s1, s2, s3, a, b + 1, c + 1)

        self.match[repr([a, b])] = result

        return result

