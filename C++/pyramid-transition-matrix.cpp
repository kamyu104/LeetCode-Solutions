// Time:  O((a^(b+1)-a)/(a-1)) = O(a^b) , a is the size of allowed, 
//                                        b is the length of bottom
// Space: O((a^(b+1)-a)/(a-1)) = O(a^b) 

// dfs solution
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<vector<int>>> edges(7, vector<vector<int>>(7));
        unordered_set<string> lookup;
        for (const auto& s: allowed) {
            edges[s[0] - 'A'][s[1] - 'A'].emplace_back(s[2] - 'A');
        }
        return pyramidTransitionHelper(bottom, edges, &lookup);
    }
    
private:
    bool pyramidTransitionHelper(const string& bottom, const vector<vector<vector<int>>>& edges,
                                 unordered_set<string> *lookup) {
        if (bottom.size() == 1) {
            return true;
        }
        for (int i = 0; i < bottom.size() - 1; ++i) {
            if (edges[bottom[i] - 'A'][bottom[i + 1] - 'A'].empty()) {
                return false;
            }
        }
        if (lookup->count(bottom)) {
            return false;
        }
        lookup->emplace(bottom);
        string new_bottom(bottom.size() - 1, 'A');
        return dfs(bottom, edges, &new_bottom, 0, lookup);
    }
    
    bool dfs(const string& bottom, const vector<vector<vector<int>>>& edges, string *new_bottom, int idx,
             unordered_set<string> *lookup) {
        if (idx == bottom.size() - 1) {
            return pyramidTransitionHelper(*new_bottom, edges, lookup);
        }
        for (const auto& i : edges[bottom[idx] - 'A'][bottom[idx + 1] - 'A']) {
            (*new_bottom)[idx] = i + 'A';
            if (dfs(bottom, edges, new_bottom, idx + 1, lookup)) {
                return true;
            }
        }
        return false;
    }
};
