// Time:  ctor:  O(1)
//        add:   O(1)
//        top:   O(n)
//        reset: O(1)
// Space: O(n)

class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        lookup_[playerId] += score;
    }
    
    int top(int K) {
        vector<int> scores;
        for (const auto& [k, v] : lookup_) {
            scores.emplace_back(v);
        }
        nth_element(scores.begin(), scores.begin() + K, scores.end(), greater<int>());
        return accumulate(scores.cbegin(), scores.cbegin() + K, 0);
    }
    
    void reset(int playerId) {
        lookup_[playerId] = 0;
    }

private:
    unordered_map<int, int> lookup_;
};
