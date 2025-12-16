# Time:  O(n)
# Space: O(1)

# string, inplace
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        VOWELS = set("aeiou")
        def count(left, right):
            return sum(s[i] in VOWELS for i in xrange(left, right+1))

        def reverse(left, right):
            while left < right:
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1

        s = list(s)
        l, cnt = 0, -1
        for i in xrange(len(s)):
            if s[i] == ' ':
                l = 0
                continue
            l += 1
            if i+1 < len(s) and s[i+1] != ' ':
                continue
            c = count(i-l+1, i)
            if cnt == -1:
                cnt = c
            elif cnt == c:
                reverse(i-l+1, i)
        return "".join(s)


# Time:  O(n)
# Space: O(n)
# string
class Solution2(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        VOWELS = set("aeiou")
        def count(s):
            return sum(x in VOWELS for x in s)

        result = s.split()
        cnt = count(result[0])
        return " ".join(w if not i or count(w) != cnt else w[::-1] for i, w in enumerate(result))
