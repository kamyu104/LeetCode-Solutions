// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res{0};
        for (int i = 0, cnt = res.size();
             res.size() <= num;
             i = (i + 1) % cnt) {
            if (i == 0) {
                cnt = res.size();
            }
            res.emplace_back(res[i] + 1);
        }
        return res;
    }
};
