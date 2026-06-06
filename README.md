# Chess Knight Moves Calculator

A C++ program that calculates the shortest path for a knight to travel between any two squares on a standard 8×8 chessboard.

## What It Does

- Accepts a starting square and destination square as input (x, y coordinates on an 8×8 board).
- Uses a custom Dijkstra-like shortest-path algorithm to find the minimal number of knight moves.
- Outputs the total number of moves and the exact sequence of squares the knight visits along the way.

## How to Run

### Build

```bash
make
```

### Run

```bash
./test
```

You will be prompted to enter:
1. Current location (x and y coordinates of the starting square)
2. Destination location (x and y coordinates of the target square)

Both coordinates should be between 0 and 7 (inclusive).

### Clean

```bash
make clean     # Windows
make remove    # Unix/Linux
```

## Tech Stack

- **Language:** C++ (C++14)
- **Build System:** Make
- **Concepts:** Graph algorithms, Dijkstra's algorithm, BFS-style pathfinding, OOP

## Project Structure

```
Chess-Knight-Moves-Calculator/
├── TestKnight.cpp   # Main source file with Node class, pathfinding logic, and main()
├── Makefile         # Build configuration
└── README.md
```

## How It Works

The program models each board square as a `Node` with:
- Coordinates (x, y)
- Distance from the source
- Predecessor coordinates for path reconstruction
- A visited flag

It then explores all legal knight moves from the current node, tracks distances, and reconstructs the shortest path once the destination is reached. A knight can move in an L-shape: 2 squares in one direction and 1 square perpendicular.

## Example

```
Enter current location: 0 0
Enter destination location: 7 7
Number of moves: 6
0,0
2,1
4,2
6,3
7,5
7,7
```

## Author

Aaryan Gupta
