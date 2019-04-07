# Time:  O(n * l), n is number of quries
#                , l is length of query
# Space: O(1)

class Solution(object):
    def camelMatch(self, queries, pattern):
        """
        :type queries: List[str]
        :type pattern: str
        :rtype: List[bool]
        """
        def is_matched(query, pattern):
            i = 0
            for c in query:
                if i < len(pattern) and pattern[i] == c:
                    i += 1
                elif c.isupper():
                    return False
            return i == len(pattern)
        
        result = []
        for query in queries:
            result.append(is_matched(query, pattern))
        return result
