# C++ Examples

Short code examples to cover different C++ language features purely for studying
purposes.

## Getting Started

### Prerequisites

Compiler for C++ code is needed and CMake is needed for generating a build
files.  Some examples uses Google Test testing library to implement unit tests.
Google Test is included as a Git submodule and you need to initialize it after
cloning because it is not automatically done for you. Do this with following on
root of the project

```
git submodule init
git submodule update
```

### Compiling

First make a build directory to root of the project and cd into it

```
mkdir build
cd build
```

Then use CMake to the generate your system's preferred build files

```
cmake ..
```

Then compile examples with

```
cmake --build .
```


## Running Examples

After successful compile executables will be available under build folder in the
same folder structure as examples in `src` folder. For instance running ellipsis
example with following from a build directory

```
./src/ellipsis/ellipsis
```

Study example's printing and source code what is happening. Source code is
usually commented extensively to inform what is happening and what is being
tested.
