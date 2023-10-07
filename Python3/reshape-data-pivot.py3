# Time:  O(n)
# Space: O(1)

import pandas as pd


# pandas
def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    return df.pivot(index="month", columns="city", values="temperature")
