// Time:  O(b^2 * a^(b*(b+1)/2-1)), a is the size of allowed, 
//                                  b is the length of bottom
// Space: O(a + b^2) 

// dfs solution
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<vector<int>>> edges(7, vector<vector<int>>(7));
        for (const auto& s: allowed) {
            edges[s[0] - 'A'][s[1] - 'A'].emplace_back(s[2] - 'A');
        }
        return pyramidTransitionHelper(bottom, edges);
    }
    
private:
    bool pyramidTransitionHelper(const string& bottom, const vector<vector<vector<int>>>& edges) {
        if (bottom.size() == 1) {
            return true;
        }
        for (int i = 0; i < bottom.size() - 1; ++i) {
            if (edges[bottom[i] - 'A'][bottom[i + 1] - 'A'].empty()) {
                return false;
            }
        }
        string new_bottom(bottom.size() - 1, 'A');
        return dfs(bottom, edges, &new_bottom, 0);
    }
    
    bool dfs(const string& bottom, const vector<vector<vector<int>>>& edges, string *new_bottom, int idx) {
        if (idx == bottom.size() - 1) {
            return pyramidTransitionHelper(*new_bottom, edges);
        }
        for (const auto& i : edges[bottom[idx] - 'A'][bottom[idx + 1] - 'A']) {
            (*new_bottom)[idx] = i + 'A';
            if (dfs(bottom, edges, new_bottom, idx + 1)) {
                return true;
            }
        }
        return false;
    }
};
