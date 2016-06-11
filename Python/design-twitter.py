# Time:  O(nlogf),     n is most recently number of tweets,
#                      f is the number of user's following.
# Space: O(u + t + r), u is the number of users,
#                      t is the total number of tweets,
#                      r is the total number of followings.

# Design a simplified version of Twitter where users can post tweets,
# follow/unfollow another user and is able to see the 10 most recent
# tweets in the user's news feed. Your design should support the following methods:
#
# postTweet(userId, tweetId): Compose a new tweet.
# getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's
# news feed. Each item in the news feed must be posted by users who the user followed
# or by the user herself. Tweets must be ordered from most recent to least recent.
# follow(followerId, followeeId): Follower follows a followee.
# unfollow(followerId, followeeId): Follower unfollows a followee.
# Example:
#
# Twitter twitter = new Twitter();
#
# // User 1 posts a new tweet (id = 5).
# twitter.postTweet(1, 5);
#
# // User 1's news feed should return a list with 1 tweet id -> [5].
# twitter.getNewsFeed(1);
#
# // User 1 follows user 2.
# twitter.follow(1, 2);
#
# // User 2 posts a new tweet (id = 6).
# twitter.postTweet(2, 6);
#
# // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
# // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
# twitter.getNewsFeed(1);
#
# // User 1 unfollows user 2.
# twitter.unfollow(1, 2);
#
# // User 1's news feed should return a list with 1 tweet id -> [5],
# // since user 1 is no longer following user 2.
# twitter.getNewsFeed(1);

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
        for uid in self.__followings[userId]:
            if self.__messages[uid]:
                heapq.heappush(max_heap, (-self.__messages[uid][-1][0], uid, 0, len(self.__messages[uid])))

        result = []
        while max_heap and len(result) < self.__number_of_most_recent_tweets:
            t, uid, curr, end = heapq.heappop(max_heap)
            nxt = curr + 1;
            if nxt != end:
                heapq.heappush(max_heap, (-self.__messages[uid][-(nxt+1)][0], uid, nxt, len(self.__messages[uid])))
            result.append(self.__messages[uid][-(curr+1)][1]);
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
