# Time:  ctor:  O(n + p^2), n is the total size of patterns
#                         , p is the count of patterns
#        query: O(m + z), m is the total size of query string
#                       , z is the number of all matched strings 
# Space: O(t + p^2), t is the total size of ac automata trie,

# Aho–Corasick automata
# reference:
# * http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Small02.pdf
# * http://algo.pw/algo/64/python

import collections


class AhoNode:
    def __init__(self):
        self.states = collections.defaultdict(AhoNode)
        self.output = []
        self.suffix = None


def create_ac_trie(patterns):  # Time:  O(n), Space: O(t)
    root = AhoNode()
    for i, pattern in enumerate(patterns):
        node = root
        for c in pattern:
            node = node.states[c]
        node.output.append(i)
    return root
 

def create_ac_suffix_and_output_links(root):  # Time:  O(n + p^2), Space: O(t + p^2)
    queue = collections.deque()
    for node in root.states.itervalues():
        queue.append(node)
        node.suffix = root
 
    while queue:
        rnode = queue.popleft()
        for key, child in rnode.states.iteritems():
            queue.append(child)
            fnode = rnode.suffix
            while fnode and key not in fnode.states:
                fnode = fnode.suffix
            child.suffix = fnode.states[key] if fnode else root
            child.output += child.suffix.output  # Time: O(p^2)


def create_ac_automata(patterns):
    root = create_ac_trie(patterns)
    create_ac_suffix_and_output_links(root)
    return root


def print_all_matched_strings(words, output):
    for l in output:
        print words[l]


class StreamChecker(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.__root = create_ac_automata(words)
        self.__node = self.__root
        self.__words = words

    def query(self, letter):
        """
        :type letter: str
        :rtype: bool
        """
        while self.__node and letter not in self.__node.states:
            self.__node = self.__node.suffix
        if not self.__node:
            self.__node = self.__root
            return
        self.__node = self.__node.states[letter]
        if self.__node.output:
            print_all_matched_strings(self.__words, self.__node.output)
            return True
        return False

# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
