import numpy as np  

u = np.array([3,2,1])
v = np.array([1,2,3])

z = u + v
z = u - v
z = u * v
z = u / v


x = np.arange(0,9)
print(x)
print(x.shape)
print(x.itemsize)

y = x.reshape((3,3))
print(y)
print(y.shape)
print(y.itemsize)

x = np.array([1,1,1])

soma = sum(x)
print(soma)


# Usando inner para produto interno

u = np.array([3,2,1])
v = np.array([1,2,3])

z = np.inner(v,u)

# retorna z = 10

# Usando cross para produto vetorial

i = [1,0,0]
j = [0,1,0]

k = np.cross(i,j)

# Transposta

A = np.array([[1,2,3],[4,5,6],[7,8,9]])
T = A.T
#print(T)

# Transforming into a one dimensional array 

A_flat = A.flatten()
#print(A_flat) 

#print(A.ndim)
#print(A.shape)

import numpy.matlib

# Criando uma matriz vazia 

A = np.matlib.zeros((3,3))

# Criando uma matriz Identidade

I = np.matlib.identity(3)

# Criando matrizes com random 

B = np.matlib.rand((3,3))

# Criando matriz com random mas usando valores da tabela de distribuicao normal

N = np.matlib.randn((3,3))


A = np.array([[1,1,1], [2,2,2], [3,3,3]])
print(A)

x = np.array([1,2,3,4,5,6,7,8,9])

B = x.reshape((3,3))
print(B)