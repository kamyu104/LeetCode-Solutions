from __future__ import print_function
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLongestSubstringTwoDistinct(self, s):
        longest, start, distinct_count, visited = 0, 0, 0, [0 for _ in xrange(256)]
        for i, char in enumerate(s):
            if visited[ord(char)] == 0:
                distinct_count += 1
            visited[ord(char)] += 1

            while distinct_count > 2:
                visited[ord(s[start])] -= 1
                if visited[ord(s[start])] == 0:
                    distinct_count -= 1
                start += 1

            longest = max(longest, i - start + 1)
        return longest

if __name__ == "__main__":
    print(Solution().lengthOfLongestSubstringTwoDistinct("eceba"))

