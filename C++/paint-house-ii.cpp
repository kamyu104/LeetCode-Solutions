// Time:  O(n * k)
// Space: O(k)

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        
        vector<vector<int>> min_cost(2, costs[0]);

        const int n = costs.size();
        const int k = costs[0].size();
        for (int i = 1; i < n; ++i) {
            int smallest = numeric_limits<int>::max(), second_smallest = numeric_limits<int>::max();
            for (int j = 0; j < k; ++j) {
                if (min_cost[(i - 1) % 2][j] < smallest) {
                    second_smallest = smallest;
                    smallest = min_cost[(i - 1) % 2][j];
                } else if (min_cost[(i - 1) % 2][j] < second_smallest) {
                    second_smallest = min_cost[(i - 1) % 2][j];
                }
            }
            for (int j = 0; j < k; ++j) {
                const int min_j = (min_cost[(i - 1) % 2][j] != smallest) ? smallest : second_smallest;
                min_cost[i % 2][j] = costs[i][j] + min_j;
            }
        }

        return *min_element(min_cost[(n - 1) % 2].begin(), min_cost[(n - 1) % 2].end());
    }
};

// Time:  O(n * k)
// Space: O(k)
class Solution2{
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        auto combine = [](const vector<int>& tmp, const vector<int>& house) {
                            const int smallest = *min_element(tmp.cbegin(), tmp.cend());
                            const int i = distance(tmp.begin(), find(tmp.cbegin(), tmp.cend(), smallest));
                            vector<int> tmp2(tmp);
                            tmp2.erase(tmp2.begin() + i);
                            const int second_smallest = *min_element(tmp2.cbegin(), tmp2.cend());
                            vector<int> min_cost(tmp.size(), smallest);
                            min_cost[i] = second_smallest;
                            transform(min_cost.begin(), min_cost.end(), house.begin(),
                                      min_cost.begin(), std::plus<int>());
                            return min_cost;
                        };
        vector<int> min_cost = accumulate(costs.cbegin(), costs.cend(), vector<int>(costs[0].size(), 0), combine);
        return *min_element(min_cost.cbegin(), min_cost.cend());

    }
};
