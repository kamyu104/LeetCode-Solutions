# Time:  O(n + m + z) = O(m), n is the total size of patterns
#                           , m is the total size of query string
#                           , z is the number of all matched strings
#                           , O(n) = O(1), O(z) = O(m) in this problem
# Space: O(t) = O(1), t is the total size of ac automata trie
#                   , O(t) = O(1) in this problem

import collections


class AhoNode(object):
    def __init__(self):
        self.children = collections.defaultdict(AhoNode)
        self.indices = []
        self.suffix = None
        self.output = None


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
            for c in pattern:
                node = node.children[c]
            node.indices.append(i)
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
                child.output = child.suffix if child.suffix.indices else child.suffix.output
                
        return root

    def __get_ac_node_outputs(self, node):  # Time:  O(z)
        result = []
        for i in node.indices:
            result.append(i)
        output = node.output
        while output:
            for i in output.indices:
                result.append(i)
            output = output.output
        return result


class Solution(object):
    def entityParser(self, text):
        """
        :type text: str
        :rtype: str
        """
        patterns = ["&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"]
        chars = ["\"", "'", "&", ">", "<", "/"]
        trie = AhoTrie(patterns)
        positions = []
        for i in xrange(len(text)):
            for j in trie.step(text[i]):
                positions.append([i-len(patterns[j])+1, j])
        result = []
        i, j = 0, 0
        while i != len(text):
            if j == len(positions) or i != positions[j][0]:                    
                result.append(text[i])
                i += 1
            else:
                result.append(chars[positions[j][1]])
                i += len(patterns[positions[j][1]])
                j += 1
        return "".join(result)


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def entityParser(self, text):
        """
        :type text: str
        :rtype: str
        """
        patterns = ["&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"]
        chars = ["\"", "'", "&", ">", "<", "/"]
        result = []
        i, j = 0, 0
        while i != len(text):
            if text[i] != '&':                    
                result.append(text[i])
                i += 1
            else:
                for j, pattern in enumerate(patterns):
                    if pattern == text[i:i+len(pattern)]:
                        result.append(chars[j])
                        i += len(pattern)
                        break
                else:
                    result.append(text[i])
                    i += 1
        return "".join(result)
