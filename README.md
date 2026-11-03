# pwd
pwd (Print Working Directory): \
A reimplementation of the Linux command `pwd` in C.

## Development Environment
- OS: Linux Mint
- GCC Toolchain
- GNU Make


## Make Commands

- `make` -	Build the project
- `make all` -	Same as make
- `make -j$(nproc)` -	Build using all available CPU cores
- `make clean` -	Remove build/ and the output binary
- `make rebuild` -	Clean everything and rebuild


## Usage
```
pwd <no args>      -> Print logical path to current working directory.
pwd -L             -> Print logical path to current working directory.
pwd -P             -> Print physical path to current working directory.
pwd -v             -> Print pwd version.
pwd -h             -> Print pwd help.
```


## License
MIT
