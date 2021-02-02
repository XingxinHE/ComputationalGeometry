# Intro to Differential Geometry



## 3.1 The Geometry of Surface




#### What is *differential* ?
___
(*infml*) =How to *transform* vectors from one space to another. e.g.The $X$ in the left to $df(X)$ in the right.

<img src="Chapter 03 A quick.assets\image-20210128093534716.png" alt="image-20210128093534716" style="zoom:50%;" />

The above transformation can be described via a map: 

$$
\begin{align}
f:M\rightarrow\mathbb{R}^3
\end{align}
$$

which map a region $M$ in the Euclidean plane $\mathbb{R}^2$ to a subset of $\mathbb{R}^3$ entitled $f(M)$.



Hence, we can say the **differential** of such map tells us how to map a vector $X$ in the plane to the corresponding vector $df(x)$ on the surface. The *differential* denoted as:
$$
\begin{align}
df
\end{align}
$$





#### Different representation of *dot product*
___
In $\mathbb{R}^2$: use angle bracket, e.g.
$$
\begin{align}
\langle X,X\rangle
\end{align}
$$

In $\mathbb{R}^3$: use $\cdot$, e.g.
$$
\begin{align}
df(X)\cdot df(X)
\end{align}
$$





#### *metric* of a surface?

___

*metric* $g$ is the inner product between any two tangent vectors $df(X)$ and $df(Y)$
$$
\begin{align}
g(X,Y) = df(X)\cdot df(Y)
\end{align}
$$



#### *vector field*?

___

A vector at every point of $M$.







#### *tangent bundle*?

___

The set of all tangent vectors of $M$. denoted as $TM$.







#### normal vector

___

a vector  $u\in \mathbb{R}^3$ is normal to the surface at a point $p$ if:
$$
\begin{align}
df(X)\cdot u = 0
\end{align}
$$









#### orientable?

___

If the normal is consistent, then the manifold is *orientable*. e.g. :

The circular band on the left is ***orientable***.

The Mobius band on the right is ***NOT orientable***.

<img src="Chapter 03 A quick.assets/image-20210128113047677.png" alt="image-20210128113047677" style="zoom:50%;" />









#### *Gauss map and Weingarten map?*

___

For *orientable surfaces*, **Gauss map** (denoted as $N$) map the associates each point on the surface with its unit normal. 
$$
N: M \in S^2
$$
Because it must be `each point` and `unit normal`, the result can be illustrated as a sphere, $S^2$ as a subset of $\mathbb{R}^3$.包含所有从原点射出的单位向量 。

<img src="Chapter 03 A quick.assets/image-20210128132251313.png" alt="image-20210128132251313" style="zoom: 50%;" />

The Weingarten map is the differential of $N$ , denoted as $dN$, tell us the change in the normal direction as the point move from one to another. For example, we can look at the change in normal along a particular tangent direction $X$ by evaluating $dN(X)$. 从Strang的微积分Big Picture来看，分析曲面的法向变化就是在分析曲面的curvature.









### 3.1.1 Conformal Coordinates



#### isometric parameterization?

___

a.k.a *arc-length* or *unit speed* parameterization.

(*infml*) You can imagine you select the curve in Rhino to the real 3D world with :heavy_check_mark:***pick up/ bend*** but not :x:***stretched***.

(*fml*) Let $\overrightarrow{p}:\mathbb{R}^n\in S$ be a parameterization of $S$. The parameterization $\overrightarrow{p}$ is called an *isometric parameterization* if the speed of $\overrightarrow{p}$ with respect to each parameter is one and $\overrightarrow{p}$ preserves area.

(*fml*) Another definition is more intuitive:
$$
\lvert df(X)\rvert = \lvert X\rvert
$$
So after the transformation to $\mathbb{R}^3$, the norm of any vector $X$ preserved.

However, isometric parameterization does not always exist. Most of the time you need to stretch things out. e.g. The world map.

<img src="Chapter 03 A quick.assets/image-20210128140413851.png" alt="image-20210128140413851" style="zoom:50%;" />







#### conformal parameterization

___

(*fml*) A map $f$ is ***conformal*** if it preserves the *angle* between any two vectors after the transformation to $\mathbb{R}^3$.
$$
f: \mathbb{R}^2\supset M \rightarrow \mathbb{R}^3
$$
The $f$ satisfies: 
$$
df(X)\cdot df(Y) = a \langle X,Y \rangle
$$
$a$ is a positive function. In practice, $a$ is often replaced with $\mathbb{e}^u$ for some real-valued function $u$. So you don't worry about whether the scaling is positive.

$\langle \cdot ,\cdot \rangle$ is the usual inner product on $\mathbb{R}^2$

<img src="Chapter 03 A quick.assets/image-20210128143048116.png" alt="image-20210128143048116" style="zoom:50%;" />

Notice the surface can get :heavy_check_mark:***stretched out*** while the surface never gets :x:***sheared*** - for instance, orthogonal vectors$X, Y$ always stay orthogonal $df(X), df(Y)$.

conformal parameterization是永远存在的，背后的理论来自Riemann的uniformization theorem（单值化理论）。这是不是很像Grasshopper里面的某些操作，之前Dixon一直说要留意“曲面的结构”，我想他指的就是*conformal coordinate*吧。





## 3.2. Derivatives and Tangent Vectors



### 3.2.1. Derivatives on the Real Line

___

Suppose a good old fashioned real-valued function $\phi (x)$ on the real line. We typically visualize $\phi$ by plotting its value as a height over the $x$-axis.



Normally thinking: $\phi '$  is the slope of $\phi (x)$ , the dashed line in the graph. 

<img src="Chapter 03 A quick.assets/image-20210128153232333.png" alt="image-20210128153232333" style="zoom:50%;" />

Geometrically thinking: $\phi$ stretches out the real line itself.  Imagine a curve of $y=x$ is evenly divided in Rhino, move the control point up and down. Then we will have the above graph. The change in node spacing is like this:

<img src="Chapter 03 A quick.assets/image-20210128154111016.png" alt="image-20210128154111016" style="zoom:50%;" />

derivative$\uparrow$ nodes space apart$\uparrow$

derivative$\downarrow$ nodes close together$\downarrow$

这很好理解，越陡，变化越大，那两个点当然越远；反之亦然。

We can say the derivative of $\phi$ in terms of the push-forward $d\phi(X)$ of a unit tangent vector $X$ pointing along the positive $x$-axis:
$$
\phi' = d\phi(X)
$$
The real line also can be represented as a curve in $\mathbb{R}^2$:
$$
\gamma(x,\phi(x))
$$




### 3.2.2 Directional Derivatives

___

In last section, $\phi$ defines the $y$ value of $x$ in $\mathbb{R}$. So what about $\mathbb{R}^3$? Let's adopt the usual approach which is to draw a height function over the $\mathbb{R}^2$plane:

<img src="Chapter 03 A quick.assets/image-20210128160744240.png" alt="image-20210128160744240" style="zoom:50%;" />

Normally, we pick one vector$X$ to travel along the direction and document how quickly we travel uphill/downhill. This is called ***directional derivative***.

<img src="Chapter 03 A quick.assets/image-20210128161133692.png" alt="image-20210128161133692" style="zoom:50%;" />





## 3.3. The Geometry of Curves

<img src="Chapter 03 A quick.assets/image-20210128181948501.png" alt="image-20210128181948501" style="zoom:50%;" />

The function map one-dimensional curve from interval:

$$
I = [0,T]\subset\mathbb{R}
$$
to 
$$
\mathbb{R}^3
$$
can be denoted as:
$$
\gamma: I \rightarrow \mathbb{R}^3
$$



$d\gamma$ = how tangent vectors get stretched out by $\gamma$:
$$
\lvert d\gamma(X)\rvert = \sqrt{d\gamma(X)\cdot d\gamma(X)}
$$

If it is unit speed/arc-length/isometric parameterization, then the $\gamma$ preserves *length* for every tangent vector $X$:
$$
\lvert d\gamma(X)\rvert = \lvert X\rvert
$$







### 3.3.1. The Curvature of a Curve

___

<img src="Chapter 03 A quick.assets/image-20210128190647770.png" alt="image-20210128190647770" style="zoom:50%;" />

$\gamma$ : a unit-speed curve

$X$ : a positively-oriented vector

$I$ : interval

$T=d\gamma(X)$  : a unit vector in $\mathbb{R}^3$ tangent to the curve

Since $T$ may change at any rate in tangent direction as we move along $\gamma$. 

$N$ : unit vector, called as *principle normal* expresses the direction of change

$\kappa\in\mathbb{R}$ : called as curvature that expresses the magnitude of change

Hence, we have:
$$
dT(X)=-\kappa N
$$



##### Why $T$ and $N$ are always orthogonal?

___

:warning::question: Because if the change in $T$ were parallel to $T$ , then it would cease to have unit length! 

上面这个回答不够intuitive，用下面两个例子就懂了。以下公式不在DDG lecture notes里面，为网上搜集。

$\gamma$ : the curve

$t$ : the parameter of the curve, similar to the $t$ in Grasshopper

$T = \frac{d\gamma(t)}{t} = \gamma'$  : the first derivative of the curve $\gamma$ is the tangent vector, the **slope** of the curve. magenta arrow in the graph.

$N = \frac{dT(t)}{t}/\lvert\frac{dT(t)}{t} \rvert = \frac{T'}{\lvert T'\rvert} = \gamma''$ : the second derivative of the curve $\gamma$ is the acceleration, **how the slope change**! Conventionally, the $N$ is a quarter turn in the ***counter-clockwise*** direction from $T$. blue arrow in the graph. 为何要除以$T'$的norm，这是公式，因为它想要unit vector,所以才要除以它的norm。

$B = T \times N$ : this is *binormal*, the cyan arrow in the following graph

*Frenet frame* : the frame composed by $T$ and $N$.



$\therefore$ the $N$ of the following graph always points to the center of the circle because **it guides the tangent turn left... turn left... and turn left**.

<img src="Chapter 03 A quick.assets/why-tangent-normal-ortho.gif" alt="why-tangent-normal-ortho" style="zoom:50%;" />

Similarly:

<img src="Chapter 03 A quick.assets/why-tangent-normal-ortho1.gif" alt="why-tangent-normal-ortho1" style="zoom:50%;" />







##### Frenet-Serret formula in details

___

The formula is like this:
$$
\underbrace{\begin{bmatrix}T'\\N'\\B'\end{bmatrix}}_{Q'\in \mathbb{R}^{3\times3}}= \underbrace{\begin{bmatrix}0&-\kappa&0\\\kappa&0&-\tau\\0&\tau&0\end{bmatrix}}_{A\in \mathbb{R}^{3\times3}}\underbrace{\begin{bmatrix}T\\N\\B\end{bmatrix}}_{Q\in\mathbb{R}^{3\times3}}
$$

###### Why $QQ^T = I$ ?

We have:
$$
Q=\begin{bmatrix}T\\N\\B\end{bmatrix}, Q^{T}= \begin{bmatrix}T&N&B\end{bmatrix}
$$

Then:
$$
QQ^T = \begin{bmatrix}T\cdot T&T\cdot N&T\cdot B\\N\cdot T&N\cdot N&N\cdot B\\B\cdot T&B\cdot N&B\cdot B\end{bmatrix}
$$

$\because T,N,B$ are ***mutually orthogonal*** whose dot product is 0. $T\cdot T=1$, vice versa. So we have:
$$
QQ^T = \begin{bmatrix}1&0&0\\0&1&0\\0&0&1\end{bmatrix}
$$
:question:I only understand by far. Not fully understand Frenet-Serret formula.







### 3.3.2 Visualizing Curvature

___



##### What is *Curvature*?

___

The curvature of a circle is simply the reciprocal of its radius. 圆形的曲率是它半径的倒数。
$$
\kappa = \lvert\kappa N\rvert = \lvert dT(X)\rvert = 2\pi/2\pi r = 1/r
$$
There is an intuitive way perceiving this:
Curve flattening $\rightarrow$ curvature$(\kappa)\downarrow$ $\rightarrow$ circle grow bigger($r\uparrow$) $\rightarrow$ become straight line with **zero** curvature :
$$
\lim_{r\to \infty}\frac{1}{r}=0
$$
Curve bending $\rightarrow$ curvature$(\kappa)\uparrow$ $\rightarrow$ circle grow smaller($r\downarrow$) $\rightarrow$ become a dot with **infinite** curvature :
$$
\lim_{r\to0}\frac{1}{r}=\infty
$$
<img src="Chapter 03 A quick.assets/curvature-of-curve.gif" alt="curvature-of-curve" style="zoom:50%;" />

***osculating circle***: the circle in the middle with a radius of $r=\frac{1}{k}$









## 3.4. Curvature of Surfaces

The curvature of surface is quite interesting. Taking the beer as an example, the direction along vector $X_2$  is super flat while the direction along vector $X_1$ is curvy.

<img src="Chapter 03 A quick.assets/image-20210129102928582.png" alt="image-20210129102928582" style="zoom:50%;" />







Construct a plane containing two vectors $df(X)$ and $N$. This plane intersects the surface in a curve:

<img src="Chapter 03 A quick.assets/image-20210129120736799.png" alt="image-20210129120736799" style="zoom:50%;" />

$df(X)$ : a unit tangent direction at some distinguished point on the surface, e.g. the peak of this surface

$N$ : the normal vector of this surface in this point

$dN = \kappa T - \tau B$ : the change in the normal along a curve

$\kappa _n = \frac{df(X)\cdot dN(X)}{\lvert df(X)\rvert^2}$ : the normal curvature in the direction $df(X)$ . It is ***signed***, meaning the surface can be bend toward the normal or away from it. *signed* means the direction is fixed. 我理解这里为C++的signed，意思是它的正负值已经确定了，即方向已经定了。所以才会toward/away.

$\lvert df(X)\rvert^2$ : it normalizes any "stretching out" that occurs as we go from the domain $M$ into $\mathbb{R}^3$





### 3.4.1Principal, Mean, and Gaussian Curvature

___

<img src="Chapter 03 A quick.assets/image-20210129123637629.png" alt="image-20210129123637629" style="zoom:50%;" />

$X_1,X_2$ : unit vectors which represent the *principle directions*

$\kappa_1,\kappa_2$ : *principle curvatures*

We can find the **maximum** and **minimum** normal curvatures( $\kappa_1,\kappa_2$ , a.k.a *principle curvatures*) along the *principle direction* represented by unit vector $X_1,X_2$.

e.g. Following picture, $\kappa_1$ has the maximum curvature and this direction is also kind of curvy, while $\kappa_2$ has the minimum curvature and this direction is flat.

<img src="Chapter 03 A quick.assets/image-20210129130447795.png" alt="image-20210129130447795" style="zoom:50%;" />

*shape operator* $S：TM\to TM$ which satisfies the following:
$$
df(SX) = dN(X)
$$
$dN$ : the Weingarten map

The above equation tells that: ***how the normal changes*** as we travel along the direction $X$.



#### Difference between $df(SX)$ and $dN(X)$?

___

$S$ : specifies this change in terms of a tangent vector on $M$ ($\mathbb{R}^2$)

$dN$ : the changes as tangent vector in $\mathbb{R}^3$



:question:The principal directions and principal curvatures is that they correspond to **eigenvectors** and **eigenvalues** (respectively) of the shape operator:
$$
SX_i = \kappa_iX_i
$$




$\because X_1,X_2$ is *principal direction*, so we can express any tangent vector $\Upsilon$  as a linear combination of the principal directions $X_1,X_2$. If $\Upsilon$ is a unit vector offset from $X_1$ by an angle $\theta$, then the associated normal curvature is:
$$
\kappa_n(\Upsilon) = \kappa_1 \cos^2\theta + \kappa_2\sin^2\theta
$$
<img src="Chapter 03 A quick.assets/image-20210129155943808.png" alt="image-20210129155943808" style="zoom:50%;" />



TO-DO: finish the script in the Grasshopper(画到一半，还没做完)





#### mean curvature and Gaussian curvature

___

These 2 curvature is more appropriate in discrete setting than principal curvatures.



mean curvature:
$$
H = \frac{\kappa_1+\kappa_2}{2}
$$
Gaussian curvature:
$$
K = \kappa_1\kappa_2
$$


(*infml*) You can think of:

***Gaussian curvature*** = logical "**and**" ((is there curvature along *both* directions?)
***mean curvature*** = logical "**or**" (is there curvature along *at least one* direction)



(*special cases*) : $\kappa_1 = -\kappa_2$   , which is zero *mean curvature*.



#### *developable surface*

___

Definition: Surfaces with zero Gaussian curvature are called *developable surfaces* because they can be “***developed***” or flattened out into the plane without any stretching or tearing. e.g. 你可以把一张A4纸卷成一个圆柱体

<img src="Chapter 03 A quick.assets/image-20210129164124483.png" alt="image-20210129164124483" style="zoom:50%;" />





#### *minimal surfaces*

___

Definition: Surfaces with ***zero mean curvature*** are called *minimal surfaces* because they minimize surface area (with respect to certain constraints). 原来这就是“最小曲面”啊，百闻不如一见。

<img src="Chapter 03 A quick.assets/image-20210129165043926.png" alt="image-20210129165043926" style="zoom:50%;" />

Minimal surfaces tend to be *saddle-like*(又称为马鞍面) since principal curvatures have equal magnitude but opposite sign.(at the *saddle point*, therefore *mean curvature* = 0. Also, the *Gaussian curvature* of *minimal surfaces* is negative because the direction is opposite.





#### *hemisphere*

___

In this case: $\kappa_1=\kappa_2$ , and so principal directions are not uniquely defined—maximum (and minimum) curvature is achieved along any direction $X$. Any such point on a surface is called an *umbilic point*.（脐qí点，想象一下脐橙，上面是不是也有一个像下图的点）

<img src="Chapter 03 A quick.assets/image-20210129172221482.png" alt="image-20210129172221482" style="zoom:50%;" />





### 3.4.2. The Fundamental Forms

___

*first fundamental form I* :
$$
I(X,Y):=g(X,Y)
$$
$I(X,Y)$ 只是待变form I而已，左边的I是罗马数字1





*second fundamental form II* :
$$
II(X,Y):=-g(SX,Y) = -dN(X)\cdot df(Y)
$$
$II(X,Y)$ 只是待变form II而已，左边的II是罗马数字2



I and II do not introduce any new geometric ideas—just another way of writing down things we’ve already seen.





## 3.5. Geometry in Coordinates

<img src="Chapter 03 A quick.assets/image-20210129192707823.png" alt="image-20210129192707823" style="zoom:50%;" />

$M$ , you can see it as a set of infinite points(/a surface) in a 2D plane. $M\sub\mathbb{R}^2$

$f: M\to\mathbb{R}^3$ , a function which tell you the result of $M$ in $\mathbb{R}^3$

$df(X)$, this is the differential of $f$, so it tells how to stretch out tangent vector as we go from $M\sub\mathbb{R}^2$ to $f(M)\sub\mathbb{R}^3$

复述一遍，$M$可被看作一个二维曲面上的所有点或者描述改曲面的函数。$f$是一个把$M$从二维变成三维的函数。$df(X)$是描述$f$怎么把曲面$M$拉扯成三维的，即它的tangent vector怎么变化的。

Precise formula below:
$$
df_p(X)=\lim_{h\to0}\frac{f(p+hX)-f(p)}{h}
$$


#### *Jacobian matrix?*

___

It is a more typical representation of $df$.
$$
J = \begin{bmatrix}\partial f^1/\partial x^1&\partial f^1/\partial x^2\\\partial f^2/\partial x^1&\partial f^2/\partial x^2\\\partial f^3/\partial x^1&\partial f^3/\partial x^2\end{bmatrix}
$$
The transformation can be written as:
$$
f(\underbrace{x^1,x^2}_{x,y\in M}) = (\underbrace{f^1(x^1,x^2)}_{x\in\mathbb{R}^3},\underbrace{f^2(x^1,x^2)}_{y\in\mathbb{R}^3},\underbrace{f^3(x^1,x^2)}_{z\in\mathbb{R}^3})
$$
The horizontal curly bracket is my interpretation on this formula.





### 3.5.1. Coordinate Representations Considered Harmful

___

:warning:There are many blablabla matrices and how should we memorize it? 矩阵名称太多，用时忘了出处，则也忘了该如何使用。

Crane's advice: Remember that ***matrices*** are not objects: they are merely ***representations of objects***! 



***linear operator***, mapping from one vector space to another:
$$
f : \mathbb{R}^2 \to \mathbb{R}^2; u\mapsto f(u)
$$
***bilinear form***, mapping from a pair of vectors to a scalar:
$$
g : \mathbb{R}^2\times\mathbb{R}^2 \to \mathbb{R}; (u,v)\mapsto g(u,v)
$$

$\to$ denotes a mapping between two sets.

$\mapsto$ denotes what it does to each element of the set

Above formula can be converted to matrices $A,B\in \mathbb{R}^{2\times2}$ and their arguments are represented by vector $u,v\in \mathbb{R}^2$
$$
\begin{align}
f(u) &= Au\\
g(u,v) &= u^{T}Bv
\end{align}
$$


Taking the following chart as an example:

<img src="Chapter 03 A quick.assets/image-20210129211533361.png" alt="image-20210129211533361" style="zoom:50%;" />

vector $u$ which is composed by $u^1,u^2$ is in the coordinate system$(x^1,x^2)$

$P\in\mathbb{R}^{2\times2}$ : change the base of the coordinate system

$\tilde{u}$ : vector $u$ in the coordinate system $(\tilde{x}^1,\tilde{x}^2)$

Therefore we have:
$$
\begin{align}
&\tilde{u} = Pu\\
&\tilde{v} = Pv\\
&f(u) = PAu = PAP^{-1}\tilde{u}\\
&g(u,v) =u^TBv = (P^{-1}\tilde{u})^TB(P^{-1}\tilde{v}) =\tilde{u}^T(P^{-T}BP^{-1})\tilde{v}\\

&A\mapsto PAP^{-1}\\
&B\mapsto P^{-T}BP^{-1}
\end{align}
$$







### 3.5.2. Standard Matrices in the Geometry of Surfaces

___

:warning::question: This section I don't understand at all.



$g$, *induced metric* 

$J$, Jacobian matrix containing first-order derivatives of the immersion $f$

$I\in \mathbb{R}^{2\times2}$ , induced matrix $I$,
$$
u^TIv = (Ju)^T(Jv)\\
I = J^TJ\\
I = \begin{bmatrix}E&F\\F&G\end{bmatrix}\\
dN(X) = df(SX)\\
II(u,v) = g(Su,v)\\
u^TIIv =u^TISv\\
II = IS\\
II = \begin{bmatrix}e&f\\f&g\end{bmatrix}\\
e = N\cdot f_{xx}\\
f = N\cdot f_{yy}\\
g = N\cdot f_{z}\\
\kappa_n(u) = \frac{II(u,u)}{I(u,u)}\\
\frac{u^TIIu}{u^TIu} = \frac{u^TISu}{u^TIu} = \frac{(Ju)^T(JSu)}{(Ju)^T(Ju)} = \frac{df(u)\cdot dN(u)}{\lvert df(u) \rvert^2} = 
$$


