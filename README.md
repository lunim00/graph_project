# Independent Cascade Model using temporal networks

## Content
  - [About the project](#about-the-project)
  - [Prerequisites](#prerequisites)
    - [To install mingw-w64](#to-install-mingw-w64)
  - [How to compile](#how-to-compile)
  - [How to use it](#how-to-use-it)

## About the project

## Prerequisites
To be able to compile this project the following prerequisites are needed:
- mingw-w64

### To install mingw-w64
- [Download](http://mingw-w64.org/doku.php/download)
- Run installer
- Choose x86_64 as architecture
- Finish the installation
- Add the mingw-w64 bin folder to your PATH variable

## How to compile
To compile the project you need the [prerequisites](#prerequisites) that were mentioned before. 
### To compile for x86_64
- Stand in the root of the project
- Run **mingw32-make implementation**
- (to clear the build and executable files run **mingw32-make clean**)

## How to use it
To run the project with the executable that is created by running **mingw32-make implementation** run: **./bin/Project.exe file nodeAmount startNodes**
- file: Is the relative path from root to the txt file that contain the edges
- nodeAmount: Is the amount of nodes that exist in the test file
- startNodes: These are the nodes that will be active when the test starts, and these are space separated

As an example: **./bin/Project.exe ./utility/data.txt 5 792 386**

### Replace content of main.cpp
The content of main.cpp can also be modified to support different types of tests 