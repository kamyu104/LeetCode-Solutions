# Time:  O(nlogg) = O(n / g * glogg), g is max size of groups
# Space: O(n)
#
# Given an array of strings, return all groups of strings that are anagrams.
#
# Note: All inputs will be in lower-case.
#

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
    result = Solution().anagrams(["cat", "dog", "act", "mac"])
    print result
