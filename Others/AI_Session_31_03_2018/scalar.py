from sklearn.preprocessing import StandardScaler

StdSc = StandardScaler()
X_data = [30,35,40,50]
StdSc = StdSc.fit(X_data)
X_Scaled = StdSc.transform(X_data)
print(X_Scaled)

'''

import iris data

'''