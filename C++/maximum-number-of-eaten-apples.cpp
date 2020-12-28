// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        int result = 0;
        for (int i = 0; i < size(apples) || !empty(min_heap); ++i) {
            if (i < size(apples) && apples[i]) {
                min_heap.emplace(i + days[i], i);
            }
            while (!empty(min_heap) &&
                   (min_heap.top().first <= i || apples[min_heap.top().second] == 0)) {
                min_heap.pop();
            }
            if (!empty(min_heap)) {
                --apples[min_heap.top().second];
                ++result;
            }  
        }
        return result;
    }
};
