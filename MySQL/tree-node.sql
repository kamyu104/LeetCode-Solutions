# Time:  O(n^2)
# Space: O(n)

SELECT
    atree.id,
    IF(ISNULL(atree.p_id),
        'Root',
        IF(atree.id IN (SELECT p_id FROM tree), 'Inner','Leaf')) AS Type
FROM
    tree AS atree
ORDER BY atree.id

