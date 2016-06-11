# Time:  O(nlogf),     n is most recently number of tweets,
#                      f is the number of followings.
# Space: O(u + t + r), u is the number of users,
#                      t is the total number of tweets,
#                      r is the number of followings.

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
            heapq.heappush(max_heap, (-self.__messages[userId][-1][0], userId, 0, len(self.__messages[userId])))
        for id in self.__followings[userId]:
            if self.__messages[id]:
                heapq.heappush(max_heap, (-self.__messages[id][-1][0], id, 0, len(self.__messages[id])))

        result = []
        while max_heap and len(result) < self.__number_of_most_recent_tweets:
            t, id, curr, end = heapq.heappop(max_heap)
            nxt = curr + 1;
            print t, id, curr, end
            if nxt != end:
                heapq.heappush(max_heap, (-self.__messages[id][-(nxt+1)][0], id, nxt, len(self.__messages[id])))
            result.append(self.__messages[id][-(curr+1)][1]);
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


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
