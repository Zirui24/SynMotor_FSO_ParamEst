# Synchronous Machine Model-based Sensorless Control with Full State Observer & Parameter Estimation
This repository demonstrates the model-based synchronous machine sensorless control with parameter estimation.



Both MATLABSimulink(MATLAB 2019B) and python files on full state observer with parameter estimation are given in this project.

In this project:
1.  The "Sim_ParamEst" file gives the simulation on python and matlab of the proposed position error mechanism and proposed multi-parameter estimator
2.  The "Sim_FullStateOb" file gives the simulation on python and matlab of the full state EEMF observer for position observation. And it intergrates resistance and q-axis inductance estimation for isotropic motor, i.e. SPMSM
3.  The "MultiParamEstCode" file gives the hole experiments code based on matlab code generation. The proposed algorithm can be find in "TEST_IPM_2_0/INT/Extra Observer". Also, for those familiar with C code, The observer C code generated separately by matlab can be found in "MultiParamEstCode\CCodeMultiParamEst"

Matlab simulation results of proposed position correction & parameter estimation under sensorless dirve with different initial values. 
![SimResults](./Sim_ParamEst/SimResults.png)


Matlab simulation results of proposed position correction & parameter estimation under sensorless dirve with different convergence parameters. 
![SimResults2](./Sim_ParamEst/SimResults2.png)
