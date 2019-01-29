// Time:  O(n)
// space: O(1)

func mincostTickets(days []int, costs []int) int {
    const MAXINT = int(^uint(0) >> 1)

    durations := [3]int{1, 7, 30}
    W := durations[len(durations) - 1]
    dp := make([]int, W)
    for i, _ := range dp {
        dp[i] = MAXINT
    }
    dp[0] = 0;

    last_buy_days := [3]int{0,0,0}
    for i := 1; i < len(days) + 1; i++ {
    	dp[i % W] = MAXINT
        for j := 0; j < len(durations); j++ {
            for (i - 1 < len(days)) && 
            	(days[i-1] > days[last_buy_days[j]]+durations[j] - 1) {
                last_buy_days[j]++
            }
            dp[i % W] = min(dp[i % W], dp[last_buy_days[j] % W]+costs[j])
        }
    }
    return dp[len(days) % W]
}

func min(X int, Y int) int {
    if X < Y {
        return X
    }
    return Y
}