// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (intersect(rec1[0], rec1[2], rec2[0], rec2[2]) &&
                intersect(rec1[1], rec1[3], rec2[1], rec2[3]));
    }

private:
    bool intersect(int p_left, int p_right, int q_left, int q_right) {
        return max(p_left, q_left) < min(p_right, q_right);
    }
};
