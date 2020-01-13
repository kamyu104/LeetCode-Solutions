# Time:  O(n^2 + d), d is the duplicated of result substrings size
# Space: O(r), r is the size of result substrings set

class Solution(object):
    def distinctEchoSubstrings(self, text):
        """
        :type text: str
        :rtype: int
        """
        def KMP(text, l, result):
            prefix = [-1]*(len(text)-l)
            j = -1
            for i in xrange(1, len(prefix)):
                while j > -1 and text[l+j+1] != text[l+i]:
                    j = prefix[j]
                if text[l+j+1] == text[l+i]:
                    j += 1
                prefix[i] = j
                if (j+1) and (i+1) % ((i+1) - (j+1)) == 0 and \
                   (i+1) // ((i+1) - (j+1)) % 2 == 0:
                    result.add(text[l:l+i+1])
            return len(prefix)-(prefix[-1]+1) \
                   if prefix[-1]+1 and len(prefix) % (len(prefix)-(prefix[-1]+1)) == 0 \
                   else float("inf")

        result = set()
        i, l = 0, len(text)-1
        while i < l:  # aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdefabcdefabcdef
            l = min(l, i + KMP(text, i, result));
            i += 1
        return len(result)


# Time:  O(n^2 + d), d is the duplicated of result substrings size
# Space: O(r), r is the size of result substrings set
class Solution2(object):
    def distinctEchoSubstrings(self, text):
        """
        :type text: str
        :rtype: int
        """
        result = set()
        for l in xrange(1, len(text)//2+1):
            count = sum(text[i] == text[i+l] for i in xrange(l))
            for i in xrange(len(text)-2*l):
                if count == l:
                    result.add(text[i:i+l])
                count += (text[i+l] == text[i+l+l]) - (text[i] == text[i+l])
            if count == l:
                result.add(text[len(text)-2*l:len(text)-2*l+l])
        return len(result)


# Time:  O(n^2 + d), d is the duplicated of result substrings size
# Space: O(r), r is the size of result substrings set
class Solution3(object):
    def distinctEchoSubstrings(self, text):
        """
        :type text: str
        :rtype: int
        """
        MOD = 10**9+7
        D = 27  # a-z and ''
        result = set()
        for i in xrange(len(text)-1):
            left, right, pow_D = 0, 0, 1
            for l in xrange(1, min(i+2, len(text)-i)):
                left = (D*left + (ord(text[i-l+1])-ord('a')+1)) % MOD
                right = (pow_D*(ord(text[i+l])-ord('a')+1) + right) % MOD
                if left == right:  # assumed no collision
                    result.add(left)
                pow_D = (pow_D*D) % MOD 
        return len(result)


# Time:  O(n^3 + d), d is the duplicated of result substrings size
# Space: O(r), r is the size of result substrings set
class Solution_TLE(object):
    def distinctEchoSubstrings(self, text):
        """
        :type text: str
        :rtype: int
        """
        def compare(text, l, s1, s2):
            for i in xrange(l):
                if text[s1+i] != text[s2+i]:
                    return False
            return True

        MOD = 10**9+7
        D = 27  # a-z and ''
        result = set()
        for i in xrange(len(text)):
            left, right, pow_D = 0, 0, 1
            for l in xrange(1, min(i+2, len(text)-i)):
                left = (D*left + (ord(text[i-l+1])-ord('a')+1)) % MOD
                right = (pow_D*(ord(text[i+l])-ord('a')+1) + right) % MOD
                if left == right and compare(text, l, i-l+1, i+1):
                    result.add(text[i+1:i+1+l])
                pow_D = (pow_D*D) % MOD 
        return len(result)
