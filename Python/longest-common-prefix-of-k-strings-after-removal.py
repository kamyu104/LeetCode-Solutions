# Time:  O(l * nlogn)
# Space: O(n)

# sort, sliding window, prefix sum
class Solution(object):
    def longestCommonPrefix(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[int]
        """
        idxs = range(len(words))
        idxs.sort(key=lambda x: words[x])
        def longest_common_prefix(k):
            lcp = [0]*len(words)
            for i in xrange(len(words)-(k-1)):
                left = words[idxs[i]]
                right = words[idxs[i+(k-1)]]
                l = min(len(left), len(right))
                lcp[i] = next((j for j in xrange(l) if left[j] != right[j]), l)
            return lcp
        
        lcp = longest_common_prefix(k)
        prefix = [0]*len(words)
        prefix[0] = lcp[0]
        for i in xrange(len(prefix)-1):
            prefix[i+1] = max(prefix[i], lcp[i+1])
        suffix = [0]*len(words)
        suffix[-1] = lcp[-1]
        for i in reversed(xrange(len(suffix)-1)):
            suffix[i] = max(suffix[i+1], lcp[i])
        result = [0]*len(words)
        mx = max(longest_common_prefix(k+1))
        for i in xrange(len(words)):
            idx = idxs[i]
            mx1 = prefix[i-k] if i-k >= 0 else 0
            mx2 = suffix[i+1] if i+1 < len(words) else 0
            result[idx] = max(mx, mx1, mx2)
        return result
        

# Time:  O(n * l)
# Space: O(t)
# trie
class Solution2(object):
    def longestCommonPrefix(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[int]
        """
        class Trie(object):
            def __init__(self):
                self.__root = self.__new_node()
            
            def __new_node(self):
                return {"cnt":0, "max":0}

            def update(self, w, d, k):
                path = [None]*(len(w)+1)
                path[0] = curr = self.__root
                for i, x in enumerate(w, 1):
                    if x not in curr:
                        curr[x] = self.__new_node()
                    path[i] = curr = curr[x]
                for i in reversed(xrange(len(path))):
                    curr = path[i]
                    curr["cnt"] += d
                    curr["max"] = i if curr["cnt"] >= k else 0
                    for x in curr.iterkeys():
                        if len(x) == 1:
                            curr["max"] = max(curr["max"], curr[x]["max"])

            def query(self):
                return self.__root["max"]
        

        trie = Trie()
        for w in words:
            trie.update(w, +1, k)
        result = [0]*len(words)
        for i in xrange(len(words)):
            trie.update(words[i], -1, k)
            result[i] = trie.query()
            trie.update(words[i], +1, k)
        return result


# Time:  O(n * l)
# Space: O(t)
# trie
class Solution_TLE(object):
    def longestCommonPrefix(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[int]
        """
        class Trie(object):
            def __init__(self):
                self.__nodes = []
                self.__cnt = []
                self.__mx = []
                self.__new_node()
            
            def __new_node(self):
                self.__nodes.append([-1]*26)
                self.__cnt.append(0)
                self.__mx.append(0)
                return len(self.__nodes)-1

            def update(self, w, d, k):
                path = [-1]*(len(w)+1)
                path[0] = curr = 0
                for i, c in enumerate(w, 1):
                    x = ord(c)-ord('a')
                    if self.__nodes[curr][x] == -1:
                        self.__nodes[curr][x] = self.__new_node()
                    path[i] = curr = self.__nodes[curr][x]
                for i in reversed(xrange(len(path))):
                    curr = path[i]
                    self.__cnt[curr] += d
                    self.__mx[curr] = i if self.__cnt[curr] >= k else 0
                    for x in xrange(len(self.__nodes[curr])):
                        if self.__nodes[curr][x] != -1:
                            self.__mx[curr]= max(self.__mx[curr], self.__mx[self.__nodes[curr][x]])

            def query(self):
                return self.__mx[0]
        

        result = [0]*len(words)
        trie = Trie()
        for w in words:
            trie.update(w, +1, k)
        for i in xrange(len(words)):
            trie.update(words[i], -1, k)
            result[i] = trie.query()
            trie.update(words[i], +1, k)
        return result
