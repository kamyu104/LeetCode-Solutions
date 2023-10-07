# Time:  O(n + m)
# Space: O(1)

import pandas as pd


# pandas
def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1, df2])
