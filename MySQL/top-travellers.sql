# Time:  O(m + nlogn) 
# Space: O(m + n) 

SELECT name, 
       Ifnull(Sum(distance), 0) AS travelled_distance 
FROM   users 
       LEFT JOIN rides 
              ON users.id = rides.user_id 
GROUP  BY name 
ORDER  BY travelled_distance DESC, 
          name; 
          
