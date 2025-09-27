class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        l = text.split()
        count = 0
        for i in l:
            for j in brokenLetters:
                if j in i:
                    break
            else:
                count += 1
        return count
