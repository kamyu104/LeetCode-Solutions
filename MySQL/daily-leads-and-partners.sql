# Time:  O(n)
# Space: O(n)

SELECT date_id,
       make_name,
       COUNT(DISTINCT lead_id) AS unique_leads,
       COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY 1, 2
ORDER BY NULL;
