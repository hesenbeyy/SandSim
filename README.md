
# Falling Sand Simulation

A real-time 2D cellular automaton built with **C++** and **SFML**. This project simulates the behavior of sand particles, allowing users to draw, erase, and observe physics-like interactions in a grid-based environment.


## 📺 Demo video



https://github.com/user-attachments/assets/73c39e74-cd17-4a0f-bc61-0b1aecafc2bc



## 🚀 Features

* **Particle Physics**: Sand falls vertically and piles up realistically by sliding diagonally when the path below is blocked.
* **Interactive Drawing**: Use your mouse to "pour" sand into the simulation or erase it.
* **Dynamic Coloring**: Particles change color based on their vertical position, creating a vibrant gradient effect.
* **Grid Management**: Efficiently handles a grid of $80 \times 60$ (or custom) cells using a 2D vector system.

---

## 🎮 Controls

| Key/Mouse | Action |
| --- | --- |
| **Left Click (Hold)** | Spawn sand at mouse position |
| **Right Click (Hold)** | Erase sand (Vacuum tool) |
| **R Key** | Reset/Clear the entire grid |
| **E Key** | Randomly initialize the grid with sand |
| **Esc Key** | Close the application |

---

## 🛠️ Logic Breakdown

The simulation operates on a simple set of rules for each particle at position $(x, y)$:

1. **Vertical Fall**: If the cell below (x, y+1) is empty, move the particle down.
2. **Diagonal Slide**: If the cell below is occupied, check the bottom-left (x-1, y+1) and bottom-right (x+1, y+1) cells randomly to simulate natural sliding.
3. **Optimization**: The simulation iterates from the bottom up to ensure particles move correctly within a single frame update.

---

## 📦 Prerequisites

Before building, ensure you have the following installed:

* **C++ Compiler** (GCC, Clang, or MSVC)
* **CMake** (version 3.10 or higher)
* **SFML Library** (Simple and Fast Multimedia Library)

## 🔨 Building and Running

Since the project uses **CMake**, it is cross-platform. Follow the steps for your specific operating system:

Firstly, clone the repository:
```

git clone https://github.com/hesenbeyy/SandSim

```

### 🪟 Windows (Visual Studio)

1. Install [SFML](https://www.sfml-dev.org/download.php) and [CMake](https://cmake.org/download/).
2. Open a terminal (PowerShell or CMD) in the project folder:
```powershell
mkdir build
cd build
cmake ..

```


3. Open the generated `.sln` file in **Visual Studio**.
4. Set the build configuration to **Release** and press **F5** to build and run.
* *Note: Ensure the SFML `.dll` files are in the same folder as your `.exe`.*



### 🍎 macOS

1. Install Homebrew and SFML:
```bash
brew install sfml cmake

```


2. Build the project:
```bash
mkdir build && cd build
cmake ..
make

```


3. Run the executable:
```bash
./SandSimulation

```



### 🐧 Linux (Ubuntu/Debian)

1. Install dependencies:
```bash
sudo apt-get install libsfml-dev cmake g++

```


2. Build and run:
```bash
cmake -S . -B build
cmake --build build
cd build

./SandSimulation

```



---

## 💡 Troubleshooting

* **SFML Not Found**: If CMake can't find SFML, you may need to set the `SFML_DIR` variable to the path where SFML is installed (e.g., `cmake -DSFML_DIR=/path/to/sfml/lib/cmake/SFML ..`).
* **Graphics Drivers**: Ensure your OpenGL drivers are up to date, as SFML relies on hardware acceleration for rendering the grid.


4. **Run the executable**:
```bash
./SandSimulation # Or SandSimulation.exe on Windows

```



---

## 📝 Project Structure

* `main.cpp`: Entry point and SFML window loop.
* `macros.hpp`: Configuration constants (Width, Height, Cell Size) and the `Sand` class definition.
* `funcs.cpp`: Implementation of drawing logic and cellular automaton rules.
* `CMakeLists.txt`: Build configuration file.

---

Would you like me to help you add more materials, like "water" or "stone," to the simulation logic next?
