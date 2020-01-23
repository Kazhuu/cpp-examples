# C++ Examples

Short code examples to cover different C++ language features for studying
purposes. Examples are commented so someone can also follow them.

## Getting Started

### Prerequisites

You will need a C++ compiler with C++17 support, CMake version 3.8 or greater
for generating a build files and Boost C++ library. Some examples uses Google
Test testing library to implement unit tests.

To install CMake you can either compile it yourself or install from APT
repository. To compiler it yourself follow [this](https://cmake.org/install/)
guide. To install from APT run following
```
sudo apt install cmake
```
If installing from APT repository make sure it's version is at least 3.8 or
greater. To check that run `cmake --version`.

Google Test is included as a Git submodule and you need
to initialize it after cloning because it is not automatically done for you. Do
this with following on root of the project
```
git submodule init
git submodule update
```
To install Boost library you can download it from
[here](https://www.boost.org/users/download/) or on Ubuntu run
```
sudo apt-get install libboost-all-dev
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
