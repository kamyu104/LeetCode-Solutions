// Time:  add:   O(logn),
//        query: O(c), c is the total count of matching records
// Space: O(n)

class TweetCounts {
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        records_[tweetName].emplace(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        static const unordered_map<string, int> lookup = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
        const auto& delta = lookup.at(freq);
        vector<int> result((endTime - startTime) / delta + 1);
        for (auto it = records_[tweetName].lower_bound(startTime);
             it != records_[tweetName].end() && *it <= endTime; ++it) {
            ++result[(*it - startTime) / delta];
        }
        return result;
    }

private:
    unordered_map<string, multiset<int>> records_;
};

// Time:  add:   O(n),
//        query: O(rlogn), r is the size of result
// Space: O(n)
class TweetCounts2 {
public:
    TweetCounts2() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        auto it = lower_bound(records_[tweetName].begin(), records_[tweetName].end(), time);
        records_[tweetName].insert(it, time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        static const unordered_map<string, int> lookup = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
        const auto& delta = lookup.at(freq);
        vector<int> result;
        for (int i = startTime; i <= endTime; i += delta) {
            int j = min(i + delta, endTime + 1);
            result.emplace_back(distance(lower_bound(records_[tweetName].cbegin(), records_[tweetName].cend(), i),
                                         lower_bound(records_[tweetName].cbegin(), records_[tweetName].cend(), j)));
        }
        return result;
    }

private:
    unordered_map<string, vector<int>> records_;
};

// Time:  add:   O(1),
//        query: O(n)
// Space: O(n)
class TweetCounts3 {
public:
    TweetCounts3() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        records_[tweetName].emplace_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        static const unordered_map<string, int> lookup = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
        const auto& delta = lookup.at(freq);
        vector<int> result((endTime - startTime) / delta + 1);
        for (const auto& t : records_[tweetName]) {
            if (startTime <= t && t <= endTime) {
                ++result[(t - startTime) / delta];
            }
        }
        return result;
    }

private:
    unordered_map<string, vector<int>> records_;
};
