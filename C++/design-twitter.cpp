// Time:  O(klogu), k is most recently number of tweets,
//                  u is the number of the user's following.
// Space: O(t + f), t is the total number of tweets,
//                  f is the total number of followings.

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() : time_(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        messages_[userId].emplace_back(make_pair(++time_, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        using RIT = deque<pair<size_t, int>>::reverse_iterator;
        priority_queue<tuple<size_t, RIT, RIT>> heap;

        if (messages_[userId].size()) {
            heap.emplace(make_tuple(messages_[userId].rbegin()->first,
                                    messages_[userId].rbegin(),
                                    messages_[userId].rend()));
        }
        for (const auto& id : followings_[userId]) {
            if (messages_[id].size()) {
                heap.emplace(make_tuple(messages_[id].rbegin()->first,
                                        messages_[id].rbegin(),
                                        messages_[id].rend()));
            }
        }
        vector<int> res;
        while (!heap.empty() && res.size() < number_of_most_recent_tweets_) {
            const auto& top = heap.top();
            size_t t;
            RIT begin, end;
            tie(t, begin, end) = top;
            heap.pop();

            auto next = begin + 1;
            if (next != end) {
                heap.emplace(make_tuple(next->first, next, end));
            }

            res.emplace_back(begin->second);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId && !followings_[followerId].count(followeeId)) {
            followings_[followerId].emplace(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followings_[followerId].count(followeeId)) {
            followings_[followerId].erase(followeeId);
        }
    }

private:
    const size_t number_of_most_recent_tweets_ = 10;
    unordered_map<int, unordered_set<int>> followings_;
    unordered_map<int, deque<pair<size_t, int>>> messages_;
    size_t time_;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
 
