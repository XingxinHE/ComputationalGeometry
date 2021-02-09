# Chapter 02 Combinatorial Surfaces



### Convex Set

___

Definition: A subset $S\sub\mathbb{R}^n$ is convex if for  every pair of points $p,q\in S$ the line segment between $p$ and $q$ is contained in $S$.

<img src="Chapter 02 Combinatorial Surfaces[Lecture&amp;CourseNote].assets/image-20210209181005100.png" alt="image-20210209181005100" style="zoom:50%;" />

Now you can tell which are convex set:

<img src="Chapter 02 Combinatorial Surfaces[Lecture&amp;CourseNote].assets/image-20210209223738504.png" alt="image-20210209223738504" style="zoom:60%;" />

### Convex Hull

___

Definition: For any subset $S\sub\mathbb{R}^n$, its convex hull $conv(S)$ is the smallest convex set containing $S$, or equivalently, the intersection of all convex set containing $S$.

<img src="Chapter 02 Combinatorial Surfaces[Lecture&amp;CourseNote].assets/image-20210209224202999.png" alt="image-20210209224202999" style="zoom:50%;" />

### Convex Hull - Example

___

**Q:** What is the convex hull of the set $S := \{(\pm1,\pm1,\pm1)\}\sub\mathbb{R}^3$ ?

**A:** A Cube.

<img src="Chapter 02 Combinatorial Surfaces[Lecture&amp;CourseNote].assets/image-20210209224603908.png" alt="image-20210209224603908" style="zoom:50%;" />







## 2.1. Abstract Simplicial Complex



### Linear Independence(for vector)

___

This is a topic in Linear Algebra.

<img src="Chapter 02 Combinatorial Surfaces[Lecture&amp;CourseNote].assets/image-20210209225113143.png" alt="image-20210209225113143" style="zoom:50%;" />



### Affine Independence(for points)

___

Introduce concept of linear independence to geometry: A collection of points $p_0,...,p_k$ are affine independent if the vectors $v_i:=p_i-p_0$ are linearly independent.

<img src="Chapter 02 Combinatorial Surfaces[Lecture&amp;CourseNote].assets/image-20210209225525559.png" alt="image-20210209225525559" style="zoom:50%;" />



### Simplex

___

(intuitive) From left to right, a *k-simplex* is a point, line segment, triangle, a tetrahedron...  *Most of the time, we study  <= $k=3$ .

<img src="Chapter 02 Combinatorial Surfaces[Lecture&amp;CourseNote].assets/image-20210209224722707.png" alt="image-20210209224722707" style="zoom:67%;" />

(geometric definition) A ***k-simplex*** is the convex hull of *k+1* affinely-independent points, which also named ***vertices***.

<img src="Chapter 02 Combinatorial Surfaces[Lecture&amp;CourseNote].assets/image-20210209225918571.png" alt="image-20210209225918571" style="zoom:50%;" />

| k-simplex | How many vertices? |
| --------- | ------------------ |
| 0-simplex | 1 = 0 + 1          |
| 1-simplex | 2 = 1 + 1          |
| 2-simplex | 3 = 2 + 1          |
| 3-simplex | 4 = 3 + 1          |



#### Barycentric Coordinates —— 1-simplex

*1-simplex* is comprised of all **weighted** combinations of the two points where the weights sum to **1**：
$$
p(t) = (1-t)a + tb, t\in[0,1]
$$
<img src="Chapter 02 Combinatorial Surfaces[Lecture&amp;CourseNote].assets/image-20210209234010454.png" alt="image-20210209234010454" style="zoom:33%;" />

Why $a\times(1-t)$ rather than $t$ ? Easy to comprehend, e.g. $t=\frac{3}{4}, p$ inclines to the right, hence the **weight** of $a$ (left) should be small. Vice versa.



   

## 2.2. Anatomy of a Simplicial Complex: Star, Closure, and Link 





## 2.3. Simplicial Surfaces 





## 2.4. Adjacency Matrices 





## 2.5. Halfedge Mesh