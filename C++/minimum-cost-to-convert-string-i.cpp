// Time:  O(26^3 + n)
// Space: O(26^2)

// Floyd-Warshall algorithm 
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        static const int INF = numeric_limits<int>::max();
        const auto& floydWarshall = [](auto& dist) {
            for (int k = 0; k < size(dist); ++k) {
                for (int i = 0; i < size(dist); ++i) {
                    for (int j = 0; j < size(dist[0]); ++j) {
                        if (dist[i][k] != INF && dist[k][j] != INF) {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        };

        vector<vector<int>> dist(26, vector<int>(26, INF));
        for (int u = 0; u < size(dist); ++u) {
            dist[u][u] = 0;
        }
        for (int i = 0; i < size(original); ++i) {
            const int u = original[i] - 'a';
            const int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        floydWarshall(dist);
        int64_t result = 0;
        for (int i = 0; i < size(source); ++i) {
            const int u = source[i] - 'a';
            const int v = target[i] - 'a';
            if (dist[u][v] == INF) {
                return -1;
            }
            result += dist[u][v];
        }
        return result;
    }
};
