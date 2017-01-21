from sympy import symbols,Matrix

r11,r12,r13,r21,r22,r23,r31,r32,r33 = symbols('r11 r12 r13 r21 r22 r23 r31 r32 r33')

R = Matrix([[r11,r12,r13],[r21,r22,r23],[r31,r32,r33]])

