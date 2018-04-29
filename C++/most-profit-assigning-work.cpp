// Time:  O(mlogm + nlogn), m is the number of workers,
//                        , n is the number of jobs
// Space: O(n)

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        for (int i = 0; i < profit.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        
        int result = 0, i = 0, max_profit = 0;
        for (const auto& ability: worker) {
            while (i < profit.size() && jobs[i].first <= ability) {
                max_profit = max(max_profit, jobs[i++].second);
            }
            result += max_profit;
        }
        return result;
    }
};
