// Time:  O(nlogn)
// Space: O(n)

// sort, greedy
class Solution {
public:
    int maxPotholes(string road, int budget) {
        vector<int> ls;
        for (int i = 0, l = 0; i < size(road); ++i) {
            ++l;
            if (i + 1 == size(road) || road[i + 1] != road[i]) {
                if (road[i] == 'x') {
                    ls.emplace_back(l);
                }
                l = 0;
            }
        }
        sort(begin(ls), end(ls));
        int result = 0;
        for (int i = size(ls) - 1; i >= 0; --i) {
            const int c = min(ls[i] + 1, budget);
            if (c <= 1) {
                break;
            }
            result += c - 1;
            budget -= c;
        }
        return result;
    }
};
