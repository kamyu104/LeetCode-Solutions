// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        vector<int> s;
        for (const auto& v : pushed) {
            s.emplace_back(v);
            while (!s.empty() &&
                   i < popped.size() &&
                   s.back() == popped[i]) {
                s.pop_back();
                ++i;
            }
        }
        return i == popped.size();
    }
};
