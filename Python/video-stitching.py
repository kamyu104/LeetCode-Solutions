# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def videoStitching(self, clips, T):
        """
        :type clips: List[List[int]]
        :type T: int
        :rtype: int
        """
        result = 0
        curr_reachable, reachable = -1, 0
        clips.sort()
        for left, right in clips:
            if reachable >= T or left > reachable:
                break
            elif left > curr_reachable:
                curr_reachable = reachable
                result += 1
            reachable = max(reachable, right)
        return result if reachable >= T else -1
