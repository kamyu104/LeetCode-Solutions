# Time:  O(n * c), c is the max of subtask count
# Space: O(n * c)

WITH RECURSIVE CTE AS
  (SELECT 1 AS subtask_id
   UNION ALL SELECT subtask_id + 1
   FROM CTE
   WHERE subtask_id <
       (SELECT MAX(subtasks_count)
        FROM Tasks) )
SELECT Tasks.task_id,
       CTE.subtask_id
FROM CTE
INNER JOIN Tasks ON CTE.subtask_id <= Tasks.subtasks_count
LEFT JOIN Executed ON Tasks.task_id = Executed.task_id
                      AND CTE.subtask_id = Executed.subtask_id
WHERE Executed.subtask_id IS NULL
ORDER BY NULL;
