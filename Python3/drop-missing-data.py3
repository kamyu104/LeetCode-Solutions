# Time:  O(n)
# Space: O(1)

import pandas as pd


# pandas
def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    students.dropna(subset=["name"], inplace=True)
    return students
