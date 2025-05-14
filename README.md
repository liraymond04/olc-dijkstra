# olc-dijkstra

GUI implementation of Dijkstra's shortest path algorithm in the olcPixelGameEngine.

![dijkstra](https://user-images.githubusercontent.com/39678448/184523029-138e6915-8f88-4b95-a595-20350363bdbf.gif)

## Controls

| Button | Action |
| ----------- | ----------- |
| Esc | Quit |
| Shift + Left click | Create node |
| Ctrl + Left click | Move node |
| Left click | Create edge |
| = | Increase edge weight |
| - | Decrease edge weight |
| D + Left click | Delete node/edge |
| S + Left click | Select start node |
| E + Left click | Select end node |
| Enter | Play shortest path |

## Building

Building is based on Moros1138's [pge-template-project](https://github.com/Moros1138/pge-template-project) CMake files

### Arch Linux

Install the required packages with the following command

`sudo pacman -Sy base-devel cmake git libpng mesa`

Generate project makefiles and build with CMake

```bash
# Use the -d flag to build for debugging
./build.sh
```

You can run the application using the built executable

```bash
./build/olc-dijkstra
```

### Windows

Install a C++ compiler like [MinGW](https://sourceforge.net/projects/mingw/)

Generate project makefiles with CMake

`cmake . -G "MinGW Makefiles"`

And build the project

`mingw32-make`

### Web build with Emscripten
Web builds use [Emscripten](https://github.com/emscripten-core/emscripten), and need the following additional packages:

```bash
sudo pacman -S --needed emscripten
```

Build by passing in a new target flag to the build script

```bash
## Optionally pass the -d flag to build for debug
./build.sh -t web
```

You can run the application by opening a local web server with emrun

```bash
emrun build/olc-rts.html
```
