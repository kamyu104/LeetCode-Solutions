# Time: O(n)
# Space: O(n)
# Given an array of strings, return all groups of strings that are anagrams.
#
# Note: All inputs will be in lower-case.

class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        anagrams_map, result = {}, []
        for s in strs:
            sorted_str = ("").join(sorted(s))
            if sorted_str in anagrams_map:
                anagrams_map[sorted_str].append(sorted_str)
            else:
                anagrams_map[sorted_str] = [s]
        for anagram in anagrams_map.values():
            if len(anagram) > 1:
                result += anagram
        return result
        
if __name__ == "__main__":
    result = Solution().anagrams(["cat", "dog", "act", "mac"])
    print result