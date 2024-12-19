// Time:  O(n^2)
// Space: O(n)

// Bellman-Ford Algorithm
class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        const auto& BellmanFord = [](auto& dist, const auto& pairs, const auto& rates) {
            for (int _ = 0; _ < size(pairs); ++_) {
                for (int i = 0; i < size(pairs); ++i) {
                    dist[pairs[i][1]] = max(dist[pairs[i][1]], dist[pairs[i][0]] * rates[i]);
                    dist[pairs[i][0]] = max(dist[pairs[i][0]], dist[pairs[i][1]] * (1.0 / rates[i]));
                }
            }
        };
        
        unordered_map<string, double> dist;
        dist[initialCurrency] = 1.0;
        BellmanFord(dist, pairs1, rates1);
        BellmanFord(dist, pairs2, rates2);
        return dist[initialCurrency];
    }
};
