// Time:  O(nlogp), p is total pages.
// Space: O(1)

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        if (k >= pages.size()) {
            return *max_element(pages.cbegin(), pages.cend());
        }

        int sum = 0;
        for (const auto& page : pages) {
            sum += page;
        }
        int average = sum / k;   // Lower bound.
        return binary_search(pages, k, average, sum);
    }

    int binary_search(const vector<int> &pages,
                      const int k, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (valid(pages, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    // Check whether everyone copying at most x pages works or not. 
    bool valid(const vector<int> &pages, const int k, const int x) {
        int sum = 0;
        int people = 0;
        for (int i = 0; i < pages.size() && people < k; ++i) {
            if (sum + pages[i] > x) {
                sum = 0;
                ++people;
            }
            sum += pages[i];
        }
        return  people < k && sum <= x;
    }
};
