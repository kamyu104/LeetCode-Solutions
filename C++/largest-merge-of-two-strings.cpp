// Time:  O(n * m)
// Space: O(n + m)

class Solution {
public:
    string largestMerge(string word1, string word2) {
        queue<char> q1, q2;
        for (const auto& c : word1) {
            q1.emplace(c);
        }
        for (const auto& c : word2) {
            q2.emplace(c);
        }
        string result;
        while (!empty(q1) || !empty(q2)) {
            if (q1 < q2) {
                swap(q1, q2);
            }
            result.push_back(q1.front()); q1.pop();
        }
        return result;
    }
};
