from __future__ import print_function
# Time:  O(n * d), n is length of string, d is size of dictionary
# Space: O(d)

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        distance, cur, visited, lookup = 0, [beginWord], set([beginWord]), set(wordList)

        while cur:
            next_queue = []

            for word in cur:
                if word == endWord:
                    return distance + 1
                for i in xrange(len(word)):
                    for j in 'abcdefghijklmnopqrstuvwxyz':
                        candidate = word[:i] + j + word[i + 1:]
                        if candidate not in visited and candidate in lookup:
                            next_queue.append(candidate)
                            visited.add(candidate)
            distance += 1
            cur = next_queue

        return 0

if __name__ == "__main__":
    print(Solution().ladderLength("hit", "cog", set(["hot", "dot", "dog", "lot", "log"])))
    print(Solution().ladderLength("hit", "cog", set(["hot", "dot", "dog", "lot", "log", "cog"])))

