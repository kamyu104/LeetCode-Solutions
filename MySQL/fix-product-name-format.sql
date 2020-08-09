# Time:  O(nlogn)
# Space: O(n)

SELECT LOWER(TRIM(product_name)) product_name,
       substring(sale_date, 1, 7) sale_date,
       count(sale_id) total
FROM sales
GROUP BY 1, 2
ORDER BY 1, 2;
