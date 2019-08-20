# Use the CS Template for House Energy Optimization and Integrate the Engine Control Simulator. Then solve the problem explained below.

Problem Statement: A customer approached the Microsoft/Bonsai platform to tune their Engine controller. The engine controller’s role is to control the actual_rpm to match a demanded_rpm. The controller has a set of parameters (Ki and Kp) that influence its response. The goal is to tune the controller such that it has the best response to the demanded_rpm. 

Simulator: 

The customer has a simulator of the engine and its controller in matlab – simulink. Details of the model are here: https://www.mathworks.com/help/simulink/examples/engine-timing-model-with-closed-loop-control.html . 

There can be two types of circumstances:  

a) the customer provides simulink file of the model, engineclosed.slx, where the parameters Kp, Ki need to be tuned by passing them from python using Matlab-Engine library in python. You will need matlab and simulink license. This approach is a good exercise for learning simulator integration.  

b) the customer is able to compile the matlab-simulink model to an `engineclosed.exe` and using a python script (`inputsimulinkparameters.py`) you can read and write to a binary file named `binn.bin`, both are provided to you.  This approach does not require matlab/simulink license. You just need to read and write to a `binn.bin` binary file. This approach minimizes simulator integration effort, and you can focus on machine teaching. 

After tuning the controller so that the response in improved, e.g. error between actual and demanded rpm, the customer wants to implement it on its production line. The problem is that engine parts have some variation on them. So, the AI approach should be able to handle these variations and still able to provide good response comparable to a benchmark PI control. 