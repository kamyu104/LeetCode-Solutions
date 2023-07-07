// Time:  O(nlogn)
// Space: O(n)

// sort, simulation, stack
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> idxs(size(positions));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return positions[a] < positions[b];
        });

        vector<int> stk;
        stk.reserve(size(idxs));
        for (const auto& i : idxs) {
            if (directions[i] == 'R') {
                stk.emplace_back(i);
                continue;
            }
            while (!empty(stk)) {
                if (healths[stk.back()] == healths[i]) {
                    healths[stk.back()] = healths[i] = 0;
                    stk.pop_back();
                    break;
                }
                if (healths[stk.back()] > healths[i]) {
                    healths[i] = 0;
                    --healths[stk.back()];
                    break;
                }                
                healths[stk.back()] = 0;
                --healths[i];
                stk.pop_back();
            }
        }
        
        vector<int> result;
        result.reserve(size(healths));
        for (const auto& x : healths) {
            if (x) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};
