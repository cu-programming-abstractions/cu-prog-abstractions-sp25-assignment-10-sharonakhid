Knight Moves — Homework
==============================
Find the minimum number of moves for a knight to reach a target position using BFS (Breadth-First Search).

---

## Story
You're programming a chess knight to find the shortest path to any position on an infinite chessboard. A knight moves in an L-shape: 2 squares in one direction and 1 square perpendicular to that, giving 8 possible moves from any position.

### Problem Variants
1. **Minimum Moves** – Find the shortest number of moves required
2. **Complete Path** – Get the actual sequence of positions from start to target
3. **Infinite Board** – Handle any coordinate including negative positions

---

## Files

```
knight_moves.pro        Qt project
src/
  knight.h              Position structure and function declarations (with TODOs)
  knight.cpp             BFS algorithms implementation (with detailed TODOs)
  main.cpp               Built-in test cases with verification
```

---

## Project Features

### Comprehensive TODOs
Each file contains detailed TODO comments explaining:
- **knight.h**: Position structure, hash functions, and algorithm interfaces
- **knight.cpp**: Step-by-step BFS implementation guides for both functions
- **main.cpp**: Test framework and verification logic

### Built-in Test Cases
The program includes 6 comprehensive test cases:
1. **Same Position Test** - Edge case where start equals target (0 moves)
2. **Single Knight Move Test** - Basic one-move scenario
3. **Two Knight Moves Test** - Multi-step pathfinding
4. **Negative Coordinates Test** - Infinite board handling
5. **Large Distance Test** - Performance with longer paths
6. **Asymmetric Move Test** - Complex pathfinding scenario

### Test Verification
- Automatic path validation (each step is a valid knight move)
- Path length verification against minimum moves
- Start/end position correctness
- Edge case handling
- Visual path display

---

## Tasks

### 1 · minKnightMoves  (BFS shortest path)

```cpp
int minKnightMoves(const Pos& start, const Pos& target);
```

**Implementation Requirements:**
* Use BFS (Breadth-First Search) for optimal solution
* Handle infinite board (no boundary constraints)
* Return minimum number of moves required
* Optimize for negative coordinates
* Handle edge case where start == target (return 0)

**Algorithm Overview:**
- Initialize queue with start position
- Track visited positions to avoid cycles
- Generate all 8 possible knight moves for each position
- Return distance when target is reached

**Detailed TODO available in knight.cpp**

### 2 · getKnightPath  (BFS with path reconstruction)

```cpp
vector<Pos> getKnightPath(const Pos& start, const Pos& target);
```

**Implementation Requirements:**
* Use BFS with parent tracking for path reconstruction
* Return complete path including start and target positions
* Path should be optimal (shortest possible)
* Handle edge cases gracefully

**Algorithm Overview:**
- Run BFS while tracking parent relationships
- When target is found, reconstruct path by following parents
- Return path from start to target

**Detailed TODO available in knight.cpp**

### 3 · isValidPosition  (Helper function)

```cpp
bool isValidPosition(const Pos& pos, int boardSize = -1);
```

**Implementation Requirements:**
* Handle infinite board case (boardSize == -1)
* Support bounded board variants
* Return appropriate validation result

---

## Build / Run

```bash
qmake
make
./knight_moves
```

**No command-line arguments needed!** The program runs built-in test cases automatically.

### Expected Output
```
Testing Knight Moves Algorithms
==================================================

=== Same Position Test ===
Start: (0, 0) -> Target: (0, 0)
Minimum moves: 0
Path length: 0
Path: (0, 0)
--------------------------------------------------
✓ Same Position Test passed

=== Single Knight Move Test ===
Start: (0, 0) -> Target: (2, 1)
Minimum moves: 1
Path length: 1
Path: (0, 0) -> (2, 1)
--------------------------------------------------
✓ Single Knight Move Test passed

Test Summary: 6/6 tests passed
All tests passed! Knight moves implementation is working correctly.
```

---

## Algorithm Details

### Knight Movement Pattern
A knight can move to 8 possible positions from any given position:
```
  . N . N .
  N . . . N
  . . K . .
  N . . . N
  . N . N .
```
Where K is the knight's current position and N represents possible next positions.

### BFS Advantages
- **Optimal Solution**: BFS guarantees the shortest path
- **Systematic Exploration**: Explores all positions at distance d before distance d+1
- **Complete**: Will find a solution if one exists

### Time & Space Complexity
- **Time**: O(V + E) where V is vertices visited and E is edges explored
- **Space**: O(V) for the queue and visited set
- **Practical**: Very efficient for reasonable distances

---

## Data Structures

### Position Structure
```cpp
struct Pos {
    int row, col;
    bool operator==(const Pos& other) const;
    bool operator!=(const Pos& other) const;
};
```

### Hash Function
Custom hash function for using `Pos` in `unordered_set` and `unordered_map`:
```cpp
struct PosHash {
    size_t operator()(const Pos& p) const;
};
```

---

### Memory & Style
* No memory leaks (all containers manage their own memory)
* Functions ≤ 50 lines; helper functions encouraged
* Descriptive names and comprehensive comments
* Detailed TODOs guide implementation

### Development Notes
* Test cases verify correctness automatically
* Visual path display helps debug implementation
* Handles infinite board (negative coordinates allowed)
* Optimized for both single queries and path reconstruction

Submit only:
```
src/knight.h
src/knight.cpp
```