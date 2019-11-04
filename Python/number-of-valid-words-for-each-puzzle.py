# Time:  O(n*l + m*L), m is the number of puzzles, L is the length of puzzles
#                    , n is the number of words, l is the max length of words
# Space: O(L!)

class Solution(object):
    def findNumOfValidWords(self, words, puzzles):
        """
        :type words: List[str]
        :type puzzles: List[str]
        :rtype: List[int]
        """
        L = 7
        def search(node, puzzle, start, first, met_first):
            result = 0
            if "_end" in node and met_first:
                result += node["_end"];
            for i in xrange(start, len(puzzle)):
                if puzzle[i] not in node:
                    continue
                result += search(node[puzzle[i]], puzzle, i+1,
                                 first, met_first or (puzzle[i] == first))
            return result

        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        for word in words:
            count = set(word)
            if len(count) > L:
                continue
            word = sorted(count)
            end = reduce(dict.__getitem__, word, trie)
            end["_end"] = end["_end"]+1 if "_end" in end else 1
        result = []
        for puzzle in puzzles:
            first = puzzle[0]
            result.append(search(trie, sorted(puzzle), 0, first, False))
        return result


# Time:  O(m*2^(L-1) + n*(l+m)), m is the number of puzzles, L is the length of puzzles
#                              , n is the number of words, l is the max length of words
# Space: O(m*2^(L-1))
import collections


class Solution2(object):
    def findNumOfValidWords(self, words, puzzles):
        """
        :type words: List[str]
        :type puzzles: List[str]
        :rtype: List[int]
        """
        L = 7
        lookup = collections.defaultdict(list)
        for i in xrange(len(puzzles)):
            bits = []
            base = 1 << (ord(puzzles[i][0])-ord('a'))
            for j in xrange(1, L):
                bits.append(ord(puzzles[i][j])-ord('a'))
            for k in xrange(2**len(bits)):
                bitset = base
                for j in xrange(len(bits)):
                    if k & (1<<j):
                        bitset |= 1<<bits[j]
                lookup[bitset].append(i)
        result = [0]*len(puzzles)
        for word in words:
            bitset = 0
            for c in word:
                bitset |= 1<<(ord(c)-ord('a'))
            if bitset not in lookup:
                continue
            for i in lookup[bitset]:
                result[i] += 1
        return result
