from sympy import *
from sympy.physics.mechanics import *
import numpy as np

N = ReferenceFrame('N')
v = 1 * N.x + 2 * N.y + 3 * N.z

print(v)
print(2 * v)
print(np.log(int(v.magnitude())))
print(v.normalize())

u = v.normalize()
print(u.magnitude())

a1, a2, a3 = symbols('a1 a2 a3')
b1, b2, b3 = symbols('b1 b2 b3')

x = a1 * N.x + a2 * N.y + a3 * N.z
y = b1 * N.x + b2 * N.y + b3 * N.z


A = ReferenceFrame('A')
alpha = symbols('alpha')
A.orient(N, 'Axis', [alpha, N.x])

print(A.dcm(N))

A = ReferenceFrame('A')
alpha = symbols('alpha')
A.orient(N, 'Axis', [alpha, N.y])

print(A.dcm(N))


A = ReferenceFrame('A')
alpha = symbols('alpha')
A.orient(N, 'Axis', [alpha, N.z])

print(A.dcm(N))

v.express(A)



