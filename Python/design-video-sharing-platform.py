# Time:  ctor:                O(1)
#        upload:              O(logn+l)
#        remove:              O(logn)
#        like:                O(1)
#        dislike:             O(1)
#        view:                O(l)
#        getLikesAndDislikes: O(1)
#        getViews:            O(1)
# Space: O(n * l), n = len(videos), l = max(len(v) for v in videos) 

import heapq


# design, heap
class VideoSharingPlatform(object):

    def __init__(self):
        self.__avails = []
        self.__videos = []
        self.__likes = []
        self.__dislikes = []
        self.__views = []

    def upload(self, video):
        """
        :type video: str
        :rtype: int
        """
        if self.__avails:
            i = heapq.heappop(self.__avails)
        else:
            i = len(self.__videos)
            self.__videos.append(None)
            self.__likes.append(0)
            self.__dislikes.append(0)
            self.__views.append(0)
        self.__videos[i] = video
        return i
        
    def remove(self, videoId):
        """
        :type videoId: int
        :rtype: None
        """
        if videoId >= len(self.__videos) or not self.__videos[videoId]:
            return
        heapq.heappush(self.__avails, videoId)
        self.__videos[videoId] = None
        self.__likes[videoId] = self.__dislikes[videoId] = self.__views[videoId] = 0
        
    def watch(self, videoId, startMinute, endMinute):
        """
        :type videoId: int
        :type startMinute: int
        :type endMinute: int
        :rtype: str
        """
        if videoId >= len(self.__videos) or not self.__videos[videoId]:
            return "-1"
        self.__views[videoId] += 1
        return self.__videos[videoId][startMinute:endMinute+1]

    def like(self, videoId):
        """
        :type videoId: int
        :rtype: None
        """
        if videoId >= len(self.__videos) or not self.__videos[videoId]:
            return
        self.__likes[videoId] += 1

    def dislike(self, videoId):
        """
        :type videoId: int
        :rtype: None
        """
        if videoId >= len(self.__videos) or not self.__videos[videoId]:
            return
        self.__dislikes[videoId] += 1

    def getLikesAndDislikes(self, videoId):
        """
        :type videoId: int
        :rtype: List[int]
        """
        if videoId >= len(self.__videos) or not self.__videos[videoId]:
            return [-1]
        return [self.__likes[videoId], self.__dislikes[videoId]]

    def getViews(self, videoId):
        """
        :type videoId: int
        :rtype: int
        """
        if videoId >= len(self.__videos) or not self.__videos[videoId]:
            return -1
        return self.__views[videoId]
