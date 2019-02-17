// Time:  O(n!)
// Space: O(n^2)

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        unordered_map<int, int> count;
        for (const auto& a : A) {
            ++count[a];
        }
        unordered_map<int, unordered_set<int>> candidate;
        for (const auto& i : count) {
            for (const auto& j : count) {
                int x = i.first, y = j.first, s = sqrt(x + y);
                if (s * s == x + y) {
                    candidate[x].emplace(y);
                }
            }
        }

        int result = 0;
        for (const auto& i : count) {
            dfs(candidate, i.first, A.size() - 1, &count, &result);
        }
        return result;
    }

private:
    void dfs(const unordered_map<int, unordered_set<int>>& candidate,
             int x,
             int left,
             unordered_map<int, int> *count,
             int *result) {

        --(*count)[x];
        if (!left) {
            ++(*result);
        }
        if (candidate.count(x)) {
            for (const auto& y : candidate.at(x)) {
                if ((*count)[y] > 0) {
                    dfs(candidate, y, left - 1, count, result);
                }
            }
        }
        ++(*count)[x];
    }
};
