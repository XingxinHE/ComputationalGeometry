# 1. Reading Assignment



##### What is the solution of the research field of *Architectural Geometry* ?

___

Discrete Differential Geometry and Numerical Optimization. Also, it is the interdisciplinary research filed between mathematics and computer science.



##### What is *rationalization* and What is *panelization* ??

___

rationalization: The approximation of an ideal design surface by a surface which is suitable for fabrication.

panelization: Replace the design surface by a surface which has a simple generation like a ruled surface

Both are very similar.



##### What is fabrication-aware design?

___

A digital modeling tool which automatically generates only buildable structures of a certain type. 上述的rationalization是设计->工程转换的问题，是解决设计落地的问题。后者fabrication-aware design是直接输出落地的工程解决方案，没有转换过程。



##### What kind of topic includes?

___

Flat panels, Developable panels, Smooth double-curved skins, paneling, support structures, repetition, patterns, statics, shading and other functional aspects, design exploration







## 1.1 Polyhedral surfaces – structures from flat panels

建筑行业一般习惯把free-form的曲面拆分成很多小的板块，这些板块被称为*panel*， 那么将曲面拆分成panel的这种曲面被定义为polyhedral surfaces / polyhedral meshes



### 1.1.1 History of polyhedral surfaces in architecture

___

<img src="https://upload.wikimedia.org/wikipedia/commons/b/b2/Planetarium_Jena.jpg" alt="img" style="zoom:75%;" />

1928, engineers of Carl Zeiss, planetarium in Jena, Germany

Construction method: project the vertices of a platonic solid with regularly triangulated faces to a sphere



<img src="https://fulldome.pro/wp-content/uploads/2019/10/Screenshot-2019-10-14-at-13.32.26.png" alt="Image result for geodesic dome" style="zoom:50%;" />

1940s, R. Buckminster Fuller, geodesic dome

Construction method: increase the stability of triangular elements



### 1.1.2 Triangle meshes from the architectural perspective

___

(1) Edges, mesh has different uses in Computer Graphics and Architecture. 

Graphics: 模糊的，用来rendering比较多，所以一般不会露出edges

Architecture: mesh edges is important for design

(2) Normal vector, this is kind of important for the gaussian image of the surface.

![image-20210204212055938](Chapter 03 Intro to Differential Geometry[Reading&Written Exercise].assets/image-20210204212055938.png)

Hybrid triangle-quad mesh in the roof of Islamic art exhibition in the Louvre, Paris, by Mario Bellini Architects and Rudy Ricciott. 这种是最基础最基本的建筑结构，每一块面折成三角面，所以这种结构最能看出三角形的edges。



### 1.1.3 Planar quad meshes

___

Planar quad mesh = PQ Mesh

<img src="Chapter 03 Intro to Differential Geometry[Reading&Written Exercise].assets/image-20210204212448851.png" alt="image-20210204212448851" style="zoom:67%;" />

PQ Mesh in the roof of Hippo house. 它是平的，可以想象成是一根线sweep过它的曲面顶部。



##### What is conjugate?

___

$s(u,v)$ = parameterization of a surface

$n = (s_u\times s_v)/\lVert s_u\times s_v\rVert$ , unit normal field

$\begin{bmatrix}L&M\\M&N\end{bmatrix} = \begin{bmatrix}s_{uu}\cdot n&s_{uv}\cdot n\\s_{uv}\cdot n&s_{vv}\cdot n\end{bmatrix}$, coefficient matrix

$t_1 = u_1s_u+v_1s_v$ , $t_2 = u_2s_u+v_2s_v$

If second fundamental form:
$$
(t_1, t_2) = Lu_1v_1 + M(u_1v_2 + u_2v_1) + Nu_2v_2 = 0
$$

Then we say $t_1,t_2$ are the conjugate. (principle curvature directions = conjugate direction when orthogonal)



So what if conjugate all about?

You can see it as the surface can be panelized once the surface is divided by conjugate curve.

<img src="Chapter 03 Intro to Differential Geometry[Reading&Written Exercise].assets/image-20210205162948314.png" alt="image-20210205162948314" style="zoom:50%;" />

The blue curves are generated by manually drawn guide-curve. The area of intersection between red curve and blue curve is nearly flat!! (a.k.a it is ok to fabricate)



But in most of the cases, **PQ Mesh** is mostly forced to use principal curvature line to remesh. You can easily sense the principal curvature direction along the roof in the following image

<img src="Chapter 03 Intro to Differential Geometry[Reading&Written Exercise].assets/image-20210205163644927.png" alt="image-20210205163644927" style="zoom:67%;" />

:warning:PQ Mesh is hard and easily failed to remesh surface like minimal surface马鞍面(which $t_1=-t_2$)!!



### 1.1.4 Nearly rectangular panels, support structures and offsets

Nearly rectangular panels are sustainable and preferable in fabrication since it saves lots of materials and energy. There are 2 types of these: ***Circular meshes*** and ***Conical meshes***.













  