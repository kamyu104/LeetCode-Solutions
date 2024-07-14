// Time:  O(mlogm + nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(begin(horizontalCut), end(horizontalCut));
        sort(begin(verticalCut), end(verticalCut));
        int64_t result = 0;
        for (int cnt_h = 1, cnt_v = 1; !empty(horizontalCut) || !empty(verticalCut); ) {
            if (empty(verticalCut) || (!empty(horizontalCut) && horizontalCut.back() > verticalCut.back())) {
                result += horizontalCut.back() * cnt_h; horizontalCut.pop_back();
                ++cnt_v;
            } else {
                result += verticalCut.back() * cnt_v; verticalCut.pop_back();
                ++cnt_h;
            }
        }
        return result;
    }
};

// Time:  O(mlogm + nlogn)
// Space: O(1)
// sort, greedy
class Solution2 {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(begin(horizontalCut), end(horizontalCut), greater<int>());
        sort(begin(verticalCut), end(verticalCut), greater<int>());
        int64_t result = 0;
        for (int i = 0, j = 0; i < size(horizontalCut) || j < size(verticalCut); ) {
            if (j == size(verticalCut) || (i < size(horizontalCut) && horizontalCut[i] > verticalCut[j])) {
                result += horizontalCut[i++] * (j + 1);
            } else {
                result += verticalCut[j++] * (i + 1);
            }
        }
        return result;
    }
};
