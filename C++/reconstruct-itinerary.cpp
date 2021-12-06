// Time:  O(|V| + |E|log|V|)
// Space: O(|V| + |E|)

// Hierholzer Algorithm
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        static const string origin{"JFK"};

        unordered_map<string, vector<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].emplace_back(ticket[1]);
        }
        for (auto& [k, v] : adj) {
            sort(rbegin(v), rend(v));
        }
        
        vector<string> result;
        vector<string> stk = {origin};
        while (!empty(stk)) {
            while (!empty(adj[stk.back()])) { 
                auto x = adj[stk.back()].back();
                adj[stk.back()].pop_back();
                stk.emplace_back(x);
                
            }
            result.emplace_back(stk.back());
            stk.pop_back();
        }
        reverse(begin(result), end(result));
        return result;
    }
};

// Time:  O(t! / (n1! * n2! * ... nk!)), t is the total number of tickets, 
//                                       ni is the number of the ticket which from is city i,
//                                       k is the total number of cities.
// Space: O(t)
class Solution2 {
public:
   vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> graph;
        for (const auto& ticket : tickets) {
            ++graph[ticket[0]][ticket[1]];
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
