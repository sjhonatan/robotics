import numpy as np 
def Reflection_yRot(array):
	R = np.array([[-1, 0], [0, 1]])
	r = np.matmul(R,array)
	return r	

def Reflection_oRot(array):
	R = np.array([[-1,0], [0,-1]])
	r = np.matmul(R,array)
	return r

u = np.array([1,2])

v = Reflection_yRot(u)
print(v)

z = Reflection_oRot(u)
print(z)

