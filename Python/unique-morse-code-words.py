# Time:  O(n), n is the sume of all word lengths
# Space: O(n)

class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        MORSE = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                 "....", "..", ".---", "-.-", ".-..", "--", "-.",
                 "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                 "...-", ".--", "-..-", "-.--", "--.."]

        lookup = {"".join(MORSE[ord(c) - ord('a')] for c in word) \
                  for word in words}
        return len(lookup)

