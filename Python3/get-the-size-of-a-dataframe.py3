# Time:  O(1)
# Space: O(1)

import pandas as pd


# pandas
def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return list(players.shape)
