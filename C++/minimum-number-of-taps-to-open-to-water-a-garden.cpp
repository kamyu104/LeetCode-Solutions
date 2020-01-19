// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> max_range(n + 1);
        for (int i = 0; i < ranges.size(); ++i) {
            int left = max(i - ranges[i], 0), right = min(i + ranges[i], n);
            max_range[left] = max(max_range[left], right - left);
        }
        return jumpGame(max_range);
    }

private:
    int jumpGame(const vector<int>& A) {
        int jump_count = 0, reachable = 0, curr_reachable = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i > reachable) {
                return -1;
            }
            if (i > curr_reachable) {
                curr_reachable = reachable;
                ++jump_count;
            }
            reachable = max(reachable, i + A[i]);
        }
        return jump_count;
    }
};
