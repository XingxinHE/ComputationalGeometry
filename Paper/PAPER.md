# Must Read Paper

This section is about the classic paper on computational geometry.



# :page_with_curl: Paper List

- Mark Meyer, Mathieu Desbrun, Peter Schröder and Alan H. Barr, [Discrete Differential-Geometry Operators for Triangulated 2-Manifolds](http://multires.caltech.edu/pubs/diffGeoOps.pdf), 2003.



# 🧱Structure of a Paper

- Abstract:eyes:
  - the importance of such topic
  - what is the problem?
  - how special this method?
  - the impact of result
- Introduction:speaking_head:
  - definition and the scope of this research
  - challenge of this research direction
  - brief description of your result and impact
- Main:rice: 方法实验步骤
- Result:clapper:
  - the impact of such result
  - different perspective on such result
- Conclusion & Discussion:pencil2:
  - constraints?
  - the TODO issue / Future work



## Discrete Differential-Geometry Operators for Triangulated 2-Manifolds

### 1.Abstract:eyes:

:pushpin: **the importance of such topic**

**:pushpin:what is the problem?**

**:pushpin:how special this method?**

**:pushpin:the impact of result**

### 2.Introduction:speaking_head:

**:pushpin:definition and the scope of this research**

**:pushpin:challenge of this research direction**

**:pushpin:brief description of your result and impact**

### 3.Main:rice: 方法实验步骤

### 4.Result:clapper:

**:pushpin:the impact of such result**

**:pushpin:different perspective on such result**

### 5.Conclusion & Discussion:pencil2:

**:pushpin:constraints?**

**:pushpin:the TODO issue / Future work**









## What's Real About Virtual Reality?

This is the article written by Frederick P. Brooks, Jr. ,Turing Award recipient, back in 1999.  When I think of the latest metaverse boom, I can't help admire his imagination and foresight. So what was his assessment of the state of the VR art which was an infant technology 20 years ago? What could we learn from the past?



<center>
<figure>
  <img src="https://gitee.com/he_xingxin/img/raw/master/Fred_Brooks.jpg" alt="Brooks" style="width:20%" class="center">
  <figcaption>Fig.Frederick P. Brooks, Jr. ©http://www.sdm.de/</figcaption>
</figure>
</center>




### 📌Technologies

He pointed out **4** most crucial technologies and another 4 auxiliary techniques.

#### 🌟Crucial 4:

- Display📺
- Rendering Engine⚙
- Tracking System🖲
- System latency🖥

Display refers to the visual effect that immerse the user in the virtual world and block conflicting sensory impressions from the real world.

<center>
<figure>
  <img src="https://gitee.com/he_xingxin/img/raw/master/unity_display.png" style="width:80%" class="center">
  <figcaption>Interior Demo ©ArchVizPRO</figcaption>
</figure>
</center>

The rendering engine aims to generate ever-changing images which was 20-30 frames per second at that time.

<center>
<figure>
  <img src="https://gitee.com/he_xingxin/img/raw/master/unity_rendering.png" style="width:80%" class="center">
  <figcaption>Bow and Arrow in VR ©Unity</figcaption>
</figure>
</center>

The tracking system constantly reports the position and orientation of users.

<center>
<figure>
  <img src="https://gitee.com/he_xingxin/img/raw/master/image-20211211231021238.png" style="width:80%" class="center">
  <figcaption>Tracing virtual reality helmet's position ©Marvelmind Robotics</figcaption>
</figure>
</center>

The end-to-end system latency builds and maintains the detailed and realistic models of virtual world with ideal smaller than 50ms .

#### ⭐Auxiliary 4:

- Synthesized sound👂
- Kinesthetic Sense💪
- Interaction Devices🥊
- Interaction Techniques👨‍💻

For the crucial 4 are, so to speak, solved, I believe these auxiliary technologies will be the main course of up-coming VR technologies.



### 😁Fun Fact of Headset

Headset is absolutely the first image popped into our mind whenever we talk about VR, like Microsoft HoloLens, HTC Vive, Oculus Rift, etc. But headset was just one of solutions on Display which aims to create the illusion of immersion. Pioneers had tried:

- Head-mounted Display(headset)
- Cave Automatic Virtual Environment
- Panoramic Projectors
- Workbench Projectors
- Desktop Displays

Let's take CAVE from the preceding solutions as an example to illustrate the advantage and disadvantge. 

👍Advantage:

The principal advantage of CAVE is it is capable to give a shared experienced to a small group.

👎Disadvantage:

Display performance like contrast and saturation will be reduced from opposing screens.



<center>
<figure>
  <img src="https://upload.wikimedia.org/wikipedia/commons/6/6d/CAVE_Crayoland.jpg" alt="Trulli" style="width:50%" class="center">
  <figcaption>Fig.The Cave Automatic Virtual Environment at EVL, ©University of Illinois at Chicago.</figcaption>
</figure>
</center>



### 🏠Modeling in AEC & CAD Industry

This is the section relevant to practitioners in AEC and CAD industry where Brook quoted modeling as a substantial engineering work towards exploring large virtual world in real time. As model is the main ingredient of a VR project, model acquisition is of tremendous importance. In general, there are 3 ways:

- Build them, by modeling techniques
- Sense them, via sensing technology or image-based methods
- Inherit them, from byproducts of computer-aided design efforts.



The first refers to merely modeling techniques and we leverage this process by generative technology in our generation. The following is an example to generate a mega scene, a city, with plugin and scripts.

<center>
<figure>
  <img src="https://gitee.com/he_xingxin/img/raw/master/node_workflow.jpg" style="width:80%" class="center">
  <figcaption>Fig.City generator addon for Blender, ©Scene City.</figcaption>
</figure>
</center>



The second includes 3D reconstruction, modeling from image, etc. Although the author only mentioned image-based techniques, the industry witnesses the blossom of techniques that transform a physical object into a virtual representation. The formats are now not only images but also pointclouds.

<center>
<figure>
  <img src="https://s2.loli.net/2021/12/12/D3ptvYIgUTACuok.png" style="width:80%" class="center">
  <figcaption>Fig. Generate Mesh from Images, ©Autodesk Recap.</figcaption>
</figure>
</center>



Considering the latter one, the following 5️⃣pain points are worthy of our attention:

- 1️⃣Formats

There are many formats and they almost have to be translated from one to another.

- 2️⃣Polygonal Ghost

Inactive objects and twinkling geometries in models often require manual cleaning/deleting/moving, etc.

- 3️⃣Geometry Orientation

Some CAD software does not preserve the orientation of geometry, like AutoCAD. Having a consistent orientation to every meshes is hard.

- 4️⃣Nonmanifold

(You know how bad it is...)

- 5️⃣Level of Details

The model from last century lacks of a certain depth of information. Although we have so-called BIM in our age, acquire a model encapsulated with a certain depth of information is still a to-do task.



### 🔥HOT OPEN QUESTION

In the end, Prof. Brooks addressed the HOT open challenges at his time.

Technological Side:
1️⃣ Getting latency down
2️⃣ Rendering massive models (> 1 M polygons) in real time.
3️⃣ Choosing which display best fits each application: HMD, cave, bench, or panorama.
4️⃣ Producing satisfactory haptic augmentation for VR illusions.
Systems Side:
5️⃣ Interacting most effectively with virtual worlds:
	Manipulation
	Specifying travel
	Wayfinding
6️⃣ Making model worlds efficiently:
	Modeling the existing world—image-based techniques
	Modeling nonexisting worlds—through CAD byproducts or hard work
7️⃣Measuring the illusion of presence and its operational effectiveness

From my opinion, 1️⃣2️⃣3️⃣5️⃣7️⃣ are solved more or less. For the future, are 4️⃣6️⃣ the future? Or do you think we could implement the auxiliary 4 mentioned above?



### 🤔Thinking

From his paper, do you see any obstacles have been solved? Or do you see any pin-points might be opportunities in the future? Pleas check it out his publication:





















## Title

### 1.Abstract:eyes:

:pushpin: **the importance of such topic**

**:pushpin:what is the problem?**

**:pushpin:how special this method?**

**:pushpin:the impact of result**

### 2.Introduction:speaking_head:

**:pushpin:definition and the scope of this research**

**:pushpin:challenge of this research direction**

**:pushpin:brief description of your result and impact**

### 3.Main:rice: 方法实验步骤

### 4.Result:clapper:

**:pushpin:the impact of such result**

**:pushpin:different perspective on such result**

### 5.Conclusion & Discussion:pencil2:

**:pushpin:constraints?**

**:pushpin:the TODO issue / Future work**

