# Lecture 1: Overview

There are few application of Discrete Differential Geometry:

1. Geometry Processing
2. Shape Analysis
3. Machine Learning
4. Numerical Simulation
5. Architecture&Design
6. Discrete Models of Nature

In a nutshell, **GEOMETRY IS EVERYWHERE**!



### What is Differential Geometry?

___

1. considering ***local properties of shape***
2. considering ***global properties of shape***
3. considering ***local-global relationship***
4. profound impact in 20th century



### What is *Discrete* Differential Geometry?

___

1. No infinity in DDG.
2. modern language in geometric processing
3. increasing:arrow_up: impact in 21st century



### Why *Discrete* Differential Geometry is important?

___

In a nutshell, DDG translate differential geometry into language suitable for **computation**.



### What is discrete setting and smooth setting?

___

(*infml*.): 

**Discrete** setting can be conceived of as ***polyline/mesh*** in Rhino.

**Smooth** setting can be conceived of as ***NURBS-curve/surface*** in Rhino.



### How to convert smooth setting to discrete setting?

___

:bangbang: ***No free lunch*** rule: from smooth setting to discrete setting, there is always something missing!!

We therefore need to determine which properties should be captured.



#### Smooth->Discrete || curves in plane(ok)

___

In the ***smooth*** setting, a *parameterized curve* is a ***map*** taking each point in an *interval* $[0,L]$ of the real line to some point in the plane $\mathbb{R}^2$. For example, the interval is $[0,2\pi]$, the *parameterized curve* $\gamma$ is a circle.

<img src="Lecture 01 Overview.assets/image-20210206224057731.png" alt="image-20210206224057731" style="zoom:50%;" />



In the ***discrete*** setting, a *parameterized curve* is ***piecewise linear***, i.e., it is a sequence of vertices connected by straight line segments. For example, this is a curve broken down into 2 curves. For architects, the discrete setting is merely polyline.

<img src="Lecture 01 Overview.assets/image-20210206232540729.png" alt="image-20210206232540729" style="zoom:50%;" />



#### Smooth->Discrete || Tangent of a curve(not easy)

___

(infml) Curvature = "how much a curve bends" If the curve is a function, then curvature is second derivative. (indicate how the curve will bend along the tangent direction)

<img src="Lecture 01 Overview.assets/image-20210207190335862.png" alt="image-20210207190335862" style="zoom:67%;" />

:x:Convert curvature from smoot setting directly to discrete is hard/impossible.

<img src="Lecture 01 Overview.assets/image-20210207190928719.png" alt="image-20210207190928719" style="zoom:50%;" />

<img src="Lecture 01 Overview.assets/image-20210207191022358.png" alt="image-20210207191022358" style="zoom:50%;" />



#### :question: So what is the equivalent definition of curvature in discrete setting?

___

There are 4:

<img src="Lecture 01 Overview.assets/image-20210207191446310.png" alt="image-20210207191446310" style="zoom:67%;" />

(:bangbang: Most natural discrete quantities are often ***integrated*** rather than *pointwise* values.)  在discrete世界里面大部分的计算都是物与物之间的运算，而不是个体自己的运算。



### Turning Angle

___

How to measure? the ***turning angle*** at the vertex:

<img src="Lecture 01 Overview.assets/image-20210207193156510.png" alt="image-20210207193156510" style="zoom:67%;" />

P.S. The angle of  $\phi$  is measured with the angle the tangent makes with the horizontal. 



### Length Variation

___

#### smooth setting

How to measure?  First let's take a look on the smooth setting:

The fastest way to decrease the length of a curve is to move it in the normal direction, with speed proportional to curvature.

<img src="Lecture 01 Overview.assets/image-20210208113332805.png" alt="image-20210208113332805" style="zoom:50%;" />

For the straight line on the left, there is nothing change.

For the circle(most curvy) in the middle, the length varies a lot.



*fml*. why the motion that most quickly decreases length is $\eta=\kappa N$:

<img src="Lecture 01 Overview.assets/image-20210208113543296.png" alt="image-20210208113543296" style="zoom:50%;" />

#### discrete setting

Suppose we have a single line segment:

$$
l := \lvert b-a\rvert
$$

<img src="Lecture 01 Overview.assets/image-20210208120338862.png" alt="image-20210208120338862" style="zoom:50%;" />

Which motion of  $b$  most quickly increases this length?

Apparently, the direction along the segment. The variation can be denoted as: 

$$
\triangledown_{b}l = (b-a)/l
$$

<img src="Lecture 01 Overview.assets/image-20210208120436678.png" alt="image-20210208120436678" style="zoom:50%;" />

Now think about the ***integration*** among segments. To find the motion that most quickly *increases the **total length*** $L$,
we now just sum the contributions of each segment:

<img src="Lecture 01 Overview.assets/image-20210208121106670.png" alt="image-20210208121106670" style="zoom:50%;" />

Mathematically speaking:
$$
\triangledown_{\gamma_i}L = 2sin(\theta_i/2)N_i
$$

#### sum up

in smooth setting, gradient length = curvature × normal($-\kappa N$)

<img src="Lecture 01 Overview.assets/image-20210208122657422.png" alt="image-20210208122657422" style="zoom:50%;" />

in discrete setting, length variation = *discrete* curvature × *discrete* normal($-\kappa^B_i N_i := 2sin(\theta_i/2)N_i$)

<img src="Lecture 01 Overview.assets/image-20210208123154479.png" alt="image-20210208123154479" style="zoom:50%;" />



*Note: the negative sign here just indicate there might be 2 direction.





### Steiner Formula

___

It says that if we move at a constant speed in the normal direction, then the change in length is proportional to curvature. 

length$(\gamma+\varepsilon N)$=length$(\gamma) - \varepsilon\int_{0}^{L} \kappa(s) ds$

In a nutshell, there is not too much difference from the last one but **3** formula. What's more, there are **2** already seen from last two.

<img src="Lecture 01 Overview.assets/image-20210208123603873.png" alt="image-20210208123603873" style="zoom:50%;" />

Similar from before, for a *constant-distance normal offset*, length will change in ***curved*** regions but not ***flat*** regions

<img src="Lecture 01 Overview.assets/image-20210208124026732.png" alt="image-20210208124026732" style="zoom:50%;" />



(*infml*) the Steiner Formula defines the "***connectivity***" of the offset curves which later become the definition of curvature. You can easily understand if you are Rhino user.

<img src="Lecture 01 Overview.assets/image-20210208124259078.png" alt="image-20210208124259078" style="zoom:50%;" />

Therefore, there are ***3*** kinds of "connectivity":

(A) along a circular arc of radius $\varepsilon$
(B) along a straight line
(C) extend edges until they intersect

<img src="Lecture 01 Overview.assets/image-20210208124739208.png" alt="image-20210208124739208" style="zoom:50%;" />

the total length of A,B, and C are:

length$_A$ = length$(\gamma) - \varepsilon\sum_i\theta_i$		a.k.a Turning Angle

length$_B$ = length$(\gamma) - \varepsilon\sum_i2sin(\theta_i/2)$		a.k.a Length Variation

length$_C$ = length$(\gamma) - \varepsilon\sum_i2tan(\theta_i/2)$		



The corresponding component in Grasshopper is the "***Corners***" option of *Offset Curve*:

<img src="Lecture 01 Overview.assets/image-20210208130830081.png" alt="image-20210208130830081" style="zoom:80%;" />



Steiner’s formula says **change in length** is *proportional* to **curvature**, hence, the curvature can be denoted as followed:

<img src="Lecture 01 Overview.assets/image-20210208152912134.png" alt="image-20210208152912134" style="zoom:50%;" />





### Osculating Circle

#### smooth setting

The curvature is the reciprocal of the radius:
$$
\kappa(p) = \frac{1}{r(p)}
$$


<img src="Lecture 01 Overview.assets/image-20210208161533603.png" alt="image-20210208161533603" style="zoom:50%;" />

#### discrete setting

Similarly, what we do in discrete is that:

consider the ***circumcircle***（外接圆） passing through three ***consecutive*** vertices of a discrete curve.

<img src="Lecture 01 Overview.assets/image-20210208164517777.png" alt="image-20210208164517777" style="zoom:50%;" />

The curvature is also the reciprocal of the circle:
$$
\kappa^{D}_{i} = \frac{1}{r_i} = 2sin(\theta_i)/\omega_i
$$




### Which curvature should we use in application?

___

Just pick the right one for your job!





### Curvature Flow

___

There are many application using curvature.



![curvature-flow](Lecture 01 Overview.assets/curvature-flow.gif)



![curvature-flow1](Lecture 01 Overview.assets/curvature-flow1.gif)





### Apply 4 Formula in Curvature Flow

___

#### smooth setting

A simple version of this topic is ***curve shortening flow***, where a *closed curve* moves in the **normal** direction with **speed**
*proportional* to **curvature**.
$$
\frac{d}{dt}\gamma(s,t) = \kappa(s,t)N(s,t)
$$


<img src="Lecture 01 Overview.assets/image-20210208180418134.png" alt="image-20210208180418134" style="zoom:50%;" />

**3** key properties in **curve shortening flow**:

• (**TOTAL**) Total curvature **remains** constant throughout the flow.
• (**DRIFT**) The **center of mass** does not drift from the origin.
• (**ROUND**) Up to rescaling, the flow is **stationary** for circular curves.



#### discrete setting

*No Free Lunch!!

(iterative process)We can approximate curvature flow by ***repeatedly*** moving each vertex a little bit in the **direction** of the **discrete curvature normal**:
$$
\gamma^{t+1} = \gamma^{t} + \tau\kappa_i N_i
$$
<img src="Lecture 01 Overview.assets/image-20210208181119922.png" alt="image-20210208181119922" style="zoom:50%;" />

So which one should we choose? They have their own benefit:

Turning Angle(A),  $\kappa^{A}_{i} = \theta_i$

Length Variation(B),  $\kappa^{B}_{i} = 2sin(\theta_i/2)$

Osculating circle(D),  $\kappa^{D}_{i} = \frac{1}{r_i} = 2sin(\theta_i)/\omega_i$

<img src="Lecture 01 Overview.assets/image-20210208181200654.png" alt="image-20210208181200654" style="zoom:50%;" />

A: It is good at containing the total curvature.

B: It does not drift the mass from center.

D: It has a round shape.