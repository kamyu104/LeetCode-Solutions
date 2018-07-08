// Time:  ctor: O(b)
//        pick: O(1)
// Space: O(b)

class Solution {
public:
    Solution(int N, vector<int> blacklist) :
        n_(N - blacklist.size()) {
        unordered_set<int> whitelist;
        for (int i = n_; i < N; ++i) {
            whitelist.emplace(i);
        }
        for (const auto& black : blacklist) {
            whitelist.erase(black);
        }
        auto white = whitelist.cbegin();
        for (const auto& black : blacklist) {
            if (black < n_) {
                lookup_[black] = *(white++);
            }
        }
    }

    int pick() {
        int index = rand() % n_;
        return lookup_.count(index) ? lookup_[index] : index;
    }

private:
    int n_;
    unordered_map<int, int> lookup_;
};

// Time:  ctor: O(blogb)
//        pick: O(logb)
// Space: O(b)
class Solution2 {
public:
    Solution(int N, vector<int> blacklist) :
        n_(N - blacklist.size()),
        blacklist_(blacklist) {
		
        sort(blacklist_.begin(), blacklist_.end());
    }

    int pick() {
        int index = rand() % n_;
        int left = 0, right = blacklist_.size() - 1;
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            if (index + mid < blacklist_[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return index + left;
    }

private:        
    int n_;
    vector<int> blacklist_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
