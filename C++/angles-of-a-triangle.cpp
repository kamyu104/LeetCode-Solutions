// Time:  O(1)
// Space: O(1)

// math, law of cosines
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        ranges::sort(begin(sides), end(sides));
        const auto& a = sides[0], &b = sides[1], &c = sides[2];
        return a + b > c ? vector<double>{
            acos((b * b + c * c - a * a) / (2.0 * b * c)) * (180.0 / numbers::pi),
            acos((a * a + c * c - b * b) / (2.0 * a * c)) * (180.0 / numbers::pi),
            acos((a * a + b * b - c * c) / (2.0 * a * b)) * (180.0 / numbers::pi)
        } : vector<double>{};
    }
};
