# Analytical Approach for Position Observation Error Correction in IPMSM Sensorless Drives Using Online Multi-Parameter Estimation
This repository contains simulations and code for model-based sensorless control of synchronous machines, integrating a full state observer and parameter estimation. The implementation is provided for both MATLAB (2019B) and Python, showcasing the development and testing of sensorless drive mechanisms.

## Features
Full State Observer and Parameter Estimation: Simulations of the full state Extended Electromotive Force (EEMF) observer for position observation, which includes resistance and q-axis inductance estimation for isotropic motors such as the Surface-Mounted Permanent Magnet Synchronous Motors (SPMSMs).

Multi-Parameter Estimator: Code for extensive experiments and algorithm validation, written in MATLAB and translatable to C through MATLAB code generation.

Matlab simulation results of proposed position correction & parameter estimation under sensorless drive with different initial values. 

![SimResults](./Sim_ParamEst/Sim1.png)


Matlab simulation results of proposed position correction & parameter estimation under sensorless drive with different convergence parameters. 

![SimResults2](./Sim_ParamEst/Sim2.png)


## Contributing & Citing

Contributions to the project are welcome. Please ensure to follow the existing code structure and document any changes or additions clearly.

The Analytical Approach for Position Observation Error Correction in IPMSM Sensorless Drives Using Online Multi-Parameter Estimation is first introducted at
```
@ARTICLE{XXXXXXX,
  author={xxxx},
  journal={xxxx}, 
  title={Analytical Approach for Position Observation Error Correction in IPMSM Sensorless Drives Using Online Multi-Parameter Estimation}, 
  year={xxx},
  volume={xx},
  number={xx},
  pages={xxx},
  }
```

## License

[MIT License](LICENSE.md)

## Contact

For any queries or further discussion regarding the project, please open an issue in this repository or direct connect ziruiliu@hust.edu.cn.