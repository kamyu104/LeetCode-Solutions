# Time:  O(n + vlogv), v is the number of the level videos
# Space: O(w)

import collections


class Solution(object):
    def watchedVideosByFriends(self, watchedVideos, friends, id, level):
        """
        :type watchedVideos: List[List[str]]
        :type friends: List[List[int]]
        :type id: int
        :type level: int
        :rtype: List[str]
        """
        curr_level, lookup = set([id]), set([id])
        for _ in xrange(level):
            curr_level = set(j for i in curr_level for j in friends[i] if j not in lookup)
            lookup |= curr_level
        count = collections.Counter([v for i in curr_level for v in watchedVideos[i]])
        return sorted(count.keys(), key=lambda x: (count[x], x))
