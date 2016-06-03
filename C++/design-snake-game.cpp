// Time:  O(s) per move, S is current length of the snake.
// Space: O(s)

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) :
               width_{width}, height_{height}, score_{0},
               food_{food.begin(), food.end()}, snake_{{0, 0}}  {
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        const auto x = snake_.back().first + direction_[direction].first;
        const auto y = snake_.back().second + direction_[direction].second;
        const auto tail = snake_.back();
        
        snake_.pop_front();
        if (!valid(x, y)) {
            return -1;
        } else if (!food_.empty() && food_.front().first == x && food_.front().second == y) {
            ++score_;
            food_.pop_front();
            snake_.push_front(tail);
        }
        snake_.push_back({x, y});
        return score_;
    }

private:
    bool valid(int x, int y) {
        if (x < 0 || x >= height_ || y < 0 || y >= width_) {
            return false;
        }
        for (const auto& p : snake_) {
            if (x == p.first && y == p.second) {
                return false;
            }
        }
        return true;
    }
    int width_, height_, score_;
    deque<pair<int, int>> food_, snake_;
    unordered_map<string, pair<int, int>> direction_ = {{"U", {-1, 0}}, {"L", {0, -1}},
                                                        {"R", {0, 1}}, {"D", {1, 0}}};
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
 
 
