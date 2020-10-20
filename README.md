# Independent Cascade Model using temporal networks

## Content
  - [About the project](#about-the-project)
  - [Prerequisites](#prerequisites)
    - [To install mingw-w64](#to-install-mingw-w64)
  - [How to compile](#how-to-compile)
  - [How to use it](#how-to-use-it)

## About the project
This project was developed in the course PA1414 given at Blekinge Institute of Technology. The objective of the project was to be able to determine the nodes that could be reached in a temporal network using the independent cascade model.

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
The project can be run in two ways. Either by only making one test on a network or by making multiple tests on a network.
To run only one test on the network using the project use the following command:
**projectExecutable networkFile nodeAmount timeCase beta output startNodes**

- **projectExecutable**: is the executable that is built by running: **mingw32-make implementation**
- **networkFile**: the relative path to a txt file that represents the network
- **nodeAmount**: is the amount of nodes that exist in the network that was given in the last parameter
- **timeCase**: represent three different cases of diffusion time that is able to be represented, **best_case**, **average_case** and **worst_case**
- **beta**: a decimal number between 0.0 and 1.0 to determine the probability that a node is affected by a adjacent node.
- **output**: the txt file that the output should be written to, but it can also be enterd as "terminal", which results in a output in the terminal.
- **startNodes**: the IDs that represent the nodes that should already be affected when running the test. Any amount of nodes can be entered, but they have to be space separated, an example: **nodeID1 nodeID2 nodeID3**

An example when standing in the bin folder: **./Project.exe ../utility/data.txt 5 best_case 1.0 terminal 792 386**

**To run multiple cases** enter the following into the command line: **projectExecutable networkFile nodeAmount testCases**

- **projectExecutable**: is the executable that is built by running: **mingw32-make implementation**
- **networkFile**: the relative path to a txt file that represents the network
- **nodeAmount**: is the amount of nodes that exist in the network that was given in the last parameter
- **testCases**: is the relative path to a txt file that contains test cases on each row, these test cases are structured in this way: **timeCase output beta startNodes**
  - **timeCase**: represent three different cases of diffusion time that is able to be represented, **best_case**, **average_case** and **worst_case**
  - **beta**: a decimal number between 0.0 and 1.0 to determine the probability that a node is affected by a adjacent node.
  - **output**: the txt file that the output should be written to, but it can also be enterd as "terminal", which results in a output in the terminal.
  - **startNodes**: the IDs that represent the nodes that should already be affected when running the test. Any amount of nodes can be entered, but they have to be space separated, an example: **nodeID1 nodeID2 nodeID3**



An **example** of how to run **multiple cases** (standing in bin folder): **Project.exe ../utility/data.txt 5 ../utility/dataTestCases.txt**

<br>
<br>

### Project created by **Ludvig Halling** ###