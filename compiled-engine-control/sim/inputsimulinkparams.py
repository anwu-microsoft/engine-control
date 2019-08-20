# Create Parameters that will be replated by actions from brain
import numpy as np
import scipy.io as sio
import os
import matplotlib.pyplot as plt
import random
Kp =0.9
Ki = 0.1
for i in range(5):
    Kp += 0.001
    Ki += 0.05
    dJ = random.uniform(-0.5,0.5)
    np.array([Kp,Ki,dJ]).astype('double').tofile('binn.bin')
    os.system('engineclosed')
    rpms = sio.loadmat('rpms.mat')
    print(rpms)
    plt.plot(rpms['rpms'][0],rpms['rpms'][1],'-.',rpms['rpms'][0],rpms['rpms'][2],'r-.')
    plt.ylabel('test')
    plt.show()


