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

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */


// Time:  ctor: O(nlogn)
//        pick: O(logn)
// Space: O(n)
class Solution2 {
public:
    Solution(int N, vector<int> blacklist) :
        n_(N - blacklist.size()) {
            
        sort(blacklist.begin(), blacklist.end());
        int prev = 0, count = 0;
        for (const auto& black : blacklist) {
            if (prev != black) {
                intervals_.push_back({prev, black, count});
                count += black - prev;
            }
            prev = black + 1;
        }
        intervals_.push_back({prev, N, count});
    }
    
    int pick() {
        int index = rand() % n_;
        int left = 0, right = intervals_.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            const auto& cur = intervals_[mid];
            if (index < cur.accu_count + cur.right - cur.left) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        Interval cur = intervals_[left];
        return cur.left + index - cur.accu_count;
    }

private:
    struct Interval {
        int left;
        int right;
        int accu_count;
    };
        
    int n_;
    vector<Interval> intervals_;
};
