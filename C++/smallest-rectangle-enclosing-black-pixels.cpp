// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        const auto searchColumns =
            [](const int mid, const vector<vector<char>>& image, bool has_one) {
                auto it = image.cbegin();
                for (; it < image.cend(); ++it) {
                    if ((*it)[mid] == '1') {
                        break;
                    }
                }
                return (it < image.cend()) == has_one;
            };
        const int left = binarySearch(image, 0, y - 1, searchColumns, true);
        const int right = binarySearch(image, y + 1, int(image[0].size()) - 1, searchColumns, false);

        const auto searchRows =
            [](const int mid, const vector<vector<char>>& image, bool has_one) {
                auto it = image[mid].cbegin();
                for (; it < image[mid].cend(); ++it) {
                    if (*it == '1') {
                        break;
                    }
                }
                return (it < image[mid].cend()) == has_one;
            };
        const int top = binarySearch(image, 0, x - 1, searchRows, true);
        const int bottom = binarySearch(image, x + 1, int(image.size()) - 1, searchRows, false);

        return (right - left) * (bottom - top);
    }
    
    private:
    int binarySearch(const vector<vector<char>>& image, int left, int right,
                     const function<bool(const int mid,
                                         const vector<vector<char>>& image,
                                         bool has_one)>& find,
                     bool has_one) {
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (find(mid, image, has_one)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
