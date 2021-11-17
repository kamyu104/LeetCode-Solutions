// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int result = 0;
        for (int i = 0; i < size(tickets); ++i) {
            result += min(tickets[i], i <= k ? tickets[k]: tickets[k] - 1);
        }
        return result;
    }
};
