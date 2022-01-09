// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> order(size(plantTime));
        iota(begin(order), end(order), 0);
        sort(begin(order), end(order),
             [&growTime](const auto& a, const auto& b) {
                return growTime[a] > growTime[b]; 
             });
        int result = 0;
        for (int i = 0, curr = 0; i < size(order); ++i) {
            curr += plantTime[order[i]];
            result = max(result, curr + growTime[order[i]]);
        }
        return result;
    }
};
