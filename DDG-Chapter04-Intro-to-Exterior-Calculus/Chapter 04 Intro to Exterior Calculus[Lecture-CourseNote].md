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



### 4.1.3. Rules of Wedge Product

___

For any collection of vectors $u, v, w \in \mathbb{R}^n$ and scalars $a, b \in\mathbb{R}$ we have

- (Antisymmetry) $u ∧ v = −v ∧ u $
- (Associativity) $(u ∧ v) ∧ w = u ∧ (v ∧ w) $
- (Distributivity over addition) $u ∧ (v +w) = u ∧ v + u ∧ w $
- (Distributivity of scalar multiplication) $(au) ∧ (bv) = ab(u ∧ v)$

Except the first one which illustrates the orientation, others can all be interpret as multiplication乘法.



## 4.2. Examples of Wedge and Star in $\mathbb{R}^n$ 











## 4.3. Vectors and 1-Forms











## 4.4. Differential Forms and the Wedge Product 











## 4.5. Hodge Duality













## 4.6. Differential Operators











## 4.7. Integration and Stokes’ Theorem 











## 4.8. Discrete Exterior Calculus