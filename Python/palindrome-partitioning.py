# Time:  O(n^2 ~ 2^n)
# Space: O(n^2)

class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        is_palindrome = [[False] * len(s) for i in xrange(len(s))]
        for i in reversed(xrange(len(s))):
            for j in xrange(i, len(s)):
                is_palindrome[i][j] = s[i] == s[j] and ((j - i < 2) or is_palindrome[i + 1][j - 1])

        sub_partition = [[] for _ in xrange(len(s))]
        for i in reversed(xrange(len(s))):
            for j in xrange(i, len(s)):
                if is_palindrome[i][j]:
                    if j + 1 < len(s):
                        for p in sub_partition[j + 1]:
                            sub_partition[i].append([s[i:j + 1]] + p)
                    else:
                        sub_partition[i].append([s[i:j + 1]])

        return sub_partition[0]


# Time:  O(2^n)
# Space: O(n)
# recursive solution
class Solution2(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        result = []
        self.partitionRecu(result, [], s, 0)
        return result

    def partitionRecu(self, result, cur, s, i):
        if i == len(s):
            result.append(list(cur))
        else:
            for j in xrange(i, len(s)):
                if self.isPalindrome(s[i: j + 1]):
                    cur.append(s[i: j + 1])
                    self.partitionRecu(result, cur, s, j + 1)
                    cur.pop()

    def isPalindrome(self, s):
        for i in xrange(len(s) / 2):
            if s[i] != s[-(i + 1)]:
                return False
        return True

