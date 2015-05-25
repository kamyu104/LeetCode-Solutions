// Time:  O(C(n, k))
// Space: O(k)

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum3(res, combination, 1, k, n);
        return res;
    }
private:
    void combinationSum3(vector<vector<int> > &res, vector<int> &combination, int start, int k, int n) {
        if (!k && !n) {
            res.push_back(combination);
            return;
        } else if (k < 0) {
            return;
        }

        for (int i = start; i < 10 && n >=  k * i + k * (k - 1) / 2; ++i) {
            combination.push_back(i);
            combinationSum3(res, combination, i + 1, k - 1, n - i);
            combination.pop_back();
        }
    }
};
