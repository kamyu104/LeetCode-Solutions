# Time:  ctor:                O(1)
#        upload:              O(logn+l)
#        remove:              O(logn)
#        like:                O(1)
#        dislike:             O(1)
#        view:                O(l)
#        getLikesAndDislikes: O(1)
#        getViews:            O(1)
# Space: O(n * l), n = len(videos), l = max(len(v) for v in videos) 

import collections
import heapq


class VideoSharingPlatform(object):

    def __init__(self):
        self.__videos = {}
        self.__avail_ids = []
        self.__max_id = 0
        self.__likes = collections.Counter()
        self.__dislikes = collections.Counter()
        self.__views = collections.Counter()

    def upload(self, video):
        """
        :type video: str
        :rtype: int
        """
        if self.__avail_ids:
            i = heapq.heappop(self.__avail_ids)
        else:
            i = self.__max_id
            self.__max_id += 1
        self.__videos[i] = video
        return i
        
    def remove(self, videoId):
        """
        :type videoId: int
        :rtype: None
        """
        if videoId not in self.__videos:
            return
        heapq.heappush(self.__avail_ids, videoId)
        del self.__videos[videoId]
        del self.__likes[videoId]
        del self.__dislikes[videoId]
        del self.__views[videoId]
        
    def watch(self, videoId, startMinute, endMinute):
        """
        :type videoId: int
        :type startMinute: int
        :type endMinute: int
        :rtype: str
        """
        if videoId not in self.__videos:
            return "-1"
        self.__views[videoId] += 1
        return self.__videos[videoId][startMinute:endMinute+1]

    def like(self, videoId):
        """
        :type videoId: int
        :rtype: None
        """
        if videoId not in self.__videos:
            return
        self.__likes[videoId] += 1

    def dislike(self, videoId):
        """
        :type videoId: int
        :rtype: None
        """
        if videoId not in self.__videos:
            return
        self.__dislikes[videoId] += 1

    def getLikesAndDislikes(self, videoId):
        """
        :type videoId: int
        :rtype: List[int]
        """
        if videoId not in self.__videos:
            return [-1]
        return [self.__likes[videoId], self.__dislikes[videoId]]

    def getViews(self, videoId):
        """
        :type videoId: int
        :rtype: int
        """
        if videoId not in self.__videos:
            return -1
        return self.__views[videoId]
