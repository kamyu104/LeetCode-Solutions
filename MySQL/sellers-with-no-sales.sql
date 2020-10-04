# Time:  O(nlogm)
# Space: O(n + m)

SELECT seller_name
FROM seller s
WHERE NOT EXISTS
  (
    SELECT 1
    FROM orders o
    WHERE s.seller_id = o.seller_id AND o.sale_date >= '2020-01-01'
  )
ORDER BY 1;
