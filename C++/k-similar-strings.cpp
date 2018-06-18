// Time:  O(n * n!/(c_a!*...*c_z!), n is the length of A, B,
//                                  c_a...c_z is the count of each alphabet,
//                                  n = sum(c_a...c_z)
// Space: O(n * n!/(c_a!*...*c_z!)

class Solution {
public:
    int kSimilarity(string A, string B) {
        queue<string> q;
        unordered_set<string> lookup;

        lookup.emplace(A);
        q.emplace(A);
        int result = 0;
        while (!q.empty()) {
            for (int size = q.size() - 1; size >= 0; --size) {
                auto s = q.front(); q.pop();
                if (s == B) {
                    return result;
                }
                int i;
                for (i = 0; s[i] == B[i]; ++i);
                for (int j = i + 1; j < s.length(); ++j){
                    if (s[j] == B[j] || s[i] != B[j]) {
                        continue;
                    }
                    swap(s[i], s[j]);
                    if (!lookup.count(s)) {
                        lookup.emplace(s);
                        q.emplace(s);
                    }
                    swap(s[i], s[j]);
                }
            }
            ++result;
        }
        return result;
    }
};
