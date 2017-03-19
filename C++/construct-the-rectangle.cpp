// Time:  O(1)
// Space: O(1)

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area % w) {
            --w;
        }
        return {area / w, w};
    }
};
