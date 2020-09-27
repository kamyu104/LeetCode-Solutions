// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int max_run = -1;
        for (int i = 0, prof = 0, run = 1, waiting = 0, max_prof = 0;
             i < size(customers) || waiting > 0; ++run) {
            if (i < size(customers)) {
                waiting += customers[i++];  // each run i increases people by customers[i]
            }
            int boarding = min(waiting, 4);  // greedy
            waiting -= boarding;
            prof += boarding * boardingCost - runningCost;
            if (prof > max_prof) {
                max_prof = prof;
                max_run = run;
            }
        }
        return max_run;
    }
};
