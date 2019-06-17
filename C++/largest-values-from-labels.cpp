// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> val_labs;
        unordered_map<int, int> count;
        for (int i = 0; i < values.size(); ++i) {
            val_labs.emplace_back(values[i], labels[i]);
        }
        sort(val_labs.begin(), val_labs.end(), greater<pair<int, int>>());
        
        int result = 0;
        for (int i = 0; num_wanted && i < val_labs.size(); ++i) {
            int val, lab;
            tie(val, lab) = val_labs[i];
            if (count[lab] >= use_limit) {
                continue;
            }
            result += val;
            ++count[lab];
            --num_wanted;
        }
        return result;
    }
};
