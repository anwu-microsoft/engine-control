# Create Parameters that will be replated by actions from brain
import numpy as np
import scipy.io as sio
import os
import matplotlib.pyplot as plt
import pandas as pd
import random
import scipy.signal as spsig

class Engine():
    def __init__(self, Ki, Kp, dJ):
        self.Ki = Ki  # something engine related...
        self.Kp = Kp  # something engine related...
        self.dJ = dJ  # something engine related...
        self.rpms = None # signal reaction
     


    def update_Ki(self, Ki_new):
        self.Ki = Ki_new # Update to new Ki
        
    def update_Kp(self,Kp_new):
        self.Kp = Kp_new # Update to new Kp
    
    def update_dJ(self,dJ_new):
        self.dJ = dJ_new # update to new dJ

    def run_engine(self):
        """Update inside temperation.
        Describes the inside temperature evolution as a function of all other variables.
        """

        np.array([self.Kp, self.Ki, self.dJ]).astype('double').tofile('binn.bin')
        os.system('engineclosed')
        self.rpms = sio.loadmat('rpms.mat') #Ok we gonna need to redo this for parallelism


 # print the object nicely   
    def __str__(self):
        string_to_print = []
        for key in self.__dict__:
            string_to_print.append("{key}='{value}'".format(key=key, value=self.__dict__[key]))
        return ', '.join(string_to_print)
    
    def __repr__(self):
        return self.__str__() 

    def __iter__(self):
        self.iteration = 0
        return self
    
    def __next__(self):

        if self.iteration <= self.max_iterations - 4:
            Tset1 = self.Tset_schedule[self.iteration+1]
            Tset2 = self.Tset_schedule[self.iteration+2]
            Tset3 = self.Tset_schedule[self.iteration+3]
            Tout_next = self.Tout_schedule[self.iteration]
            self.iteration += 1
        else:
            StopIteration


def time_to_index(days, hours, timestep=5):
	hours_index = int(hours*60/timestep)
	days_index = int(days*24*60/timestep)
	return hours_index + days_index

