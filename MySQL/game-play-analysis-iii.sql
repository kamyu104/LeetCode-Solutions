# Time:  O(nlogn)
# Space: O(n)

SELECT player_id, 
       event_date, 
       @accum := games_played + ( @prev = ( @prev := player_id ) ) * @accum 
       games_played_so_far 
FROM   activity, 
       (SELECT @accum := 0, 
               @prev := -1) init 
ORDER  BY player_id, 
          event_date 
