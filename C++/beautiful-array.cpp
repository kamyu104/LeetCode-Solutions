// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> result{1};
        while (result.size() < N) {
            vector<int> tmp;
            for (const auto& i : result) {
                tmp.emplace_back(i * 2 - 1);
            }
            for (const auto& i : result) {
                tmp.emplace_back(i * 2);
            }
            result = move(tmp);
        }
        vector<int> tmp = move(result);
        for (const auto& i : tmp) {
            if (i <= N) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
