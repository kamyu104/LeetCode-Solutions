# Time:  O(n + w * l)
# Space: O(n + w * l)

# rolling hash, hash table, two pointers, sliding window, dp
class Solution(object):
    def minValidStrings(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """
        MOD, P = 10**9+7, 131
        power = [1]
        for _ in xrange(len(target)):
            power.append(power[-1]*P%MOD)
        lookup = set()
        for w in words:
            h = 0
            for x in w:
                h = (h*P+(ord(x)-ord('a')+1))%MOD
                lookup.add(h)
        dp = [0]*(len(target)+1)
        left = h = 0
        for right in xrange(len(target)):
            h = (h*P+(ord(target[right])-ord('a')+1))%MOD
            while right-left+1 >= 1 and h not in lookup:
                h = (h-(ord(target[left])-ord('a')+1)*power[(right-left+1)-1])%MOD
                left += 1
            if right-left+1 == 0:
                return -1
            dp[right+1] = dp[(right-(right-left+1))+1]+1
        return dp[-1]


# Time:  O(n + w * l)
# Space: O(n + t), t is the total size of ac automata trie
import collections


class AhoNode(object):
    def __init__(self):
        self.children = collections.defaultdict(AhoNode)
        # self.indices = []
        self.suffix = None
        # self.output = None
        self.length = 0  # added


class AhoTrie(object):

    def step(self, letter):
        while self.__node and letter not in self.__node.children:
            self.__node = self.__node.suffix
        self.__node = self.__node.children[letter] if self.__node else self.__root
        return self.__get_ac_node_outputs(self.__node)
    
    def __init__(self, patterns):
        self.__root = self.__create_ac_trie(patterns)
        self.__node = self.__create_ac_suffix_and_output_links(self.__root)
    
    def __create_ac_trie(self, patterns):  # Time:  O(n), Space: O(t)
        root = AhoNode()
        for i, pattern in enumerate(patterns):
            node = root
            for l, c in enumerate(pattern, 1):  # modified
                node = node.children[c]
                node.length = l  # added
            # node.indices.append(i)
        return root

    def __create_ac_suffix_and_output_links(self, root):  # Time:  O(n), Space: O(t)
        queue = collections.deque()
        for node in root.children.itervalues():
            queue.append(node)
            node.suffix = root

        while queue:
            node = queue.popleft()
            for c, child in node.children.iteritems():
                queue.append(child)
                suffix = node.suffix
                while suffix and c not in suffix.children:
                    suffix = suffix.suffix
                child.suffix = suffix.children[c] if suffix else root
                # child.output = child.suffix if child.suffix.indices else child.suffix.output
                
        return root

    def __get_ac_node_outputs(self, node):  # Time:  O(z)
        return node.length  # modified
        # result = []
        # for i in node.indices:
        #     result.append(i)
        # output = node.output
        # while output:
        #     for i in output.indices:
        #         result.append(i)
        #     output = output.output
        # return result


# ac automata trie
class Solution2(object):
    def minValidStrings(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """
        trie = AhoTrie(words)
        dp = [0]*(len(target)+1)
        for i in xrange(len(target)):
            l = trie.step(target[i])
            if not l:
                return -1
            dp[i+1] = dp[(i-l)+1]+1
        return dp[-1]


# Time:  O(w * (l + n))
# Space: O(l + n)
# kmp, dp
class Solution3(object):
    def minValidStrings(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """
        def getPrefix(pattern):
            prefix = [-1]*len(pattern)
            j = -1
            for i in xrange(1, len(pattern)):
                while j+1 > 0 and pattern[j+1] != pattern[i]:
                    j = prefix[j]
                if pattern[j+1] == pattern[i]:
                    j += 1
                prefix[i] = j
            return prefix

        def KMP(text, pattern, callback):
            prefix = getPrefix(pattern)
            j = -1
            for i in xrange(len(text)):
                while j+1 > 0 and pattern[j+1] != text[i]:
                    j = prefix[j]
                if pattern[j+1] == text[i]:
                    j += 1
                callback(i, j)
                if j+1 == len(pattern):
                    j = prefix[j]

        def update(i, j):
            lookup[i] = max(lookup[i], j+1)

        lookup = [0]*len(target)
        for w in words:
            KMP(target, w, update)
        dp = [0]*(len(target)+1)
        for i in xrange(len(target)):
            if not lookup[i]:
                return -1
            dp[i+1] = dp[(i-lookup[i])+1]+1
        return dp[-1]
