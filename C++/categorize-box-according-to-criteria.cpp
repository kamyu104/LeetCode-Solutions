// Time:  O(1)
// Space: O(1)

// math, implementation
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = (length >= 10'000  || width >= 10'000 || height >= 10'000) ||
                     1ll * length * width * height >= 1'000'000'000;
        bool heavy = mass >= 100;
        if (bulky && heavy) {
            return "Both";
        }
        if (bulky) {
            return "Bulky";
        }
        if (heavy) {
            return "Heavy";
        }
        return "Neither";
    }
};

// Time:  O(1)
// Space: O(1)
// math, implementation
class Solution2 {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        static const vector<string> CATEGORIES = {"Neither", "Heavy", "Bulky", "Both"};
        const int i = 2 * ((length >= 10'000  || width >= 10'000 || height >= 10'000) ||
                      1ll * length * width * height >= 1'000'000'000) + (mass >= 100);
        return CATEGORIES[i];
    }
};
