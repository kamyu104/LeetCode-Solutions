from __future__ import print_function
# Time:  O(n * d), n is length of string, d is size of dictionary
# Space: O(d)

class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return an integer
    def findLadders(self, start, end, dict):
        dict.add(start)
        dict.add(end)

        result, cur, visited, found, trace = [], [start], set([start]), False, {word: [] for word in dict}

        while cur and not found:
            for word in cur:
                visited.add(word)

            next = set()
            for word in cur:
                for i in xrange(len(word)):
                    for j in 'abcdefghijklmnopqrstuvwxyz':
                        candidate = word[:i] + j + word[i + 1:]
                        if candidate not in visited and candidate in dict:
                            if candidate == end:
                                found = True
                            next.add(candidate)
                            trace[candidate].append(word)
            cur = next

        if found:
            self.backtrack(result, trace, [], end)

        return result

    def backtrack(self, result, trace, path, word):
        if not trace[word]:
            result.append([word] + path)
        else:
            for prev in trace[word]:
                self.backtrack(result, trace, [word] + path, prev)

if __name__ == "__main__":
    print(Solution().findLadders("hit", "cog", set(["hot","dot","dog","lot","log"])))

