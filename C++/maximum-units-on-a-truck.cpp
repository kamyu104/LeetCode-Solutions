// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes),
             [](const auto& a, const auto& b) {
                 return a[1] > b[1];
             });
        int result = 0;
        for (const auto& boxType : boxTypes) {
            if (truckSize > boxType[0]) {
                truckSize -= boxType[0];
                result += boxType[0] * boxType[1];
            } else {
                result += truckSize * boxType[1];
                break;
            }
        }
        return result;
    }
};
