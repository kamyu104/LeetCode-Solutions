// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string a = "ab", b = "ba";
        if (x < y) {
            swap(a, b);
            swap(x, y);
        }
        return remove(s, a, x) + remove(s, b, y);
    }

private:
    int remove(string &s, string a, int x) {
        int i = 0, result = 0;
        for (int j = 0; j < size(s); ++j) {
            s[i++] = s[j];
            if (i >= 2 && s.substr(i - 2, 2) == a) {
                i -= 2;
                result += x;
            }
        }
        s.resize(i);
        return result;
    }
};
