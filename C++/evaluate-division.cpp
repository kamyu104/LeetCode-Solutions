// Time:  O(e + q * e)
// Space: O(e)

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
        vector<double>& values, vector<pair<string, string>> query) {

        unordered_map<string,unordered_map<string, double>> lookup;
        vector<double> result;
        for (int i = 0; i < values.size(); ++i) {
            lookup[equations[i].first].emplace(equations[i].second, values[i]);
            if (values[i] != 0) {
                lookup[equations[i].second].emplace(equations[i].first, 1 / values[i]);
            }
        }

        for (const auto& i : query) {
            unordered_set<string> visited;
            auto tmp = check(i.first, i.second, lookup, &visited);
            if (tmp.first) {
                result.emplace_back(tmp.second);
            } else {
                result.emplace_back(-1);
            }
        }
        return result;
    }

private:
    pair<bool, double> check(string up, string down, 
            unordered_map<string,unordered_map<string, double>> &lookup,
            unordered_set<string> *visited) {
        if (lookup[up].find(down) != lookup[up].end()) {
            return {true, lookup[up][down]};
        }
        for (const auto& i : lookup[up]) {
            if (!visited->count(i.first)) {
                visited->emplace(i.first);
                const auto tmp = check(i.first, down, lookup, visited);
                if (tmp.first) {
                    return {true, i.second * tmp.second};
                }
            }
        }
        return {false, 0};
    }
};
