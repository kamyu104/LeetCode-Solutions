# Time:  O(n)
# Space: O(1)

# inplace solution
class Solution(object):
    def reorderSpaces(self, text):
        """
        :type text: str
        :rtype: str
        """
        text = list(text)
        # count the spaces and words
        space_count, word_count = 0, 0
        for i, c in enumerate(text):
            if c == ' ':
                space_count += 1
            elif i == 0 or text[i-1] == ' ':
                word_count += 1

        # rearrange all the spaces to the right
        left, i = 0, 0
        while i < len(text):
            has_word = False
            while i < len(text) and text[i] != ' ':
                text[left], text[i] = text[i], text[left]
                left += 1
                i += 1
                has_word = True
            if has_word:
                left += 1  # keep one space
            i += 1

        # rearrange all the spaces to the left
        equal_count = space_count//(word_count-1) if word_count-1 > 0 else 0
        extra_count = space_count%(word_count-1) if word_count-1 > 0 else space_count
        right, i = len(text)-1-extra_count, len(text)-1
        while i >= 0:
            has_word = False
            while i >= 0 and text[i] != ' ':
                text[right], text[i] = text[i], text[right]
                right -= 1
                i -= 1
                has_word = True
            if has_word:
                right -= equal_count  # keep equal_count spaces
            i -= 1
        return "".join(text)
