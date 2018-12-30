# Time:  O(klogu), k is most recently number of tweets,
#                  u is the number of the user's following.
# Space: O(t + f), t is the total number of tweets,
#                  f is the total number of followings.

import collections
import heapq


class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__number_of_most_recent_tweets = 10
        self.__followings = collections.defaultdict(set)
        self.__messages = collections.defaultdict(list)
        self.__time = 0

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        self.__time += 1
        self.__messages[userId].append((self.__time, tweetId))

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        max_heap = []
        if self.__messages[userId]:
            heapq.heappush(max_heap, (-self.__messages[userId][-1][0], userId, 0))
        for uid in self.__followings[userId]:
            if self.__messages[uid]:
                heapq.heappush(max_heap, (-self.__messages[uid][-1][0], uid, 0))

        result = []
        while max_heap and len(result) < self.__number_of_most_recent_tweets:
            t, uid, curr = heapq.heappop(max_heap)
            nxt = curr + 1
            if nxt != len(self.__messages[uid]):
                heapq.heappush(max_heap, (-self.__messages[uid][-(nxt+1)][0], uid, nxt))
            result.append(self.__messages[uid][-(curr+1)][1])
        return result

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId != followeeId:
            self.__followings[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        self.__followings[followerId].discard(followeeId)



