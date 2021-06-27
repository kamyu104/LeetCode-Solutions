// Time:  ctor:   O(nlogn)
//        search: O(logn)
//        rent:   O(logn)
//        drop:   O(logn)
//        report: O(logn)
// Space: O(n)

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& e : entries) {
            movie_to_ordered_price_shop_[e[1]].emplace(e[2], e[0]);
            shop_movie_to_price_[e[0]][e[1]] = e[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        for (const auto& [_, s] : movie_to_ordered_price_shop_[movie]) {
            result.emplace_back(s);
            if (size(result) == 5) {
                break;
            }
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        const auto price = shop_movie_to_price_[shop][movie];
        movie_to_ordered_price_shop_[movie].erase(pair(price, shop));
        rented_ordered_price_shop_movie_.emplace(price, shop, movie);
    }
    
    void drop(int shop, int movie) {
        const auto price = shop_movie_to_price_[shop][movie];
        movie_to_ordered_price_shop_[movie].emplace(price, shop);
        rented_ordered_price_shop_movie_.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        for (const auto& [_, s, m] : rented_ordered_price_shop_movie_) {
            result.push_back({s, m});
            if (size(result) == 5) {
                break;
            }
        }
        return result;
    }

private:
    unordered_map<int, set<pair<int, int>>> movie_to_ordered_price_shop_;
    unordered_map<int, unordered_map<int, int>> shop_movie_to_price_;
    set<tuple<int, int, int>> rented_ordered_price_shop_movie_;
};
