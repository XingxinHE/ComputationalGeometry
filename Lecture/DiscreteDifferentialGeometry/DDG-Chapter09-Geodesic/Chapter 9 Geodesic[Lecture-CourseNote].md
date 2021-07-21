# Chapter 09 Geodesic



## Overview

What is **geodesic**?

We all know one fact from our elementary school that the closest distance between 2 points is connected by a line. The line is the:

> 1. straightest path - *no curvature/acceleration*
> 2. shortest path - *(locally) minimize length*

So **Geodesic** generalizes this idea to curved spaces. Although we very much care about discrete geodesic distance, it does start from curved space. 

<img src="Chapter 9 Geodesic[Lecture-CourseNote].assets/image-20210621212256942.png" alt="image-20210621212256942" style="zoom:50%;" />





However, there is something between curved space and plane. We call plane as Euclidean Geometry while curved space as Non-Euclidean Geometry. Looking at following example:

For any line 𝓁 and point $p$ not on 𝓁, there’s **a** unique line parallel to 𝓁 passing through $p$

<img src="Chapter 9 Geodesic[Lecture-CourseNote].assets/image-20210621214946384.png" alt="image-20210621214946384" style="zoom:67%;" />

But it is not true in following cases:

<img src="Chapter 9 Geodesic[Lecture-CourseNote].assets/image-20210621215304941.png" alt="image-20210621215304941" style="zoom: 33%;" />

- Elliptic: **no** parallel lines through a point—all lines intersect

- Hyperbolic: **many** parallel line through point is not unique

So today we will see that shortest and straightest disagree in simplicial surfaces.



## Intrinsic & Extrinsic?

<img src="Chapter 9 Geodesic[Lecture-CourseNote].assets/image-20210621220251013.png" alt="image-20210621220251013" style="zoom: 50%;" />

One image to illustrate the idea between intrinsic and extrinsic:

> An **intrinsic** property will **not change**, regardless of how we represent the object, an extrinsic property does not have the same immutability.

For example, the distance(intrinsic) between two hands below will not change. Just imagine there is an ant crawling from right hand to left hand. No matter how this guy performs, the ant always has to crawl a static distance.(You can also see it as topological structure)

<img src="Chapter 9 Geodesic[Lecture-CourseNote].assets/image-20210621220708099.png" alt="image-20210621220708099" style="zoom:50%;" />

Just like the map, if you fold the map, the length of the river doesn't change at all.

<img src="Chapter 9 Geodesic[Lecture-CourseNote].assets/image-20210621221442634.png" alt="image-20210621221442634" style="zoom: 33%;" />

This is also called Isometry Invariance which preserves the **Riemannian metric** (which measures lengths & angles of tangent vectors).



## Shortest

