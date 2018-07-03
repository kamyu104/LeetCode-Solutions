// Time:  ctor: O(nlogn)
//        pick: O(logn)
// Space: O(n)

class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        _n = N - blacklist.size();
        sort(blacklist.begin(), blacklist.end());
        int prev = 0, count = 0;
        for (const auto& black : blacklist) {
            if (prev != black) {
                _intervals.push_back({prev, black - 1, count});
                count += black - prev;
            }
            prev = black + 1;
        }
        _intervals.push_back({prev, N - 1, count});
    }
    
    int pick() {
        int index = rand() % _n;
        int left = 0, right = _intervals.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            Interval cur = _intervals[mid];
            if (index < cur.accu_count + cur.right - cur.left + 1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        Interval cur = _intervals[left];
        return cur.left + index - cur.accu_count;
    }

private:
    struct Interval {
        int left;
        int right;
        int accu_count;
    };
        
    int _n;
    vector<Interval> _intervals;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
