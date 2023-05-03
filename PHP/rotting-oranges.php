/*
    Time: O(n*m)
    Space: O(n*m)
 */

class Solution {

/**
 * @param Integer[][] $grid
 * @return Integer
 */

    public function orangesRotting($grid) {
        $dir = [-1, 0, 1, 0, -1]; // used for finding all 4 adjacent coordinates
        
        $m = count($grid);
        $n = count($grid[0]);
        
        $q = new SplQueue();
        $fresh = 0; // To keep track of all fresh oranges left
        for ($i = 0; $i < $m; $i++) {
            for ($j = 0; $j < $n; $j++) {
                if ($grid[$i][$j] == 2) {
                    $q->enqueue([$i, $j]);
                }
                if ($grid[$i][$j] == 1) {
                    $fresh++;
                }
            }
        }
        
        $ans = -1; // initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while (!$q->isEmpty()) {
            $sz = $q->count();
            while ($sz--) {
                $p = $q->dequeue();
                for ($i = 0; $i < 4; $i++) {
                    $r = $p[0] + $dir[$i];
                    $c = $p[1] + $dir[$i + 1];
                    if ($r >= 0 && $r < $m && $c >= 0 && $c < $n && $grid[$r][$c] == 1) {
                        $grid[$r][$c] = 2;
                        $q->enqueue([$r, $c]);
                        $fresh--; // decrement by 1 for each fresh orange that now is rotten
                    }
                }
            }
            $ans++; // incremented after each minute passes
        }
        
        if ($fresh > 0) {
            return -1; // if fresh > 0 that means there are fresh oranges left
        }
        if ($ans == -1) {
            return 0; // we initialised with -1, so if there were no oranges it'd take 0 mins.
        }
        
        return $ans;
    }
}