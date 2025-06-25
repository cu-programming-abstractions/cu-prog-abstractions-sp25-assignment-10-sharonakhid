#include "knight.h"
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

/* -------- minKnightMoves -------- */
int minKnightMoves(const Pos& start, const Pos& target) {
    if (start == target) return 0; // Edge case: same position

    // Directions for knight moves
    vector<Pos> directions = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    queue<pair<Pos, int>> bfsQueue; // Pair of position and distance
    unordered_set<Pos, PosHash> visited; // Track visited positions

    bfsQueue.push({start, 0});
    visited.insert(start);

    while (!bfsQueue.empty()) {
        auto [current, distance] = bfsQueue.front();
        bfsQueue.pop();

        for (const auto& dir : directions) {
            Pos next = {current.row + dir.row, current.col + dir.col};

            if (next == target) {
                return distance + 1; // Return distance when target is reached
            }

            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                bfsQueue.push({next, distance + 1});
            }
        }
    }

    return -1; // Should never reach here for valid inputs
}

/* -------- getKnightPath -------- */
vector<Pos> getKnightPath(const Pos& start, const Pos& target) {
    if (start == target) return {start}; // Edge case: same position

    vector<Pos> directions = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    queue<Pos> bfsQueue;
    unordered_map<Pos, Pos, PosHash> parent; // Track parent positions
    unordered_set<Pos, PosHash> visited;

    bfsQueue.push(start);
    visited.insert(start);

    while (!bfsQueue.empty()) {
        Pos current = bfsQueue.front();
        bfsQueue.pop();

        for (const auto& dir : directions) {
            Pos next = {current.row + dir.row, current.col + dir.col};

            if (next == target) {
                parent[next] = current; // Track parent for path reconstruction
                vector<Pos> path;
                for (Pos at = target; at != start; at = parent[at]) {
                    path.push_back(at);
                }
                path.push_back(start);
                reverse(path.begin(), path.end());
                return path; // Return the reconstructed path
            }

            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                parent[next] = current; // Track parent
                bfsQueue.push(next);
            }
        }
    }

    return {}; // Should never reach here for valid inputs
}

/* -------- isValidPosition -------- */
bool isValidPosition(const Pos& pos, int boardSize) {
    if (boardSize == -1) {
        return true; // Infinite board
    }
    return pos.row >= 0 && pos.row < boardSize &&
           pos.col >= 0 && pos.col < boardSize;
}
