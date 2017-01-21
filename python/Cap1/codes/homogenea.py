import numpy as np

T = np.matrix('1 0 0 0; 0 0 -1 3; 0 1 0 1; 0 0 0 1')

Pb = np.matrix('0;1;1;1')

Pa = np.dot(T,Pb)

Pa = Pa[0:3]


