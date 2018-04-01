# Time:  O(logn)
# Space: O(1)

# Given a list of sorted characters letters containing only lowercase letters,
# and given a target letter target, find the smallest element in the list that is larger than the given target.
#
# Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
#
# Examples:
# Input:
# letters = ["c", "f", "j"]
# target = "a"
# Output: "c"
#
# Input:
# letters = ["c", "f", "j"]
# target = "c"
# Output: "f"
#
# Input:
# letters = ["c", "f", "j"]
# target = "d"
# Output: "f"
#
# Input:
# letters = ["c", "f", "j"]
# target = "g"
# Output: "j"
#
# Input:
# letters = ["c", "f", "j"]
# target = "j"
# Output: "c"
#
# Input:
# letters = ["c", "f", "j"]
# target = "k"
# Output: "c"
# Note:
# - letters has a length in range [2, 10000].
# - letters consists of lowercase letters, and contains at least 2 unique letters.
# - target is a lowercase letter.

import bisect


class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        i = bisect.bisect_right(letters, target)
        return letters[0] if i == len(letters) else letters[i]
