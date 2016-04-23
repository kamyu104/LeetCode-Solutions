# Time:  O(n)
# Space: O(1)

# Write a function that takes a string as input 
# and reverse only the vowels of a string.
#
# Example 1:
# Given s = "hello", return "holle".
#
# Example 2:
# Given s = "leetcode", return "leotcede".

class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = "aeiou"
        string = list(s)
        i, j = 0, len(s) - 1
        while i < j:
            if string[i].lower() in vowels and \
               string[j].lower() in vowels:
                string[i], string[j] = string[j], string[i]
                i += 1
                j -= 1
            elif string[i].lower() not in vowels:
                i += 1
            else:
                j -= 1
        return "".join(string)
