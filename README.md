# yaml-cpp Practice

Practice of [yaml-cpp](https://github.com/jbeder/yaml-cpp), which allow us to use yaml in C++

## How to run

### Environment
Ubuntu 16.04.2 LTS

```sh
# Install yaml-cpp
# (from: https://stackoverflow.com/a/23656283)
$ sudo apt install libyaml-cpp-dev

# Install boost because yaml-cpp uses boost
# (from: https://stackoverflow.com/a/12578564)
$ sudo apt install libboost-dev

$ cd <this-repo>
$ g++ main.cpp -lyaml-cpp
$ ./a.out
```
