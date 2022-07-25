// Time:  ctor:         O(nlogn)
//        changeRating: O(logn)
//        highestRated: O(1)
// Space: O(n)

// bst
class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < size(ratings); ++i) {
            food_to_cuisine_[foods[i]] = cuisines[i];
            food_to_rating_[foods[i]] = ratings[i];
            cuisine_to_rating_foods_[cuisines[i]].emplace(-ratings[i], foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        const int old_rating = food_to_rating_[food];
        const auto& cuisine = food_to_cuisine_[food];
        cuisine_to_rating_foods_[cuisine].erase({-old_rating, food});
        food_to_rating_[food] = newRating;
        cuisine_to_rating_foods_[cuisine].emplace(-newRating, food);
    }
    
    string highestRated(string cuisine) {
        return cbegin(cuisine_to_rating_foods_[cuisine])->second;
    }

private:
    unordered_map<string, string> food_to_cuisine_;
    unordered_map<string, int> food_to_rating_;
    unordered_map<string, set<pair<int, string>>> cuisine_to_rating_foods_;
};
