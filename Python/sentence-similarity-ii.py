# Time:  O(n + p)
# Space: O(p)

# Given two sentences words1, words2 (each represented as an array of strings),
# and a list of similar word pairs pairs, determine if two sentences are similar.
#
# For example, words1 = ["great", "acting", "skills"] and
# words2 = ["fine", "drama", "talent"] are similar,
# if the similar word pairs are pairs =
# [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].
#
# Note that the similarity relation is transitive.
# For example, if "great" and "good" are similar,
# and "fine" and "good" are similar, then "great" and "fine" are similar.
#
# Similarity is also symmetric.
# For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.
#
# Also, a word is always similar with itself.
# For example, the sentences words1 = ["great"],
# words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.
#
# Finally, sentences can only be similar if they have the same number of words.
# So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
#
# Note:
# - The length of words1 and words2 will not exceed 1000.
# - The length of pairs will not exceed 2000.
# - The length of each pairs[i] will be 2.
# - The length of each words[i] and pairs[i][j] will be in the range [1, 20].

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        self.set[min(x_root, y_root)] = max(x_root, y_root)
        return True


class Solution(object):
    def areSentencesSimilarTwo(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        if len(words1) != len(words2): return False

        lookup = {}
        union_find = UnionFind(2 * len(pairs))
        for pair in pairs:
            for p in pair:
                if p not in lookup:
                    lookup[p] = len(lookup)
            union_find.union_set(lookup[pair[0]], lookup[pair[1]])

        return all(w1 == w2 or
                   w1 in lookup and w2 in lookup and
                   union_find.find_set(lookup[w1]) == union_find.find_set(lookup[w2])
                   for w1, w2 in itertools.izip(words1, words2))
