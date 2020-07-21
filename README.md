# Socket Courier

A cross-platform desktop client for testing WebSocket connections.

## Contributing

### Building

Must have CMake v.18+ and a C++ compiler installed. From the root directory (on a *nix system):

```bash
$ ./cleanup.sh
$ ./configure.sh
$ ./build.sh
```

On Windows, you can use the `bat` scripts instead.

### Choosing your own build system

To see what build systems your CMake install supports, run `cmake --help`. Then, you can build with your build system of choice. For example, on Windows you might do:

```bash
$ cmake -B bin_win64 -- -G "Visual Studio 16 2019" -A x64
#=> Generates a Visual Studio config in ./bin_win64

$ cmake --build bin_win64
#=> Builds using the config in ./bin_win64
```

If the build folder (e.g., `bin`, `bin_64`, `build`, etc.) already exists from a previous build, you may need to remove `CMakeCache.txt` first.

### Running tests

First, Cconfigure and build the project.

```bash
$ cd bin
$ ctest
#=> Results of test suite
```
