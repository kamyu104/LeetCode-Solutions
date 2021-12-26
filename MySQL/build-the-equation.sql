# Time:  O(nlogn)
# Space: O(n)

SELECT 
    CONCAT(
        GROUP_CONCAT(
        CASE 
            WHEN factor > 0 THEN CONCAT('+', factor)
            ELSE factor
        END,
        CASE 
            WHEN power=0 THEN ''
            WHEN power=1 THEN 'X'
            ELSE CONCAT('X^', power)
        END
        ORDER BY power DESC SEPARATOR ''), '=0') AS equation
FROM Terms;
