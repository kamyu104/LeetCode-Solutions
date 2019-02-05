# Time:  O(n + m), m is the number of targets
# Space: O(n)

class Solution(object):
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        S = list(S)
        bucket = [None] * len(S)
        for i in xrange(len(indexes)):
            if all(indexes[i]+k < len(S) and
                   S[indexes[i]+k] == sources[i][k]
                   for k in xrange(len(sources[i]))):
                bucket[indexes[i]] = (len(sources[i]), list(targets[i]))
        result = []
        last = 0
        for i in xrange(len(S)):
            if bucket[i]:
                result.extend(bucket[i][1])
                last = i + bucket[i][0]
            elif i >= last:
                result.append(S[i])
        return "".join(result)


# Time:  O(mlogm + m * n)
# Space: O(n + m)
class Solution2(object):
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        for i, s, t in sorted(zip(indexes, sources, targets), reverse=True):
            if S[i:i+len(s)] == s:
                S = S[:i] + t + S[i+len(s):]

        return S
