# Chapter 04 Intro to Exterior Calculus

Reason to study Exterior Calculus:

- Language: used to interact with *signed volume*
- Geometry: algebraic geometry, geometric algebra
- Physics: velocity, acceleration, momentum, force
- Computer Science: geometric computation on meshes



To 100% understand ***Discrete Exterior Calculus***, the pipeline is organized as followed:

- Linear Algebra: "little arrows" (vectors)
- Vector Calculus: how do vectors change?
- Exterior Algebra: "little volumes" ($k$-vectors)
- Exterior Calculus: how do $k$-vectors change?
- ***Discrete Exterior Calculus***: How do we do all of this on meshes?



In a nutshell, similar to Discrete Differential Geometry is to replace Differential Geometry, ***Discrete Exterior Calculus*** also is to replace vector calculus with computation on meshes.



Built on ***DEC***, the computational tools are:

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210215172713901.png" alt="image-20210215172713901" style="zoom:40%;" />

Built on ***DEC***, the applications are:

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210215172750872.png" alt="image-20210215172750872" style="zoom:40%;" />



## Vector Spaces - (review)

(fml.) A vector space is a set $V$ together with the operations

Addition:  $+: V\times V\to V$

Scalar multiplication:  $\cdot: \mathbb{R}\times V\to V$



Must satisfy the following properties for all vectors $x,y,z$ and scalars $a,b$:

$x+y=y+x$

$(x+y)+z=x+(y+z)$

$\exist 0\in V$ s.t. $x+0=0+x=x$  , $\exist$ means "exist",  "s.t." means "such that"

$\forall x,\exist \tilde{x}\in V$ s.t. $x+\tilde{x}=0$ , it means there is always a vector with reversed(negative) direction.

$(ab)x = a(bx)$

$1x=x$

$a(x+y)=ax+ay$

$(a+b)x=ax+bx$



## Inner Product - (review)

$\langle\cdot,\cdot\rangle:V\times V\to\mathbb{R}$ , this quantity tells how well two vector "line up" in $V$

***symmetry*** : $\langle x,y\rangle=\langle y,x\rangle$

***linearity*** : $\langle ax,y\rangle=a\langle x,y\rangle$   $\langle x,y+z\rangle=\langle x,y\rangle+\langle x,z\rangle$

***positivity*** : $\langle x,x\rangle > 0, x\neq0$        $\langle x,x\rangle = 0,x=0$

***Euclidean inner product*** : $\langle x,y\rangle = \sum_{k=1}^{n}x_iy_i $ 







## 4.1. Exterior Algebra

Definition: **exterior algebra** is the natural language of “little volumes” which we will call **$k$-vectors**.   REMEMBER!!:bangbang:  $k$-vectors also encode **orientation** and **magnitude**. For simplicity, this notes stick to the plane $\mathbb{R}^2$, three-dimensional space $\mathbb{R}^3$, or more generally, $n$-dimensional space $\mathbb{R}^n$.



### 4.1.1. $k$-Vectors in Exterior Algebra

___



#### direction vs orientation in English

$l$ : A line encodes a **direction**.(infinity)

$v$ : A vector encodes a **direction** AND a definite **orientation**. (finite)

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216145452443.png" alt="image-20210216145452443" style="zoom:50%;" />

#### 0-vector

​	It is a **scalar/scalar value**.  (*magnitude*, no direction) 

#### 1-vector

​	1-vector is just an ordinary vector.

#### 2-vector

​	A pretty good visualization of a 2-vector is to associate any two vectors $u, v$ in three-dimensional space $\mathbb{R}^3$ with the volume spanned by a little parallelogram.

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216162804238.png" alt="image-20210216162804238" style="zoom:67%;" />

#### $k$-vector

:bangbang: The **wedge** of $k$ vectors is called a “$k$-vector” a.k.a a **volume**!!

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216162843007.png" alt="image-20210216162843007" style="zoom:50%;" />



### 4.1.2. Wedge Product

___

$\land$ : pronounced "**wedge**"

In $\mathbb{R}^2$, $u\land v$ is the volume spanned by the 2 vectors, called **parallelogram**.

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216152248135.png" alt="image-20210216152248135" style="zoom:70%;" />

In $\mathbb{R}^3$, $u\land v\land w$ is the volume spanned by the 3 vectors, called **parallelepiped**.

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216155231386.png" alt="image-20210216155231386" style="zoom:67%;" />

#### Wedge product - orientation

In $\mathbb{R}$, there are 2 opposite orientations$(-x,x)$ which can be described as "**forward**" and "**backward**"

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216155725343.png" alt="image-20210216155725343" style="zoom:80%;" />

In $\mathbb{R}^2$, there are 2 opposite orientations corresponding to "**up**" and "**down**".

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216152432974.png" alt="image-20210216152432974" style="zoom:50%;" />

$+N : u\land v$  , $-N : v\land u$

$u\land v = -v\land u$

In $\mathbb{R}^3$, there are 2 opposite orientations corresponding to "**inward**" and "**outward**".

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216161539829.png" alt="image-20210216161539829" style="zoom:60%;" />



####  :bangbang: RULES OF ORIENTATION SWITCHES

Any **even permutation** of vectors **preserves** orientation!!!

Any **odd permutation** of vectors **reverses** orientation!!!

In CHN, we said"负负得正"

For example:

$u\land v\land w = v\land w \land u = w\land u \land v$ , 可以看成把$v,w$两个都挪到$u$前面

$w\land v\land u = v\land u\land w = u\land w\land v$






#### Wedge product - degeneracy

$u\land u=0$ , geometrically, spans a region of *zero area*.



#### Wedge product - scaling

Scaling just one of the vectors by a factor $a\in\mathbb{R}$ will scale the area of our parallelogram by the same amount:

$(au)\land v=a(u\land v) = u\land (av)=a(u\land v)$

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216154559248.png" alt="image-20210216154559248" style="zoom:70%;" />



#### Wedge product - associativity

$u\land v\land w=(u\land v)\land w=u\land (v\land w)$

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216154228168.png" alt="image-20210216154228168" style="zoom:40%;" />



#### Wedge product - distributivity

$u\land v_1 + u\land v_2 = u\land(v_1+v_2)$

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210216154936638.png" alt="image-20210216154936638" style="zoom:40%;" />



#### Rules of Wedge Product

For any collection of vectors $u, v, w \in \mathbb{R}^n$ and scalars $a, b \in\mathbb{R}$ we have

- (Antisymmetry) $u ∧ v = −v ∧ u $
- (Associativity) $(u ∧ v) ∧ w = u ∧ (v ∧ w) $
- (Distributivity over addition) $u ∧ (v +w) = u ∧ v + u ∧ w $
- (Distributivity of scalar multiplication) $(au) ∧ (bv) = ab(u ∧ v)$

Except the first one which illustrates the orientation, others can all be interpret as multiplication乘法.



### 4.1.3. The Hodge Star

___

Why use "Hodge Star"? The ideology of "**complement**".

- Question - “*what foods do you like?*”
- Answer - (*positive* **all**) "*I like pizza, and apples, and hamburgers, and sushi, and fesenjan, and chicken & waffles, and . . .*"
- Answer - (*negative* **complement**) "*I like everything except for natto and doogh*"



#### Orthogonal Complement - "complement" in Linear Algebra

Definition: Let $U\subseteq V$ be a linear subspace of a vector space $V$ with an inner product $\langle\cdot,\cdot\rangle$. The *orthogonal complement* of $U$ is the collection of vectors denoted as $U^\bot$.

$$
U^{\bot}:=\{v\in V | \langle u,v\rangle=0, \forall u\in U\}
$$
<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210217090707345.png" alt="image-20210217090707345" style="zoom:50%;" />



#### Hodge Star - "complement" in Exterior Algebra

In exterior algebra, the ***Hodge star***$\star$(pronounced “star”) provides a sort of *orthogonal complement* for $k$-vectors. If we have a $k$-vector $v$ in $\mathbb{R}^n$, then $\star v$ will be an $(n−k)$-vector that is in some sense “complementary.” 



The analogy can be summarized:

|                          | Linear Algebra                                               | Exterior Algebra                                             |
| ------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| image                    | <img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210217091633014.png" alt="image-20210217091633014" style="zoom:50%;" /> | <img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210217091714194.png" alt="image-20210217091714194" style="zoom:50%;" /> |
| ideology of "complement" | Orthogonal Complement                                        | Hodge Star                                                   |
| orientation & magnitude  | :x:                                                          | :heavy_check_mark:                                           |



#### Hodge Star - orientation & magnitude

Then the question shifts to how to determine these two?

orientation: 

- right hand rule, we asked: det$(u,v,\star(u\land v))>0$ , 
- i.e. the determinant of the two vectors comprising u ∧ v and the third vector given by its Hodge star should be positive
- :bangbang::warning:when heard the word "**determinant**", you should instead think "**volume**" !!

magnitude: 

- suppose there are 2 orthonormal vectors $u_1,u_2$ , 
- we asked: det$(u_1.u_2,\star(u_1\land u_2))=1$

General rules:

- orthonormal basis for $\mathbb{R}^n$ : $e_1,...,e_n$ 
- $k$ orthonormal vectors : $u_1,...,u_k$ 
- Relationship is that: $(u_1\land \cdot\cdot\cdot\land u_k)\land\star(u_1\land \cdot\cdot\cdot\land u_k)=e_1\land \cdot\cdot\cdot\land e_n$
- Conclusion of this relationship: their wedge and their hodge star must be the base of the whole space.





#### Hodge Star - 2D

Since  we are talking in $\mathbb{R}^2$, then we have 1-vector $u$. Hodge star $\star u$ will be $(n-k)=2-1=1$-vector. Therefore, it merely is 90 degree rotation.

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210217092117200.png" alt="image-20210217092117200" style="zoom:30%;" />







### 4.1.4. Examples of Wedge and Star in $\mathbb{R}^n$ 

___

Example 1. Let $u:=e_1+2e_2$ and $v:=e_1+e_2-e_3$ be 1-vectors in $\mathbb{R}^3$. Then their wedge product is given by
$$
\begin{align}
u\land v &= (e_1+2e_2)\land(e_1+e_2-e_3)\\
&= e_1\land(e_1+e_2-e_3) + 2e_2\land(e_1+e_2-e_3)\\
&= \cancelto{0}{e_1\land e_1} + e_1\land e_2-e_1\land e_3+2e_2\land e_1+\cancelto{0}{2e_2\land e_2}-2e_2\land e_3\\
&=e_1\land e_2-2e_1\land e_2-e_1\land e_3-2e_2\land e_3\\
&=-e_1\land e_2-e_1\land e_3-2e_2\land e_3
\end{align}
$$
*key notes: $e_1\land e_1=0, \space 2e_2\land e_1=-2e_1\land e_2$



Example 2. Let $w:=-e_1\land e_2-e_1\land e_3-2e_2\land e_3$ be the 2-vector from the previous example. Its Hodge star is given by:
$$
\begin{align}
\star w &= \star(-e_1\land e_2-e_1\land e_3-2e_2\land e_3)\\
&=-\star(e_1\land e_2)-\star(e_1\land e_3)-2\star(e_2\land e_3)\\
&=-e_3-(-e_2)-2e_1\\
&=-2e_1+e_2-e_3
\end{align}
$$
*key notes: right hand rule, $\star(e_1\land e_3)=-e_2$

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210217105816252.png" alt="image-20210217105816252" style="zoom:50%;" />

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210217110304240.png" alt="image-20210217110304240" style="zoom:50%;" />



Example 3. Let $u:=e_1+e_2+e_3, v:=e_1+2e_2+3e_3, w:=e_1-e_3$ be 1-vectors in $\mathbb{R}^3$, compute $u\land v\land w$ . Due to the associativity, the process can be divided into $u\land(v\land w)$:

$$
\begin{align}
v\land w &= (e_1+2e_2+3e_3)\land(e_1-e_3)\\
&=\cancelto{0}{e_1\land e_1}-e_1\land e_3+2e_2\land e_1-2e_2\land e_3+3e_3\land e_1 -3\cancelto{0}{e_3\land e_3}\\
&=-2e_1\land e_2-4e_1\land e_3 -2e_2\land e_3\\
\\
u\land(v\land w)&=(e_1+e_2+e_3)\land (-2e_1\land e_2-4e_1\land e_3 -2e_2\land e_3)\\
&=0
\end{align}
$$

*key notes: any term involving multiple copies of the same basis 1-vector (e.g., $e_1\land e_1\land e_2$) would have zero volume



### 4.1.5. Coordinate Representation

___

#### Basis

Definition: Let $V$ be a vector space. A collection of vectors is *linearly independent* if no vector in the collection can be expressed as a linear combination of the others. A linearly independent collection of vectors $\{e_1,...,e_n\}$ is a ***basis*** for $V$ if every vector $v\in V$ can be expressed as:
$$
v=v_1e_1+\cdot\cdot\cdot+v_ne_n
$$
for some collection of coefficients $v_1,...,v_n\in\mathbb{R}$ , i.e., if every vector can be uniquely expressed as a linear combination of the *basis vector* $e_i$. In this case, we say that $V$ is **finite dimensional**, with dimension *n*.

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210218175753880.png" alt="image-20210218175753880" style="zoom:33%;" />



#### Basic $k$-Vectors - visualized

Reminds once again: $k$-Vectors is a **volume**!! Therefore, **basis $k$-vector** is also a **volume**!!

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210218175859849.png" alt="image-20210218175859849" style="zoom:50%;" />



#### Basic $k$-Vectors - amounts

Consider $V=\mathbb{R}^4$ with basis $\{e_1,e_2,e_3,e_4\}$

**How many basis 2-vectors?

​	$e_1\land e_2, e_1\land e_3,e_2\land e_3, e_1\land e_4, e_2\land e_4, e_3\land e_4$

**How many basis 3-vectors?

​	$e_1\land e_2\land e_3, e_1\land e_2\land e_4, e_1\land e_3\land e_4,e_2\land e_3\land e_4$

**How many basis 4-vectors?

​	$e_1\land e_2\land e_3\land e_4$

The **pattern** is this:

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210218180721431.png" alt="image-20210218180721431" style="zoom:40%;" />



#### Basic $k$-Vectors - Hodge Star

Consider $V=\mathbb{R}^3$ with orthogonal basis $\{e_1,e_2,e_3\}$

Given $\alpha:=e_2$, find $\star\alpha$ such that det$(e_2\land\star e_2)=1$

Must have $\star\alpha=e_3\land e_1$, 

therefore $e_2\land\star e_2=e_2\land e_3\land e_1$,  which is the even permutation of $e_1,e_2,e_3$ , :bangbang: determinant是1

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210218215919621.png" alt="image-20210218215919621" style="zoom:60%;" />







## 4.2. $k$-Vectors and $k$-Forms

:bangbang:  In a nutshell, $k$-Forms are to **measure** $k$-Vectors.

wedging together vectors yields  =>  $k$-vectors

wedging together covectors yields  =>  $k$-forms



### 4.2.1. Vector-Covector Duality

___

***Duality*** is a pervasive idea in mathematics - two sets of objects that are in ***one-to-one correspondence***, but play complementary roles. Very much similar to Ancient Chinese philosophy - Yin-Yang阴阳。

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210218221855693.png" alt="image-20210218221855693" style="zoom:50%;" />



#### Duality in differential geometry and exterior calculus

<span style="color:blue">vectors</span> $u$ - vector of any magnitude, objects that get **measured** , 

<span style="color:red">covectors</span> $\alpha$ - covector with unit magnitude, objects that **measure**

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210218222929918.png" alt="image-20210218222929918" style="zoom:67%;" />

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210218223459465.png" alt="image-20210218223459465" style="zoom:43%;" />

The notation $\alpha(u)$ here is meant to emphasize the idea that $\alpha$ is a **function**: in particular, it’s **a linear function** that *eats a vector and produces a scalar*. Any such function is called a **1-form** (also known as a **covector**).



#### Dual Space & Covectors

Definition: Let $V$ be any real vector space. Its **dual space** $V^*$ is the collection of all **linear functions** $\alpha:V\to\mathbb{R}$ together with the operations of ***addition*** and ***scalar multiplication***:
$$
(\alpha+\beta)(u):=\alpha(u)+\beta(u)\\
(c\alpha)(u):=c(\alpha(u))
$$
for all $\alpha,\beta\in V^*, u\in V,$ and $c\in\mathbb{R}$



Definition: An element of a dual vector space is called a ***dual vector*** or ***covector***.



#### Covectors - Example in $\mathbb{R}^3$

linear map $f$ , vectors $u,v$ , scalars $a$ . Then we have:

$f(u+v)=f(u)+f(v)$	and	$f(au)=af(u)$

**Q**: What’s an example of a linear map from $\mathbb{R}^3$ to $\mathbb{R}$?

​	A: One good example is to express vectors in coordinates $u = (x,y,z)$. One of many example could be $f (x,y,z) = x + 2y + 3z$

**Q**: What are all the possibilities?

​	A: It can be summarized as: $f(x,y,z) = ax + by + cz$  for constants $a,b,c$

**Conclusion**: In Euclidean $\mathbb{R}^3$, a covector looks like just another 3-vector!

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210218231219069.png" alt="image-20210218231219069" style="zoom:50%;" />



#### Covectors - Example in Functions

Let $V$ be the set of integrable functions $f:[0,1]\to\mathbb{R}$ a.k.a. the blue,red, and green curve.

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210218233155643.png" alt="image-20210218233155643" style="zoom:50%;" />

We say **covector** eats a vector and **produce** a **scalar**. So what is the covector of above 3 curves??:thinking:

The integral!!
$$
\phi:V\to\mathbb{R}; f\mapsto \smallint_0^1f(x)dx\\
\delta:V\to\mathbb{R}; f\mapsto f(0)
$$
How to interpret above equation?

一个函数叫$\phi$，它将$V$变成$\mathbb{R}$, 本质是将函数$f$ 影射到函数$f$ 的0-1区间的积分

一个函数叫$\delta$， 它将$V$变成$\mathbb{R}$, 本质是将函数$f$ 影射到函数$f(0)$



#### Sharp and Flat

***sharp*** ($\sharp$) : convert a 1-form into a vector

***flat*** ($\flat$) : convert a vector into a 1-form

How to memorize?

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210219102956120.png" alt="image-20210219102956120" style="zoom:50%;" />

Keep it in mind: ***sharp*** ($\sharp$) and ***flat*** ($\flat$) are both *musical isomorphisms*. 

***sharp*** ($\sharp$) : tune going up $\uparrow$

***flat*** ($\flat$) : tune going down $\downarrow$

$k$-form is underneath, so "sharp" will bring it up to $k$-vector $\uparrow$

$k$-vector is above, so "flat" will bring it down to $k$-form $\downarrow$



Therefore, for 1-vector $v$ and 1-form $\alpha$, we can write like this:

$v^\flat(v)$ , which is equivalent to $\alpha(v)$

$\alpha(\alpha^\sharp)$ , which is equivalent to $\alpha(v)$



#### Sharp and Flat w/ Inner Product

<span style="color:red">$\begin{bmatrix}u_1&u_2&u_3\end{bmatrix}\begin{bmatrix}M_{11}&M_{12}&M_{13}\\M_{12}&M_{22}&M_{23}\\M_{13}&M_{23}&M_{33}\end{bmatrix}$</span><span style="color:blue">$\begin{bmatrix}v_1\\v_2\\v_3\end{bmatrix}$</span>

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210219110614609.png" alt="image-20210219110614609" style="zoom:50%;" />



#### Sharp and Flat - Example

In *curved* space, suppose we want to measure the length of a vector $v$ along the direction of another vector $u$.

$f:\mathbb{R}^2\supset M\to\mathbb{R}^3$  , the map $f$ stretch out the tangent vector, take us from the plane to some surface in $\mathbb{R}^3$, then we have:
$$
u^\flat(v)=g(u,v)
$$
$g$  , is the metric. In a nutshell, a *distance function*. 因为$u^\flat()$是变成1-form，喂$v$进去，得出**scalar**，而这个scalar就是distance function $g$得出的。





### 4.2.2. $k$-Forms

___

Just a sum-up and warm-up:

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210219112734239.png" alt="image-20210219112734239" style="zoom:50%;" />

$k$-form will measure $k$-vectors



#### Computing the Projected Length

Since we think of $u$ as the vector “**getting measured**” and $\alpha$ as the vector “**doing the measurement**”, we’ll write this as a function $\alpha(u)$:
$$
\alpha(u)=\sum^n_{i=1}\alpha_iu^i
$$
<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210219113319825.png" alt="image-20210219113319825" style="zoom:40%;" />



#### 1-form

We can of course apply this same expression when $\alpha$ does not have unit length:
$$
\alpha(u) := \sum_ia_iu^i
$$
How to interpret? 

- Projected length gets scaled by magnitude of $\alpha$.

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210219113912828.png" alt="image-20210219113912828" style="zoom:33%;" />



#### (review) Determinants & Signed Volume

:star:Don't memorize the equation and matrix of determinants. Just remember **determinant = signed volume**

Determinant of 2-vectors = 2D signed area 

Determinant of 3-vectors = 3D signed volume

<img src="Chapter 04 Intro to Exterior Calculus[Lecture-CourseNote].assets/image-20210219125309001.png" alt="image-20210219125309001" style="zoom:50%;" />





## 4.4. Differential Forms and the Wedge Product 











## 4.5. Hodge Duality













## 4.6. Differential Operators











## 4.7. Integration and Stokes’ Theorem 











## 4.8. Discrete Exterior Calculus