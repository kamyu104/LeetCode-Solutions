# Time:  O(1)
# Space: O(1)

import pandas as pd


# pandas
def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)
