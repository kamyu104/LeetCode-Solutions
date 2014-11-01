# Time:  O(n^2 ~ 2^n)
# Space: O(n^2)
#
# Given a string s, partition s such that every substring of the partition is a palindrome.
# 
# Return all possible palindrome partitioning of s.
# 
# For example, given s = "aab",
# Return
# 
#   [
#     ["aa","b"],
#     ["a","a","b"]
#   ]

# Time:  O(n^2 ~ 2^n)
# Space: O(n^2)
# dynamic programming solution
class Solution:
    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
        n = len(s)
        
        is_palindrome = [[0 for j in xrange(n)] for i in xrange(n)]
        for i in reversed(xrange(0, n)):
            for j in xrange(i, n):
                is_palindrome[i][j] = s[i] == s[j] and ((j - i < 2 ) or is_palindrome[i + 1][j - 1])
        
        sub_partition = [[] for i in xrange(n)]
        for i in reversed(xrange(n)):
            for j in xrange(i, n):
                if is_palindrome[i][j]:
                    if j + 1 < n:
                        for p in sub_partition[j + 1]:
                            sub_partition[i].append([s[i:j + 1]] + p)
                    else:
                        sub_partition[i].append([s[i:j + 1]])
                        
        return sub_partition[0]

# Time:  O(2^n)
# Space: O(n)
# recursive solution
class Solution2:
    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
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

if __name__ == "__main__":
    print Solution().partition("aab")
