# Time:  O(n * m)
# Space: O(n + m)

class Solution(object):
    # @return an integer
    def minDistance(self, word1, word2):
        if len(word1) < len(word2):
            return self.minDistance(word2, word1)

        distance = [i for i in xrange(len(word2) + 1)]

        for i in xrange(1, len(word1) + 1):
            pre_distance_i_j = distance[0]
            distance[0] = i
            for j in xrange(1, len(word2) + 1):
                insert = distance[j - 1] + 1
                delete = distance[j] + 1
                replace = pre_distance_i_j
                if word1[i - 1] != word2[j - 1]:
                    replace += 1
                pre_distance_i_j = distance[j]
                distance[j] = min(insert, delete, replace)

        return distance[-1]

# Time:  O(n * m)
# Space: O(n * m)
class Solution2(object):
    # @return an integer
    def minDistance(self, word1, word2):
        distance = [[i] for i in xrange(len(word1) + 1)]
        distance[0] = [j for j in xrange(len(word2) + 1)]

        for i in xrange(1, len(word1) + 1):
            for j in xrange(1, len(word2) + 1):
                insert = distance[i][j - 1] + 1
                delete = distance[i - 1][j] + 1
                replace = distance[i - 1][j - 1]
                if word1[i - 1] != word2[j - 1]:
                    replace += 1
                distance[i].append(min(insert, delete, replace))

        return distance[-1][-1]

