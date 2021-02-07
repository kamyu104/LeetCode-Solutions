# Time:  O(n^2)
# Space: O(n)

SELECT DISTINCT l1.account_id
FROM   loginfo l1
       INNER JOIN loginfo l2
               ON l1.account_id = l2.account_id
                  AND l1.ip_address != l2.ip_address
WHERE  NOT (l1.login > l2.logout
            OR l1.logout < l2.login); 
