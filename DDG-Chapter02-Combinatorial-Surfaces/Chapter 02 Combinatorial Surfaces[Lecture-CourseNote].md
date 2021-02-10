# 2Chapter 02 Combinatorial Surfaces



### Convex Set

___

Definition: A subset $S\sub\mathbb{R}^n$ is convex if for  every pair of points $p,q\in S$ the line segment between $p$ and $q$ is contained in $S$.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210209181005100.png" alt="image-20210209181005100" style="zoom:50%;" />

Now you can tell which are convex set:

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210209223738504.png" alt="image-20210209223738504" style="zoom:50%;" />

### Convex Hull

___

Definition: For any subset $S\sub\mathbb{R}^n$, its convex hull $conv(S)$ is the smallest convex set containing $S$, or equivalently, the intersection of all convex set containing $S$.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210209224202999.png" alt="image-20210209224202999" style="zoom:50%;" />

### Convex Hull - Example

___

**Q:** What is the convex hull of the set $S := \{(\pm1,\pm1,\pm1)\}\sub\mathbb{R}^3$ ?

**A:** A Cube.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210209224603908.png" alt="image-20210209224603908" style="zoom:50%;" />







## 2.1. Abstract Simplicial Complex



### Linear Independence(for vector)

___

This is a topic in Linear Algebra.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210209225113143.png" alt="image-20210209225113143" style="zoom:50%;" />



### Affine Independence(for points)

___

Introduce concept of linear independence to geometry: A collection of points $p_0,...,p_k$ are affine independent if the vectors $v_i:=p_i-p_0$ are linearly independent.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210209225525559.png" alt="image-20210209225525559" style="zoom:50%;" />



### Simplex

___

(intuitive) From left to right, a *k-simplex* is a point, line segment, triangle, a tetrahedron...  *Most of the time, we study  <= $k=3$ .

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210209224722707.png" alt="image-20210209224722707" style="zoom:67%;" />

(geometric definition) A ***k-simplex*** is the convex hull of *k+1* affinely-independent points, which also named ***vertices***.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210209225918571.png" alt="image-20210209225918571" style="zoom:50%;" />

| k-simplex | How many vertices? | Image                                                        |
| --------- | :----------------: | ------------------------------------------------------------ |
| 0-simplex |     1 = 0 + 1      | <img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210113121055.png" alt="image-20210210113121055" style="zoom:40%;" /> |
| 1-simplex |     2 = 1 + 1      | <img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210113205491.png" alt="image-20210210113205491" style="zoom:40%;" /> |
| 2-simplex |     3 = 2 + 1      | <img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210113240662.png" alt="image-20210210113240662" style="zoom:40%;" /> |
| 3-simplex |     4 = 3 + 1      | <img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210113257536.png" alt="image-20210210113257536" style="zoom:40%;" /> |



#### Barycentric Coordinates

___

A **barycentric coordinate system** is a coordinate system in which **the location of a point** is **specified** by **reference** to a **simplex** (a triangle for points in a plane, a tetrahedron四面体 for points in three-dimensional space, etc.). The barycentric coordinates of a point can be interpreted as **masses** placed at the vertices of the simplex, such that the point is the center of mass (or **barycenter**) of these masses. 



#### Barycentric Coordinates Example:  *1-simplex*

___

*1-simplex* is comprised of all **weighted** combinations of the two points where the weights sum to **1**：
$$
p(t) = (1-t)a + tb, t\in[0,1]
$$
<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210209234010454.png" alt="image-20210209234010454" style="zoom:33%;" />

Why $a\times(1-t)$ rather than $t$ ? Easy to comprehend, e.g. $t=\frac{3}{4}, p$ inclines to the right, hence the **weight** of $a$ (left) should be small, vice versa.



#### Barycentric Coordinates Example:  *k-simplex*

___

Any point $p$ in a $k$-simplex $\sigma$ can be expressed as a (**non-negative**) weighted combination of the vertices, where the weights sum to **1**. The weights $t_i$ are called *barycentric coordinates*.
$$
\sigma = \Bigg\{\sum_{i=0}^kt_ip_i\Bigg|\sum_{i=0}^kt_i=1,t_i\geq0\forall i\Bigg\}
$$
<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210111906293.png" alt="image-20210210111906293" style="zoom:70%;" />

This is also known as **Convex Combination** which defined as a linear combination of points (which can be vectors, scalars, or more generally **points in an affine space**) where all coefficients are **non-negative** and sum to **1**.



#### Probability Simplex

___

The *standard n-simplex* is the collection of points which is also known as ***probability simplex***.
$$
\sigma := \Bigg\{(x_o,...,x_n)\in\mathbb{R}^{n+1}\Bigg|\sum^{n}_{i=1}x_i=1, x_i\geq0 \forall\Bigg\}
$$
<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210113856084.png" alt="image-20210210113856084" style="zoom:50%;" />

The above diagram is a *2-simplex* which lies in $\mathbb{R}^3$. Imagine all the possibilities of this simplex... No matter how, they all lie in the triangle $\sigma$ above. Therefore, it is called **probability simplex**.



### Simplicial Complex

___

(*infml*) **Simplicial Complex** = a bunch of **simplices**.

| Singular单数 | Plural复数 |
| ------------ | ---------- |
| Vertex       | Vertices   |
| Simplex      | Simplicies |

**Q:** What are all the simplices?
<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210150909217.png" alt="image-20210210150909217" style="zoom:50%;" />
**A:** {6,7,9} {7,10,8} {2,3} {3,4} {4,5} {0} {1}
{6,7} {7,9} {9,6} {7,8} {8,10} {10,7} {2} {3} {4} {5}
{6} {7} {8} {9} {10} - simply write down all the **vertices**, **edges** and **faces**.



#### (Abstract) Simplicial Complex  ||  (Geometric) Simplicial Complex

___

Definition: A (***geometric***) simplicial complex is a *collection* of simplices where (a) the *intersection* of any two simplices is a simplex, and every face of (b) every simplex in the complex is also in the complex.

Definition: Let $S$ be a collection of sets. If for each set $\sigma\in S$ all subsets of $\sigma$ are contained in $S$, then $S$ is an *abstract simplicial complex*. A set $\sigma\in S$ of size $k+1$ is an (***abstract***) simplicial complex.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210144954732.png" alt="image-20210210144954732" style="zoom:50%;" />

(infml.) You can see these two as <u>torch_geometric.data.Data</u> while the left is *with coordinates and the right is *without coordinates*. You can also see the left as "**fabrication**" which requires everything lines up while the right as "**connectivity**" only.



#### Abstract Simplicial Complex—Graphs

___

Any *(undirected) graph* $G = (V,E)$ is an abstract simplicial (1-)complex

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210165920758.png" alt="image-20210210165920758" style="zoom:30%;" />

0-simplices are vertices

1-simplices are edges



#### Abstract Simplicial Complex—Example

___

Example: Consider the set

$S:=$ {{1,2,:black_heart:}, {2,:black_heart:,:slightly_smiling_face:},{1,2},{2,:black_heart:},{:black_heart:,1},{2,:slightly_smiling_face:},{:black_heart:,:slightly_smiling_face:},{1},{2},{:black_heart:},{:slightly_smiling_face:}}

**Q**: Is this set an abstract simplicial complex? If so, what does it look like?
**A**: Yes—it’s a pair of 2-simplices (triangles) sharing a single edge:

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210170715166.png" alt="image-20210210170715166" style="zoom:50%;" />



#### Application of Simplicial Complex

___

There are many applications of simplicial complex, one of which is persistent homology.

![topological data analysis](Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/topological data analysis.gif)

The idea is that

1. increase the radius of vertices

2. if overlapped, then connect
3. track "birth" and "death" of features like connected components, holes, etc
4. features that persist for a long time are likely "real"

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210171548133.png" alt="image-20210210171548133" style="zoom:50%;" />

As the radius increasing(axis of birth), the "D", "O", "G" are created(**birth**) and **exist for a certain amount of time** until they are connected(**dead**) with excessive radius.



### Comparison Chart of Noun

___

| Discrete Differential Geometry | Rhino/Grasshopper Software | PyTorch Geometric                                            |
| ------------------------------ | -------------------------- | ------------------------------------------------------------ |
| 0-simplex                      | A point                    | ```x = torch.tensor([0,0,0], dtype=torch.float)```           |
| 1-simplex                      | An edge                    | ```edge_index = torch.tensor([[0, 1], [1, 0]], dtype=torch.long)``` |
| 2-simplex                      | A triangle                 | /                                                            |
| Abstract Simplicial Complex    | NA.                        | ```torch_geometric.data.Data```                              |
| Geometric Simplicial Complex   | `Rhino.Geometry.Mesh`      | `read_ply` or `read_obj`                                     |

可以把0-simplex, 1-simplex和2-simplex理解为构建几何世界的基本元素，(只有一个点才是0-simplex，2个点是simplicial complex)。而把基本元素拼凑起来才是Mesh。



## 2.2. Anatomy of a Simplicial Complex: Star, Closure, and Link 

$S$ is a given set of simplices.

***Closure*** $Cl(S)$ is the smallest (i.e., fewest elements) subcomplex of $K$ that contains $S$. In the following diagram, $S$ is a set of 1×triangle and an 1×edge.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210211205145.png" alt="image-20210210211205145" style="zoom:50%;" />

***Star*** $St(S)$ is the collection of all simplices in $K$ that contain any simplex in $S$. In the following diagram, $S$ is a vertex.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210211654892.png" alt="image-20210210211654892" style="zoom:50%;" />

***Link*** $Lk(S)$ is equal to $Cl(St(S)) \backslash St(Cl(S))$ which means taking out the $star\space St(s)$ from $closure\space Cl(S)$. In the following diagram, $S$ is a vertex.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210212146475.png" alt="image-20210210212146475" style="zoom:50%;" />





### Vertices, Edges, and Faces

___

Most of the time, **1-complexes** and **2-complexes** are 2 entities been researched the most. The former is called **graphs** which relates to Graph Machine Learning, Graph Theory, Space Syntax, etc. The later is called **triangle mesh**(trimesh) which relates to Architecture, design, manufacturing, everything!

| simplicial k-complexes | alias         | notation      | Image                                                        |
| ---------------------- | ------------- | ------------- | ------------------------------------------------------------ |
| simplicial 1-complexes | graph         | $G = (V,E)$   | <img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210213615618.png" alt="image-20210210213615618" style="zoom:33%;" /> |
| simplicial 2-complexes | triangle mesh | $K = (V,E,F)$ | <img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210213627501.png" alt="image-20210210213627501" style="zoom:33%;" /> |

- V = vertices
- E = edges
- F = faces
- *K = komplex(in German)



### 2.2.1. Oriented Simplicial Complex

___

#### Orientation of a 1-Simplex

___

$\{a,b\}$   is ***unordered set***.(NO direction)

$(a,b)$ or $(b,a)$    is ***ordered tuples*** which can be illustrated as followed.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210214100027.png" alt="image-20210210214100027" style="zoom:33%;" />

Why *orientation* matters? **Integral**.
$$
\int^b_a f(x)dx = -\int^a_b f(x)dx
$$


#### Orientation of a 2-Simplex

___

For a 2-simplex, orientation given by "winding order" of vertices. An ***oriented 2-simplex*** can be specified by a 3-tuple.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210215052534.png" alt="image-20210210215052534" style="zoom:33%;" />



#### Oriented *k-Simplex*

___

How do we define orientation in general?

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210223018898.png" alt="image-20210210223018898" style="zoom:50%;" />

Definition: An ***oriented k-simplex*** is an *ordered tuple*, up to **even** permutation. 

Why permutation is even? Because there are always **2** orientation **positive-negative** and **clockwise-counterclockwise**. Conventionally, we called the **even-index** permutation as "**positive**" while **odd-index** permutation as "**negative**".



#### Oriented 0-Simplex

___

What’s the orientation of a single vertex?

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210223557050.png" alt="image-20210210223557050" style="zoom:33%;" />

Only one permutation of vertices(the zero-index), so only one orientation - $(a)$! (Positive).



#### Oriented 3-Simplex

___

How to determine this...

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210223830301.png" alt="image-20210210223830301" style="zoom:33%;" />

We can use python for permutation.

```python
>>> import itertools
>>> list(itertools.permutations([1,2,3,4]))
[(1, 2, 3, 4), (1, 2, 4, 3), (1, 3, 2, 4), (1, 3, 4, 2), (1, 4, 2, 3), (1, 4, 3, 2), (2, 1, 3, 4), (2, 1, 4, 3), (2, 3, 1, 4), (2, 3, 4, 1), (2, 4, 1, 3), (2, 4, 3, 1), (3, 1, 2, 4), (3, 1, 4, 2), (3, 2, 1, 4), (3, 2, 4, 1), (3, 4, 1, 2), (3, 4, 2, 1), (4, 1, 2, 3), (4, 1, 3, 2), (4, 2, 1, 3), (4, 2, 3, 1), (4, 3, 1, 2), (4, 3, 2, 1)]
```

Therefore you got this:

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210224421535.png" alt="image-20210210224421535" style="zoom:50%;" />





#### Oriented Simplicial Complex

___

An ***oriented simplicial complex*** is a simplicial complex where each simplex is assigned an orientation. The *orientation* of a simplex is an ordering of its vertices up to even permutation. One can specify an oriented simplex via one of its representative **ordered tuples**. 

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210225701197.png" alt="image-20210210225701197" style="zoom:50%;" />



#### Relative Orientation

___

Two distinct oriented simplices have the same ***relative orientation*** if the two (maximal) faces in their intersection have **opposite** orientation.

<img src="Chapter 02 Combinatorial Surfaces[Lecture-CourseNote].assets/image-20210210225920570.png" alt="image-20210210225920570" style="zoom:50%;" />

共面的边方向相冲，则为relative orientation.



2.3. Simplicial Surfaces 







2.4. Adjacency Matrices 







2.5. Halfedge Mesh