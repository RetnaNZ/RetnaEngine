# RetnaEngine

A minimal C++ game engine starter project using SDL2 for windowing and rendering.

## Prerequisites
- CMake 3.10 or higher
- C++17 compatible compiler (MSVC, MinGW, etc.)
- SDL2 development libraries (make sure SDL2 is installed and available to CMake)

## Building on Windows

1. Install SDL2 development libraries and ensure they are discoverable by CMake.
2. Open a terminal in the project directory.
3. Run the following commands:

```
mkdir build
cd build
cmake ..
cmake --build .
```

4. Run the executable from the build directory:

```
./RetnaEngine.exe
```

You should see a window titled "RetnaEngine Window".

## Next Steps
- Add more engine features (input, rendering, scenes, etc.)
- Explore SDL2 documentation for more capabilities
