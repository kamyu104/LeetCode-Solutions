# Time:  O(n)
# Space: O(k), k is 
#
# Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
# 
# For example,
# S = "ADOBECODEBANC"
# T = "ABC"
# Minimum window is "BANC".
# 
# Note:
# If there is no such window in S that covers all characters in T, return the emtpy string "".
# 
# If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
#

class Solution:
    # @return a string
    def minWindow(self, S, T):
        current_count = [0 for i in xrange(52)]
        expected_count = [0 for i in xrange(52)]
        
        for char in T:
            expected_count[ord(char) - ord('a')] += 1
        
        i, count, start, min_width, min_start = 0, 0, 0, float("inf"), 0
        while i < len(S):
            current_count[ord(S[i]) - ord('a')] += 1
            if current_count[ord(S[i]) - ord('a')] <= expected_count[ord(S[i]) - ord('a')]:
                count += 1
            
            if count == len(T):
                while expected_count[ord(S[start]) - ord('a')] == 0 or\
                      current_count[ord(S[start]) - ord('a')] > expected_count[ord(S[start]) - ord('a')]:
                    current_count[ord(S[start]) - ord('a')] -= 1
                    start += 1
                
                if min_width > i - start + 1:
                    min_width = i - start + 1
                    min_start = start
            i += 1
                    
        if min_width == float("inf"):
            return ""
        
        return S[min_start:min_start + min_width]

if __name__ == "__main__":
    print Solution().minWindow("ADOBECODEBANC", "ABC")       
