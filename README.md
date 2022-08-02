# olc-dijkstra

GUI implementation of Dijkstra's shortest path algorithm in the olcPixelGameEngine.

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

Generate project makefiles with CMake

`cmake .`

And build the project

`make`

### Windows

Install a C++ compiler like [MinGW](https://sourceforge.net/projects/mingw/)

Generate project makefiles with CMake

`cmake . -G "MinGW Makefiles"`

And build the project

`mingw32-make`
