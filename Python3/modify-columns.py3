# Time:  O(n)
# Space: O(1)

import pandas as pd


# pandas
def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.assign(salary=2*employees["salary"])
