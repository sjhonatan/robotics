import numpy as np 
import numpy.matlib

# soma das matrizes 
A = np.array([[1,0],[0,2]])
B = np.array([[0,1],[1,0]])
C = A + B
print(C)

# soma das linhas 
A = np.array([[1,0],[0,2]])
B = np.array([[0,1],[1,0]])
s_linha = sum(A)
print(s_linha)
# soma dos elementos
A = np.array([[1,0],[0,2]])
B = np.array([[0,1],[1,0]])
soma = sum(sum(A))
print(soma)

A = np.array([[1,0],[0,2]])
B = np.array([[0,1],[1,0]])
C = A - B
print(C)

A = np.array([[1,0],[0,2]])
B = np.array([[0,1],[1,0]])
C = np.matmul(A,B)
print(C)

# transposta
A = np.array([[1,0],[0,2]])
A_transposta = A.T 
print(A_transposta)

# inversa
from numpy.linalg import *
from numpy import linalg as LA

A = np.array([[1,3],[2,0]])
A_inv = inv(A)
print(A_inv)
I = np.matmul(A,A_inv)
print(I) 

A = ([2,2],[4,8])
A_det = LA.det(A)
print(A_det)

A = ([[1,2],[1,2]])
A_n = LA.matrix_power(A, 2)
