// Time:  ctor:             O(1)
//        addBid:           O(logn)
//        updateBid:        O(logn)
//        removeBid:        O(logn)
//        getHighestBidder: O(1), amortized
// Space: O(n)

// hash table, heap
class AuctionSystem {
public:
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        bids_[itemId][userId] = bidAmount;
        bidders_[itemId].emplace(bidAmount, userId);
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        bids_[itemId].erase(userId);
        if (empty(bids_[itemId])) {
            bids_.erase(itemId);
        }
    }
    
    int getHighestBidder(int itemId) {
        if (!bidders_.count(itemId)) {
            return -1;
        }
        while (!empty(bidders_[itemId])) {
            const auto [p, u] = bidders_[itemId].top();
            if (bids_[itemId][u] == p) {
                return u;
            }
            bidders_[itemId].pop();
        }
        bidders_.erase(itemId);
        return -1;
    }

private:
    unordered_map<int, unordered_map<int, int>> bids_;
    unordered_map<int, priority_queue<pair<int, int>>> bidders_;
};

// Time:  ctor:             O(1)
//        addBid:           O(logn)
//        updateBid:        O(logn)
//        removeBid:        O(logn)
//        getHighestBidder: O(1)
// Space: O(n)
// hash table, bst
class AuctionSystem2 {
public:
    AuctionSystem2() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if (bids_[itemId].count(userId)) {
            bidders_[itemId].erase({bids_[itemId][userId], userId});
        }
        bids_[itemId][userId] = bidAmount;
        bidders_[itemId].emplace(bidAmount, userId);
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        bidders_[itemId].erase({bids_[itemId][userId], userId});
        if (empty(bidders_[itemId])) {
            bidders_.erase(itemId);
        }
        bids_[itemId].erase(userId);
        if (empty(bids_[itemId])) {
            bids_.erase(itemId);
        }
    }
    
    int getHighestBidder(int itemId) {
        return bidders_.count(itemId) ? rbegin(bidders_[itemId])->second : -1;
    }

private:
    unordered_map<int, unordered_map<int, int>> bids_;
    unordered_map<int, set<pair<int, int>>> bidders_;
};
