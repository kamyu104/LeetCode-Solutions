// Time:  O(n)
// Space: O(n)

// sliding window, two pointers, mono deque
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int result = 0;
        deque<int> dq;
        int64_t curr = 0;
        int right = 0, left = 0;
        for (; right < size(chargeTimes); ++right) {
            while (!empty(dq) && chargeTimes[dq.back()] <= chargeTimes[right]) {
                dq.pop_back();
            }
            dq.emplace_back(right);
            curr += runningCosts[right];
            if (chargeTimes[dq[0]] + (right - left + 1) * curr > budget) {
                if (dq[0] == left) {
                    dq.pop_front();
                }
                curr -= runningCosts[left++];
            }
        }
        return right - left;
    }
};

// Time:  O(n)
// Space: O(n)
// sliding window, two pointers, mono deque
class Solution2 {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int result = 0;
        deque<int> dq;
        int64_t curr = 0;
        for (int right = 0, left = 0; right < size(chargeTimes); ++right) {
            while (!empty(dq) && chargeTimes[dq.back()] <= chargeTimes[right]) {
                dq.pop_back();
            }
            dq.emplace_back(right);
            curr += runningCosts[right];
            while (!empty(dq) && chargeTimes[dq[0]] + (right - left + 1) * curr > budget) {
                if (dq[0] == left) {
                    dq.pop_front();
                }
                curr -= runningCosts[left++];
            }
            result = max(result, right - left + 1);            
        }
        return result;
    }
};
