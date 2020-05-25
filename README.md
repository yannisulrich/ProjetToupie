
# Projet de simulation d'une Toupie

Authors: Tanish Patil and Yannis Ulrich.

## Help for application

A general step-by-step instruction list is available inside the app. Here is some additonal information about the tops, the integrators, the parameters, and the plotable values. 

### Parameters
The three angles are Euler angles, and are to be given in radians. The other physical parameters have units indicated. The euler angles follow the convention on figure 1. Psi and phi may be switched from what you are used to. Apostrophes indicate time derivatives. This means that for a primitive test all parameters you really need to set are θ, i.e. how straight your top is, and φ', how fast you let it spin.

<p align="center">
 <img src="https://b7.pngbarn.com/png/682/676/euler-angles-yaw-aircraft-principal-axes-orientation-cartesian-coordinate-system-travel-roll-up-png-clip-art.png" width="300">
 <img src="./EulerAnglesHelpImage.png" width="300">
 <b>Figure 1: Euler angle convention</b><br>
  </p>

Mass means exactly what one would think: it's the mass of the top. For the remaining parameters, the information is specific to each top:
* For the cone, physical parameters are very intuitive. R is the radius of the base, and L is the height. X and y parameters define the position in the plane of the cone's apex. The speeds are ignored, as the position is assumed fixed. Also, friction is always static in this case and thus the μ parameter also doesn't apply. 
* For the rolling Tippe top, R is the radius of the sphere, and h is the height that was truncated off the sphere (see description of tops for details, but this parameter is covariant with the distance between geometric sphere center and center of mass.
* For the slipping Tippe top, 
