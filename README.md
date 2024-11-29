# so_long - 42 Project

A simple top-down 2D game built in C using MiniLBX

## 🎮 Rules
Move using W, A, S, D.
Collect all the chickens and safely reach the exit, avoiding the guard dogs.

## 📋 Program Requirements
The map may only contain the following characters:

P (Player)
1 (Wall)
0 (Empty Space)
C (Collectible)
E (Exit)
(Optional: N for enemies, available in the bonus version)

The map must meet the following conditions:

It must be rectangular: all rows must have the same length.
It must contain at least one exit, one player, and one collectible.
It must be closed: fully surrounded by walls.

## Installation
Clone the repository 
git clone https://github.com/your-repo/so_long.git
cd so_long

Compile the game:

For the basic game, run:
make

For the bonus version (with extra features), run:
make bonus

Run the game:

./so_long maps/<map-name>.ber

The game has been only tested on MacOS.

## 📂 Available Maps
Currently, there are 6 maps included:

3 for the basic version
3 for the bonus version
Feel free to create your own maps following the format rules!

## ✨ Bonus Features
The bonus version includes:

Animation: Adds life to the game with moving elements.
Patrolling Enemies: Avoid enemies that move along predetermined paths.
Move Counter: Displays the number of moves on the screen.

- Animation
- Patrolling enemies
- Move counter on the screen

## 🎨 Assets
To create this mini game I used the assets from  - amazing creators on itch.io

## 🐞 Feedback and Bugs
Enjoy the game! If you encounter any bugs, feel free to reach out.


