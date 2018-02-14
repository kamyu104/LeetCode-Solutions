# Time:  O(n)
# Space: O(1)

# Given a List of words, return the words that can be typed
# using letters of alphabet on only one row's of American keyboard like the image below.
#
# Example 1:
# Input: ["Hello", "Alaska", "Dad", "Peace"]
# Output: ["Alaska", "Dad"]
# Note:
# You may use one character in the keyboard more than once.
# You may assume the input string will only contain letters of alphabet.

class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        rows = [set(['q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p']),
                set(['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l']), 
                set(['z', 'x', 'c', 'v', 'b' ,'n', 'm'])]

        result = []
        for word in words:
            k = 0
            for i in xrange(len(rows)):
                if word[0].lower() in rows[i]:
                    k = i
                    break
            for c in word:
                if c.lower() not in rows[k]:
                    break
            else:
                result.append(word)
        return result


class Solution2(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        keyboard_rows = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']
        single_row_words = []
        for word in words:
            for row in keyboard_rows:
                if all(letter in row for letter in word.lower()):
                    single_row_words.append(word)
        return single_row_words
