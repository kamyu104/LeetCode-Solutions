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
        const string from{"JFK"};
        vector<string> ans{from};
        routeHelper(from, tickets.size(), &graph, &ans);
        return ans;
    }

private:
    bool routeHelper(const string& from, const int ticket_cnt,
                     unordered_map<string, map<string, int>> *graph, vector<string> *ans) {

        if (ticket_cnt == 0) {
            return true;
        }

        for (auto& to : (*graph)[from]) {
            if (to.second) {
                --to.second;
                ans->emplace_back(to.first);
                if (routeHelper(to.first, ticket_cnt - 1, graph, ans)) {
                    return true;
                }
                ans->pop_back();
                ++to.second;
            }
        }
        return false;
    }
};
