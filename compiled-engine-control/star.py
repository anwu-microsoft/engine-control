import copy
from collections import deque

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

import bonsai_tools
from simulator_integration import Model

class Star():
	"""
	Definition of  State, Terminal, Actions, Reward. 
	For new experiments, you should modify the following methods:

	1. `get_state`: observe new states from the simulator, and define them in an attribute
	2. `get_terminal`: the terminal condition
	3. `set_action`: receive brain action, transform, output action and call simulator.model_step. 
	4. `brain_action_to_sim_action`: transform brain action to the form needed for `set_action`.
	5. `get_reward`: calculate reward from last step
	6. `simulator_reset_config`: get next state and reset configurations.
	"""

	def __init__(self, predict=False):

		self.model = Model(predict=predict)
		self.simulator_reset_config()

	def get_state(self):
		"""Get state observations from simulator, transform observations to state sent to BRAIN, executed every iteration.
		"""
		self.observations = self.model.simulator_get_observations()
		self.state = {

			#What the brain controls
			'Ki': float(self.observations['Ki']),
			'Kp': float(self.observations['Kp']),

			#What we monitor
			'peak_time': float(self.observations['peak_time']),
			'rise_time': float(self.observations['rise_time']),
			'settling_time': float(self.observations['settling_time']),

			'settling_min': float(self.observations['settling_min']),
			'settling_max': float(self.observations['settling_max']),


			#Can define more state variables here if desired.
		}

		# TODO: normalize?

		return self.state

	def get_terminal(self, state):
		"""Terminal condition check
		
		Parameters
		----------
		state : dict
			dictionary containing state variables
		
		Returns
		-------
		boolean
			terminal condition or not (True means terminal)
		"""
		
		return self.model.iteration > 0 # New iteration at every try

	def set_action(self, brain_action):
		"""Set action and submit to simulator
		
		Takes brain_action as input, transforms it if necessary for input and sets sim_action to simulator, runs the simulator one step

		Parameters
		----------
		brain_action : action
		"""
		self.brain_action = brain_action
		self.sim_action = self.brain_action_to_sim_action(brain_action)
		self.model.simulator_step(self.sim_action)

	def brain_action_to_sim_action(self, brain_action):
		"""Convert brain_action -> sim_action
		Takes brain action and transforms it to sim action (action actually applied to the environment)
		"""
		return brain_action
		#return {key: 1 if brain_action[key] > 0 else 0 for key in brain_action}

	def get_reward(self, state, terminal):
		"""Return reward value
		
		Parameters
		----------
		state : dict
			State values
		terminal : boolean 
			Terminal state
		
		Returns
		-------
		double
			Reward value
		"""
        
        #TBD

		deltaT = np.abs(self.state['Tset']-self.state['Tin'])
		min_deltaT = 1
		if deltaT <= min_deltaT:
			reward = -deltaT+1
		else:
			reward = 0
            
            
		reward = 1-deltaT
        
		return reward

	def simulator_reset_config(self, config=None):
		"""Reset simulator configuration
		"""

		self.config = {'K': 0.5, 'C': 0.3}
		self.model.simulator_reset()

		self.initial_action = {'hvacON':1}
		self.sim_action = self.initial_action
		self.brain_action = self.initial_action
		self.state = self.get_state()


	def define_logged_observations(self):
		"""Log actions and states.
		Defines the logged_observations dictionary which will be logged in file
		"""
		logged_observations = {}
		logged_observations.update(self.observations)
		logged_observations.update(self.state)
		logged_observations.update(self.config)
		logged_observations.update(bonsai_tools.rename_action(self.brain_action,'brain'))
		logged_observations.update(bonsai_tools.rename_action(self.sim_action,'sim'))		
		return logged_observations

def simple_brain_controller(state):
	# Application Specific Controller specific to House Energy
	
	if state['Tin'] < state['Tset']:
		command = 0
	else:
		command = 1
	action = {'hvacON':command}
	return action

if __name__ == "__main__":
	"""use star.py as main to test star piece without bonsai platform in the loop
	"""
	# TODO: provide some instructions for testing
	print("Testing star.py")
	star = Star()
	star.simulator_reset_config()
	state = star.get_state()
	

	#model = Model()
	#model.simulator_initialize()
	#model.simulator_reset()
	#observations = model.simulator_get_observations()
	observations_df = pd.DataFrame()
	for i in range(284):
		brain_action = simple_brain_controller(state)
		sim_action = star.brain_action_to_sim_action(brain_action)
		star.set_action(sim_action)
		state = star.get_state()
		#model.simulator_step(action)
		terminal = star.get_terminal(state)
		reward = star.get_reward(state, terminal)
		print(state)

		observations = star.model.simulator_get_observations()
		observations.update(state)
		observations.update({'terminal':terminal})
		observations.update({'reward':reward})
		observations.update({'brain_action':brain_action})
		observations.update({'sim_action':sim_action})
		observations_df = observations_df.append(observations,ignore_index=True)
		print(observations)	

	observations_df.plot(title='simulation integration plot')
	plt.xlabel('iteration count')
	plt.ylabel('observations')
	plt.show()
