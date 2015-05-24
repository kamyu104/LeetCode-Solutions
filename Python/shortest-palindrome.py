# Time:  O(n)
# Space: O(n)

# KMP algorithm
class Solution:
    # @param {string} s
    # @return {string}
    def shortestPalindrome(self, s):
        if not s:
            return s
            
        A = s + s[::-1]
        prefix = self.getPrefix(A)
            
        return s[prefix[-1]+1:][::-1] + s
        
    def getPrefix(self, pattern):
        prefix = [-1] * len(pattern)
        j = -1
        for i in xrange(1, len(pattern)):
            while j > -1 and pattern[j+1] != pattern[i]:
                j = prefix[j]
            if pattern[j+1] == pattern[i]:
                j += 1
            prefix[i] = j
        return prefix

# Manacher's Algorithm
class Solution_TLE:
    # @param {string} s
    # @return {string}
    def shortestPalindrome(self, s):
        string = self.preProcess(s)
        palindrome = [0] * len(string) 
        center, right = 0, 0
        for i in xrange(1, len(string) - 1):
            i_mirror = 2 * center - i
            if right > i:
                palindrome[i] = min(right - i, palindrome[i_mirror])
            else:
                palindrome[i] = 0

            while string[i + 1 + palindrome[i]] == string[i - 1 - palindrome[i]]:
                palindrome[i] += 1

            if i + palindrome[i] > right:
                center, right = i, i + palindrome[i]       
        
        max_len = 0
        for i in xrange(1, len(string) - 1):
            if i - palindrome[i] == 1:
                max_len = palindrome[i]
        return s[len(s)-1:max_len-1:-1] + s
        
    def preProcess(self, s):
        if not s:
            return "^$"
        string = "^"
        for i in s:
            string +=  "#" + i
        string += "#$"
        return string
        
