// Time:  ctor:    O(1)
//        join:    O(logu + c), u is the number of total joined users
//        leave:   O(logu + c), c is the number of chunks
//        request: O(u)
// Space: O(u * c)

// "u ~= n" solution, n is the average number of users who own the chunk
class FileSharing {
public:
    FileSharing(int m) {
        
    }
    
    int join(vector<int> ownedChunks) {
        int userID = users_.size() + 1;
        if (!min_heap_.empty()) {
            userID = min_heap_.top();
            min_heap_.pop();
        } else {
            users_.emplace_back();
        }
        for (const auto& chunk : ownedChunks) {
            users_[userID - 1].emplace(chunk);
        }
        lookup_.emplace(userID);
        return userID;
    }
    
    void leave(int userID) {
        if (!lookup_.count(userID)) {
            return;
        }
        lookup_.erase(userID);
        users_[userID - 1].clear();
        min_heap_.emplace(userID);
    }
    
    vector<int> request(int userID, int chunkID) {
        vector<int> result;
        for (int i = 0; i < users_.size(); ++i) {
            if (users_[i].count(chunkID)) {
                result.emplace_back(i + 1);
            }
        }
        if (!result.empty()) {
            users_[userID - 1].emplace(chunkID);
        }
        return result;
    }

private:
    vector<unordered_set<int>> users_;
    unordered_set<int> lookup_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;
};

// Time:  ctor:    O(1)
//        join:    O(logu + c), u is the number of total joined users
//        leave:   O(logu + c), c is the number of chunks
//        request: O(nlogn)   , n is the average number of users who own the chunk
// Space: O(u * c + m)
// "u >> n" solution
class FileSharing2 {
public:
    FileSharing2(int m) {
        
    }
    
    int join(vector<int> ownedChunks) {
        int userID = users_.size() + 1;
        if (!min_heap_.empty()) {
            userID = min_heap_.top();
            min_heap_.pop();
        } else {
            users_.emplace_back();
        }
        for (const auto& chunk : ownedChunks) {
            users_[userID - 1].emplace(chunk);
            chunks_[chunk].emplace(userID);
        }
        lookup_.emplace(userID);
        return userID;
    }
    
    void leave(int userID) {
        if (!lookup_.count(userID)) {
            return;
        }
        lookup_.erase(userID);
        for (const auto& chunk : users_[userID - 1]) {
            chunks_[chunk].erase(userID);
        }
        users_[userID - 1].clear();
        min_heap_.emplace(userID);
    }
    
    vector<int> request(int userID, int chunkID) {
        vector<int> result(cbegin(chunks_[chunkID]), cend(chunks_[chunkID]));
        sort(begin(result), end(result));
        if (!result.empty()) {
            users_[userID - 1].emplace(chunkID);
            chunks_[chunkID].emplace(userID);
        }
        return result;
    }

private:
    vector<unordered_set<int>> users_;
    unordered_set<int> lookup_;
    unordered_map<int, unordered_set<int>> chunks_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;
};
