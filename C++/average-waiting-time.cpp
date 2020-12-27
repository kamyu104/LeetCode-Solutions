// Time:  O(n)
// Space: O(1)

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avai = 0, wait = 0;
        for (const auto& c : customers) {
            avai = max(avai, double(c[0])) + c[1];
            wait += avai - c[0];
        }
        return wait / size(customers);
    }
};
