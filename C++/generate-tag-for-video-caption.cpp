// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    string generateTag(string caption) {
        static const int L = 100;

        string result = "#";
        result.reserve(L);
        for (int i = 0; i < size(caption); ++i) {
            if (caption[i] == ' ') {
                continue;
            }
            result.push_back(i == 0 || caption[i - 1] == ' ' ? toupper(caption[i]) : tolower(caption[i]));
            if (size(result) == L) {
                break;
            }
        }
        if (1 < size(result)) {
            result[1] = tolower(result[1]);
        }
        return result;
    }
};
