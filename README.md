# Hair Strand Simulation
This project is the assignment for 2021-22 ASE & CGI Techniques course units. The method used in this project is based on the study at the end of this page.<br>

**NOTE**<br>Gravity is applied by default.


## Hair Detail
|Parameters|Description|
|----------|------------|
|Hair Precision|To control the number of particles used to generate a hair strand|
|Hair Length|To control the length of the hair strand|
|Hair Damping|To simulate the damping coefficient of the hair|
|Time Steps|To control the time steps in algorithm (not the real interframe time)|
|Start Simulation|When it is on, the integrated force will be applied; otherwise, simulation ends and hair strand recover to the default state.|

## Wind Setting
|Parameters|Description|
|----------|------------|
|Direction|The direction of the wind applied in spatial coordinate. Click the 'Apply' button to confirm the modification.|
|Force|The magnitude of force vector.|


## Camera View
Use Alt+Left Mouse Button to rotate the view and Alt+Right Mouse Button to translate camera.<br>Click 'Reset' button to restore its initial state.

<br>
Reference Link :<br>
[M.Müller, T.Y.Kim and N.Chentanez, 2012. Fast Simulation of Inextensible Hair and Fur](https://matthias-research.github.io/pages/publications/FTLHairFur.pdf)