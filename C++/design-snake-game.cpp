// Time:  O(1) per move
// Space: O(s), s is the current length of the snake.

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food)
     : food_(food)
     , f_{0}
     , width_{width}
     , height_{height}
     , score_{0}
     , snake_{{0, 0}}
     , lookup_{{0}} {
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        const auto x = snake_.back()[0] + direction_[direction].first;
        const auto y = snake_.back()[1] + direction_[direction].second;
        const auto tail = snake_.front();
        lookup_.erase(hash(tail[0], tail[1]));
        snake_.pop_front();
        if (!valid(x, y)) {
            return -1;
        } else if (f_ != size(food_) && food_[f_][0] == x && food_[f_][1] == y) {
            ++score_;
            ++f_;
            snake_.push_front(tail);
            lookup_.emplace(hash(tail[0], tail[1]));
        }
        snake_.push_back({x, y});
        lookup_.emplace(hash(x, y));
        return score_;
    }

private:
    bool valid(int x, int y) {
        if (x < 0 || x >= height_ || y < 0 || y >= width_) {
            return false;
        }
        return !lookup_.count(hash(x, y));
    }

    int hash(int x, int y) {
        return x * width_ + y;
    }

    const vector<vector<int>>& food_;
    int f_, width_, height_, score_;
    deque<vector<int>> snake_;
    unordered_set<int> lookup_;
    unordered_map<string, pair<int, int>> direction_ = {{"U", {-1, 0}}, {"L", {0, -1}},
                                                        {"R", {0, 1}}, {"D", {1, 0}}};
};
