import numpy as np
import pandas as pd

# Create Series
# series = pd.Series(data, index = index)

ser = pd.Series(np.random.randn(4), index = ['a', 'b', 'c', 'd'])
print(ser)
print(ser.values)