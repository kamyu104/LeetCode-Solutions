// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        vector<double> errors;
        double lower = 0, upper = 0;
        for (const auto& price : prices) {
            const auto& p = stod(price);
            lower += floor(p);
            upper += ceil(p);
            if (p != floor(p)) {
                errors.emplace_back(p - floor(p));
            }
        }
        if (target < lower || target > upper) {
            return "-1";
        }

        int lowerRoundCount = static_cast<int>(upper - target);
        nth_element(errors.begin(), errors.begin() + lowerRoundCount, errors.end());
        double min_error = 0.0;
        for (int i = 0; i < errors.size(); ++i) {
            if (i < lowerRoundCount) {
                min_error += errors[i];
            } else {
                min_error += 1.0 - errors[i];
            }
        }
        const auto& result = to_string(min_error);
        return result.substr(0, result.find(".") + 4);
    }
};
