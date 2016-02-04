// Time:  O(t! / (n1! * n2! * ... nk!)), t is the total number of tickets, 
//                                       ni is the number of ticket which from is node i,
//                                       k is the total number of cities.
// Space: O(t)

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> graph;
        for (const auto& ticket : tickets) {
            ++graph[ticket.first][ticket.second];
        }
        const string start{"JFK"};
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

        for (auto& neighbor : (*graph)[start]) {
            if (neighbor.second) {
                --neighbor.second;
                ans->emplace_back(neighbor.first);
                if (routeHelper(neighbor.first, size - 1, graph, ans)) {
                    return true;
                }
                ans->pop_back();
                ++neighbor.second;
            }
        }
        return false;
    }
};
