# Time:  O(n)
# Space: O(n)

import pandas as pd


# pandas
def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.assign(bonus=2*employees["salary"])
