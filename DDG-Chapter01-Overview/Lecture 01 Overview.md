# Lecture 1: Overview

There are few application of Discrete Differential Geometry:

1. Geometry Processing
2. Shape Analysis
3. Machine Learning
4. Numerical Simulation
5. Architecture&Design
6. Discrete Models of Nature

In a nutshell, **GEOMETRY IS EVERYWHERE**!



##### What is Differential Geometry?

___

1. considering ***local properties of shape***
2. considering ***global properties of shape***
3. considering ***local-global relationship***
4. profound impact in 20th century



##### What is *Discrete* Differential Geometry?

___

1. No infinity in DDG.
2. modern language in geometric processing
3. increasing:arrow_up: impact in 21st century



##### Why *Discrete* Differential Geometry is important?

___

In a nutshell, DDG translate differential geometry into language suitable for **computation**.



##### What is discrete setting and smooth setting?

___

(*infml*.): 

**Discrete** setting can be conceived of as ***polyline/mesh*** in Rhino.

**Smooth** setting can be conceived of as ***NURBS-curve/surface*** in Rhino.



##### How to convert smooth setting to discrete setting?

___

:bangbang: ***No free lunch*** rule: from smooth setting to discrete setting, there is always something missing!!

We therefore need to determine which properties should be captured.



##### Smooth->Discrete || curves in plane(ok)

___

In the ***smooth*** setting, a *parameterized curve* is a ***map*** taking each point in an *interval* $[0,L]$ of the real line to some point in the plane $\mathbb{R}^2$. For example, the interval is $[0,2\pi]$, the *parameterized curve* $\gamma$ is a circle.

<img src="Lecture 01 Overview.assets/image-20210206224057731.png" alt="image-20210206224057731" style="zoom:50%;" />



In the ***discrete*** setting, a *parameterized curve* is ***piecewise linear***, i.e., it is a sequence of vertices connected by straight line segments. For example, this is a curve broken down into 2 curves. For architects, the discrete setting is merely polyline.

<img src="Lecture 01 Overview.assets/image-20210206232540729.png" alt="image-20210206232540729" style="zoom:50%;" />

