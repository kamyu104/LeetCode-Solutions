# Time:  O(n)
# Space: O(1)

import pandas as pd


# pandas
def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(
        data=student_data,
        columns=["student_id", "age"],
    )


# Time:  O(n)
# Space: O(n)
import pandas as pd


# pandas
def createDataframe2(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame({k:[x[i] for x in student_data] for i, k in enumerate(["student_id", "age"])})
