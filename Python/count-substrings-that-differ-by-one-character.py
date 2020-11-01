# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def countSubstrings(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        def count(i, j):  # for each possible alignment, count the number of substrs that differ by 1 char
            result = left_cnt = right_cnt = 0  # left and right consecutive same counts relative to the different char
            for k in xrange(min(len(s)-i, len(t)-j)):
                right_cnt += 1
                if s[i+k] != t[j+k]:
                    left_cnt, right_cnt = right_cnt, 0
                    # prev_i = i+k-prev+1
                result += left_cnt  # target substrs are [s[left_i+c:i+k+1] for c in xrange(left_cnt)]
            return result

        return sum(count(i, 0) for i in xrange(len(s))) + \
               sum(count(0, j) for j in xrange(1, len(t)))
