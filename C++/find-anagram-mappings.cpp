// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, queue<int>> lookup;
        for (int i = 0; i < B.size(); ++i) {
            lookup[B[i]].emplace(i);
        }
        vector<int> result;
        for (const auto& n : A) {
            result.emplace_back(lookup[n].back());
            lookup[n].pop();
        }
        return result;
    }
};
