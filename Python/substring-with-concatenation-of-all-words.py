# Time:  O((m + n) * k), where m is string length, n is dictionary size, k is word length
# Space: O(n * k)

# You are given a string, S, and a list of words, L, that are all of the same length. 
# Find all starting indices of substring(s) in S that is a concatenation of each word 
# in L exactly once and without any intervening characters.
# 
# For example, given:
# S: "barfoothefoobarman"
# L: ["foo", "bar"]
# 
# You should return the indices: [0,9].
# (order does not matter).
#

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        result, m, n, k = [], len(s), len(words), len(words[0])
        if m < n*k:
            return result
        
        lookup = collections.defaultdict(int)
        for i in words:
            lookup[i] += 1                # Space: O(n * k)

        for i in xrange(k):               # Time:  O(m / k)
            left, count = i, 0
            tmp = collections.defaultdict(int)
            for j in xrange(i, m-k+1, k): # Time:  O(m / k)
                s1 = s[j:j+k];            # Time:  O(k)
                if s1 in lookup:
                    tmp[s1] += 1
                    if tmp[s1] <= lookup[s1]: 
                        count += 1
                    else:
                        while tmp[s1] > lookup[s1]:
                            s2 = s[left:left+k]
                            tmp[s2] -= 1
                            if tmp[s2] < lookup[s2]:
                                count -= 1
                            left += k
                    if count == n:
                        result.append(left)
                        tmp[s[left:left+k]] -= 1
                        count -= 1
                        left += k
                else:
                    tmp = collections.defaultdict(int)
                    count = 0
                    left = j+k
        return result


# Time:  O(m * n * k), where m is string length, n is dictionary size, k is word length
# Space: O(n * k)
class Solution2(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        result, m, n, k = [], len(s), len(words), len(words[0])
        if m < n*k:
            return result
        lookup = collections.defaultdict(int)
        for i in words:
            lookup[i] += 1                            # Space: O(n * k)

        for i in xrange(m+1-k*n):                     # Time: O(m)
            cur, j = collections.defaultdict(int), 0
            while j < n:                              # Time: O(n)
                word = s[i+j*k:i+j*k+k]               # Time: O(k)
                if word not in lookup: 
                    break
                cur[word] += 1
                if cur[word] > lookup[word]:
                    break
                j += 1
            if j == n:
                result.append(i)
                
        return result


if __name__ == "__main__":
    print Solution().findSubstring("barfoothefoobarman", ["foo", "bar"])
