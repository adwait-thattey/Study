import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

X=np.array([[1,1],[2,1],[2,3],[4,4]])
y=np.array([2,3,4,5])

# approximating XA+c=y where, A and c line coefficients

# If you don't have matplotlib comment below code
fig = plt.figure()
ax = plt.axes(projection="3d")
ax.plot3D(X[:,0], X[:,1], y, 'gray')
ax.scatter3D(X[:,0], X[:,1], y, c=y, cmap='hsv')
ax.set_xlabel("X axis")
ax.set_ylabel("Y axis")
ax.set_zlabel("Z axis")
plt.show()



