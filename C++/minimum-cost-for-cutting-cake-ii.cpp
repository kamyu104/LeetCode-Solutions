// Time:  O(mlogm + nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(begin(horizontalCut), end(horizontalCut));
        sort(begin(verticalCut), end(verticalCut));
        int64_t result = 0;
        for (int cnt1 = 1, cnt2 = 1; !empty(horizontalCut) || !empty(verticalCut); ) {
            if (empty(verticalCut) || (!empty(horizontalCut) && horizontalCut.back() > verticalCut.back())) {
                result += horizontalCut.back() * cnt1; horizontalCut.pop_back();
                ++cnt2;
            } else {
                result += verticalCut.back() * cnt2; verticalCut.pop_back();
                ++cnt1;
            }
        }
        return result;
    }
};
