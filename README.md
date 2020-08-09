# OctoRotor
>A matlab simulator of octorotor drone
## INTRODUCTION
This is a Octorotor simulator written with Matlab2014a Simulink, problems may occur in other version.

The simulator consists of 4 parts: Model, Control, Filt and Decision
![image](https://github.com/SeasonIrving/OctoRotor/blob/master/Simulator%20Structure.png)

 Once started, the simulator will implement a task of crop protection：

     A. Following a Z-shape trajectory.

     B. Go home for charge after a certain working time.

 ![image](https://github.com/SeasonIrving/OctoRotor/blob/master/Task%20Description.jpg)

## Code Index
> finishi.slx: 
> The main simulink code

> sat.m: 
> A satuation function used in low-level control



