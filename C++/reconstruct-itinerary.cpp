// Time:  O(n!)
// Space: O(n)

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> graph;
        for (const auto& ticket : tickets) {
            ++graph[ticket.first][ticket.second];
        }
        const string start = "JFK";
        vector<string> ans{start};
        routeHelper(start, tickets.size(), &graph, &ans);
        return ans;
    }

private:
    bool routeHelper(const string& start, const int size,
             unordered_map<string, map<string, int>> *graph, vector<string> *ans) {

        if (size == 0) {
            return true;
        }

        for (const auto& neighbor : (*graph)[start]) {
            if ((*graph)[start][neighbor.first]) {
                --(*graph)[start][neighbor.first];
                ans->emplace_back(neighbor.first);
                if (dfs(neighbor.first, size - 1, graph, ans)) {
                    return true;
                }
                ans->pop_back();
                ++(*graph)[start][neighbor.first];
            }
        }
        return false;
    }
};
