from __future__ import print_function
# Time:  O(n * glogg), g is the max size of groups.
# Space: O(n)

import collections

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        anagrams_map, result = collections.defaultdict(list), []
        for s in strs:
            sorted_str = ("").join(sorted(s))
            anagrams_map[sorted_str].append(s)
        for anagram in anagrams_map.values():
            anagram.sort()
            result.append(anagram)
        return result

if __name__ == "__main__":
    result = Solution().groupAnagrams(["cat", "dog", "act", "mac"])
    print(result)

