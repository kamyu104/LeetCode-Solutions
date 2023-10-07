# Time:  O(n)
# Space: O(1)

import pandas as pd


# pandas
def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    return students.rename(columns={
        "id" : "student_id",
        "first" : "first_name",
        "last" : "last_name",
        "age" : "age_in_years",
    })
