# Time:  O(b^(d/2)), b is the branch factor of bfs, d is the result depth
# Space: O(w * l), w is the number of words, l is the max length of words

from collections import defaultdict
from string import ascii_lowercase


class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        def backtracking(tree, beginWord, word): 
            return [[beginWord]] if word == beginWord else [path + [word] for new_word in tree[word] for path in backtracking(tree, beginWord, new_word)]

        words = set(wordList)
        if endWord not in words:
            return []
        tree = defaultdict(set)
        is_found, left, right, is_reversed = False, {beginWord}, {endWord}, False
        while left:
            words -= left
            new_left = set()
            for word in left:
                for new_word in (word[:i]+c+word[i+1:] for i in xrange(len(beginWord)) for c in ascii_lowercase):
                    if new_word not in words:
                        continue
                    if new_word in right: 
                        is_found = True
                    else: 
                        new_left.add(new_word)
                    tree[new_word].add(word) if not is_reversed else tree[word].add(new_word)
            if is_found:
                break
            left = new_left
            if len(left) > len(right): 
                left, right, is_reversed = right, left, not is_reversed
        return backtracking(tree, beginWord, endWord)


# Time:  O(b^d), b is the branch factor of bfs, d is the result depth
# Space: O(w * l), w is the number of words, l is the max length of words
class Solution2(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        dictionary = set(wordList)
        result, cur, visited, found, trace = [], [beginWord], set([beginWord]), False, defaultdict(list)

        while cur and not found:
            for word in cur:
                visited.add(word)

            next = set()
            for word in cur:
                for i in xrange(len(word)):
                    for c in ascii_lowercase:
                        candidate = word[:i] + c + word[i + 1:]
                        if candidate not in visited and candidate in dictionary:
                            if candidate == endWord:
                                found = True
                            next.add(candidate)
                            trace[candidate].append(word)
            cur = next

        if found:
            self.backtrack(result, trace, [], endWord)

        return result

    def backtrack(self, result, trace, path, word):
        if not trace[word]:
            path.append(word)
            result.append(path[::-1])
            path.pop()
        else:
            for prev in trace[word]:
                path.append(word)
                self.backtrack(result, trace, path, prev)
                path.pop()
