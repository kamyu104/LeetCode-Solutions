# Time:  O(nlogn)
# Space: O(n)

SELECT p.product_id,
       p.price * IFNULL(1 - d.discount / 100, 1) AS final_price,
       p.category
FROM products p
LEFT JOIN discounts d ON p.category = d.category
ORDER BY 1;
