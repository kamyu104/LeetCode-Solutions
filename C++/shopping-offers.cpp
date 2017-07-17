// Time:  O(n * 2^n)
// Space: O(n)

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shoppingOffersHelper(price, special, needs, 0);
    }

private:
    int shoppingOffersHelper(const vector<int>& price, const vector<vector<int>>& special, vector<int>& needs, int i) {
        if (i == special.size()) {
            return inner_product(price.begin(), price.end(), needs.begin(), 0);
        }

        int result = shoppingOffersHelper(price, special, needs, i + 1);

        for (int j = 0; j < special[i].size() - 1; ++j) {
            needs[j] -= special[i][j];
        }
        if (all_of(needs.begin(), needs.end(), [](int i) { return i >= 0; })) {
            result = min(result, special[i].back() + shoppingOffersHelper(price, special, needs, i));
        }
        for (int j = 0; j < special[i].size() - 1; ++j) {
            needs[j] += special[i][j];
        }

        return result;
    }
};

