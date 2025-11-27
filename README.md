
# 🧱 Cub3D

Cub3D is a simple **3D raycasting engine** inspired by *Wolfenstein 3D*, built with **C** and the **MiniLibX** graphics library.  
This project introduces fundamental concepts of **computer graphics**, **raycasting**, **player movement**, and **texture mapping**.

<img width="1289" height="749" alt="image" src="https://github.com/user-attachments/assets/c2c26beb-6f0b-47fd-9aa2-5abc61cc9979" />

---

## 🚀 Features

- 🧭 **First-person view** with smooth camera rotation  
- 🪞 **Raycasting engine** (walls rendered using DDA algorithm)  
- 🧱 **Textured walls** with correct scaling and perspective  
- 🚪 **Animated doors** (open/close when player approaches)  
- 🗺️ **Minimap** with player position and field of view  
- ⌨️ **Keyboard and mouse input** for movement and rotation  
- 🎨 **Ceiling and floor colors** loaded from `.cub` configuration files  
- 🖼️ **External textures** loaded from `.xpm` files  

---

## 🧩 Controls

| Key | Action |
|-----|---------|
| `W / S` | Move forward / backward |
| `A / D` | Strafe left / right |
| `← / →` | Rotate camera |
| `ESC` | Exit game |

Mouse look can also be enabled if implemented.

---

## 🗂️ Project Structure
```
cub3D/
├── include/ # Header files
├── src/ # Source code
│ ├── parsing/ # Map and texture parsing
│ ├── raycasting/ # Raycasting engine
│ ├── render/ # Drawing functions
│ ├── player/ # Movement and input
│ └── utils/ # Helpers
├── libft/ # Custom C library
├── minilibx-linux/ # MiniLibX graphics library
└── maps/ # Example .cub maps
```

---

## 🧠 How It Works

1. The `.cub` file is parsed to load:
   - Wall textures (NO, SO, EA, WE)
   - Floor and ceiling colors
   - Map layout (with `1` = wall, `0` = empty, `D` = door, `N/S/E/W` = player)

2. Each frame:
   - Rays are cast for every vertical screen column.
   - Wall intersections are calculated using **DDA** (Digital Differential Analyzer).
   - The correct texture and column slice are drawn based on distance.
   - Doors are animated progressively.

3. The result is a **pseudo-3D world** rendered from a 2D map.

---

## 🧱 Compilation

```bash
make
./cub3D maps/test_map.cub
```

⚙️ Requirements

gcc or clang

make

MiniLibX (Linux or macOS)

libft (42’s standard C library)


On Linux, you may need to install:
```bash
sudo apt-get install libx11-dev libxext-dev
```
🧪 Example Map Format
```
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
DO ./textures/door.xpm

F 120,120,120
C 60,60,60

111111
1N0D01
100001
111111
```
## Tutorials
https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/

https://lodev.org/cgtutor/raycasting.html

https://www.youtube.com/watch?v=NbSee-XM7WA

https://github.com/iciamyplant/Cub3d-Linux
