# Time:  O(nlogn)
# Space: O(n)

SELECT gender, 
       day, 
       CASE 
         WHEN gender = 'F' THEN @f_accu := @f_accu + score_points 
         ELSE @m_accu := @m_accu + score_points 
       END total 
FROM   scores, 
       (SELECT @f_accu := 0, 
               @m_accu := 0) init 
ORDER  BY gender, 
          day 
