# Library Section:book:

In software engineering, we are always told don't repeat yourself (DRY) or don't reinvent the wheel. Hence, this section introduces few geometry processing libraries.

| Name   | Language | Website                   |
| ------ | -------- | ------------------------- |
| libigl | C++      | https://libigl.github.io/ |
| CGAL   | C++      | https://www.cgal.org/     |
| ...    |          |                           |



## Useful Tool:wrench:

Since many libraries is written in C++, the workflow will be also included in this section. I would like to recommend some handy tools you might find useful in C++ coding.

| Name  | Function            | Website                            |
| ----- | ------------------- | ---------------------------------- |
| vcpkg | C++ Library Manager | https://github.com/microsoft/vcpkg |
| CMake | Build Production    | https://cmake.org/                 |
|       |                     |                                    |



### vcpkg

`vcpkg` /ˈvc pakij/ is a C++ Library Manager for Windows, Linux, and MacOS. It is very handy especially when you are dealing with lots of dependencies in C++. You can see it as `pip` or `conda` in python.

#### 0.Download

```bash
git clone https://github.com/microsoft/vcpkg
```

#### 1.Install vcpkg

```bash
cd vcpkg
.\bootstrap-vcpkg.bat
```

#### 2.Save following location in a .txt file

```bash
CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
```

The command line will pop up something similar to above sentence after installation, I highly recommend you make an empty `.txt` file to save it. Then you can use `vcpkg` with `CMake` outside of an IDE.

#### 3.Search for a library

```bash
.\vcpkg search [library_name]
```

#### 4.Install library

```bash
.\vcpkg install [library_name]
```

#### 5.Install Globally with IDE:star:

```bash
.\vcpkg integrate install
```

This is extremely useful when you are using Visual Studio IDE. After running this command, you can directly use, for example, the installed library by `#include`.

```c++
#include <igl/signed_distance.h>
```

#### 6.Uninstall Globally with IDE

```bash
.\vcpkg integrate remove
```

