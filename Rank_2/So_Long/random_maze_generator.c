#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 16
#define MAX_COLS 30
#define WALL '#'
#define FLOOR ' '
#define COLLECTABLE 'C'
#define START 'P'
#define EXIT 'E'
#define FILE_NAME "maze.ber"

// Structure to represent the maze
typedef struct {
    char grid[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
} Maze;

// Function to initialize the maze with walls
void initializeMaze(Maze* maze) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (i == 0 || i == MAX_ROWS - 1 || j == 0 || j == MAX_COLS - 1) {
                maze->grid[i][j] = WALL;  // Surround with walls
            } else {
                maze->grid[i][j] = WALL;  // Fill the maze with walls initially
            }
        }
    }
    maze->rows = MAX_ROWS;
    maze->cols = MAX_COLS;
}

// Depth-first search algorithm for carving paths
void carvePathDFS(Maze* maze, int x, int y) {
    // Directions for moving: right, down, left, up
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    // Randomize directions
    for (int i = 0; i < 4; i++) {
        int randIndex = rand() % 4;
        int tempX = dx[i];
        int tempY = dy[i];
        dx[i] = dx[randIndex];
        dy[i] = dy[randIndex];
        dx[randIndex] = tempX;
        dy[randIndex] = tempY;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] * 2;
        int ny = y + dy[i] * 2;
        if (ny > 0 && ny < MAX_ROWS - 1 && nx > 0 && nx < MAX_COLS - 1 && maze->grid[ny][nx] == WALL) {
            maze->grid[y + dy[i]][x + dx[i]] = FLOOR; // Carve through the wall
            maze->grid[ny][nx] = FLOOR; // Carve the next cell
            carvePathDFS(maze, nx, ny);
        }
    }
}

// Prim's algorithm for carving paths
void carvePathPrim(Maze* maze) {
    int visited[MAX_ROWS][MAX_COLS] = {0};
    int walls[MAX_ROWS * MAX_COLS][2];
    int wallCount = 0;

    visited[1][1] = 1;
    maze->grid[1][1] = FLOOR; // Start at (1, 1)

    // Add initial walls
    if (maze->grid[2][1] == WALL) {
        walls[wallCount][0] = 2; walls[wallCount++][1] = 1; // down
    }
    if (maze->grid[0][1] == WALL) {
        walls[wallCount][0] = 0; walls[wallCount++][1] = 1; // up
    }
    if (maze->grid[1][2] == WALL) {
        walls[wallCount][0] = 1; walls[wallCount++][1] = 2; // right
    }
    if (maze->grid[1][0] == WALL) {
        walls[wallCount][0] = 1; walls[wallCount++][1] = 0; // left
    }

    while (wallCount > 0) {
        int index = rand() % wallCount;
        int wx = walls[index][0];
        int wy = walls[index][1];

        // Check how many of the adjacent cells are visited
        int visitedNeighbors = 0;
        if (wy + 1 < MAX_ROWS && maze->grid[wy + 1][wx] == FLOOR) visitedNeighbors++; // down
        if (wy - 1 > 0 && maze->grid[wy - 1][wx] == FLOOR) visitedNeighbors++; // up
        if (wx + 1 < MAX_COLS && maze->grid[wy][wx + 1] == FLOOR) visitedNeighbors++; // right
        if (wx - 1 > 0 && maze->grid[wy][wx - 1] == FLOOR) visitedNeighbors++; // left

        if (visitedNeighbors == 1) {
            maze->grid[wy][wx] = FLOOR; // Carve path

            // Add new walls around the new cell
            if (wy + 1 < MAX_ROWS && maze->grid[wy + 1][wx] == WALL) {
                walls[wallCount][0] = wx; walls[wallCount++][1] = wy + 1; // down
            }
            if (wy - 1 > 0 && maze->grid[wy - 1][wx] == WALL) {
                walls[wallCount][0] = wx; walls[wallCount++][1] = wy - 1; // up
            }
            if (wx + 1 < MAX_COLS && maze->grid[wy][wx + 1] == WALL) {
                walls[wallCount][0] = wx + 1; walls[wallCount++][1] = wy; // right
            }
            if (wx - 1 > 0 && maze->grid[wy][wx - 1] == WALL) {
                walls[wallCount][0] = wx - 1; walls[wallCount++][1] = wy; // left
            }

            visited[wy][wx] = 1; // Mark as visited
        }

        // Remove wall from list
        walls[index][0] = walls[--wallCount][0];
        walls[index][1] = walls[wallCount][1];
    }
}

// Function to place collectables randomly in the maze
void placeCollectables(Maze* maze) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (maze->grid[i][j] == FLOOR && rand() % 5 == 0) { // 20% chance to place a collectable
                maze->grid[i][j] = COLLECTABLE;
            }
        }
    }
}

// Function to place start and exit points
void placeStartAndExit(Maze* maze) {
    maze->grid[1][1] = START; // Start point at (1, 1)
    maze->grid[MAX_ROWS - 2][MAX_COLS - 2] = EXIT; // Exit point at bottom right
}

// Function to print the maze to console
void printMaze(const Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            putchar(maze->grid[i][j]);
        }
        putchar('\n');
    }
}

// Function to save the maze to a .ber file
void saveMazeToFile(const Maze* maze) {
    FILE* file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            fputc(maze->grid[i][j] == WALL ? '1' : '0', file);
        }
        fputc('\n', file);
    }
    fclose(file);
}

// Main function
int main() {
    srand(time(NULL));
    Maze maze;
    initializeMaze(&maze);

    // Randomly choose between DFS and Prim's Algorithm
    if (rand() % 2 == 0) {
        carvePathDFS(&maze, 1, 1);
    } else {
        carvePathPrim(&maze);
    }

    placeCollectables(&maze);
    placeStartAndExit(&maze);

    printMaze(&maze);
    saveMazeToFile(&maze);
    
    return 0;
}
