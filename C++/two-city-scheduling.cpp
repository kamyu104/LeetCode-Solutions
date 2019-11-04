// Time:  O(n) ~ O(n^2), O(n) on average.
// Space: O(1)

// quick select solution
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        static auto cmp = [](auto &a, auto &b) {
            return a[0] - a[1] < b[0] - b[1];    
        };       

        nth_element(costs.begin(),
                    costs.begin() + costs.size() / 2,
                    costs.end(),
                    cmp);
        
        int result = 0;
        for (int i = 0; i < costs.size(); ++i) {
            result += (i < costs.size() / 2) ? costs[i][0] : costs[i][1]; 
        }
        return result;
    }
};
