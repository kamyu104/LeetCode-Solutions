// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string capitalizeTitle(string title) {
        for (int i = 0, j = 0; i <= size(title); ++i) {
            if (i < size(title) && title[i] != ' ') {
                title[i] = tolower(title[i]);
                continue;
            }
            if (i - j > 2) {
                title[j] = toupper(title[j]);
            }
            j = i + 1;
        }
        return title;
    }
};
