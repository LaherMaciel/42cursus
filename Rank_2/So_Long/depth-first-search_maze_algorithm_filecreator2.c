#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIDTH 29  // Width of the maze (must be odd)
#define HEIGHT 15 // Height of the maze (must be odd)

typedef struct {
    int x, y;
} Point;

// Directions to explore (up, down, left, right)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// Check if a point is within bounds
int inBounds(int x, int y) {
    return (x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1);
}

// Initialize the maze with walls
void initializeMaze(int maze[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x] = 1; // Wall
        }
    }
}

// Place a path in the maze
void placePath(int maze[HEIGHT][WIDTH], int x, int y) {
    maze[y][x] = 0; // Path
}

// Perform DFS to generate the maze
void dfsMazeGeneration(int maze[HEIGHT][WIDTH], int x, int y) {
    // Randomize direction order to create a random maze
    int directions[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[directions[i]] * 2;
        int ny = y + dy[directions[i]] * 2;

        if (inBounds(nx, ny) && maze[ny][nx] == 1) {
            // Knock down the wall between current cell and the next cell
            placePath(maze, x + dx[directions[i]], y + dy[directions[i]]);
            placePath(maze, nx, ny);
            dfsMazeGeneration(maze, nx, ny);
        }
    }
}

// Perform DFS to check if all collectables and exit are reachable
void dfsCheck(int maze[HEIGHT][WIDTH], int visited[HEIGHT][WIDTH], int x, int y) {
    if (!inBounds(x, y) || visited[y][x] || maze[y][x] == 1) return;

    visited[y][x] = 1;

    // Explore in all four directions
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfsCheck(maze, visited, nx, ny);
    }
}

// Check if the maze is valid (start -> exit and all collectables reachable)
int isValidMaze(int maze[HEIGHT][WIDTH], Point start, Point exit, Point collectables[], int collectableCount) {
    int visited[HEIGHT][WIDTH] = {0};

    // Perform DFS to check connectivity from the start
    dfsCheck(maze, visited, start.x, start.y);

    // Ensure exit is reachable
    if (!visited[exit.y][exit.x]) return 0;

    // Ensure all collectables are reachable
    for (int i = 0; i < collectableCount; i++) {
        if (!visited[collectables[i].y][collectables[i].x]) return 0;
    }

    return 1;
}

// Place collectables in the maze
void placeCollectables(int maze[HEIGHT][WIDTH], Point collectables[], int collectableCount) {
    for (int i = 0; i < collectableCount; i++) {
        int x, y;
        do {
            x = 1 + (rand() % ((WIDTH - 2) / 2)) * 2;
            y = 1 + (rand() % ((HEIGHT - 2) / 2)) * 2;
        } while (maze[y][x] != 0);

        maze[y][x] = 'C';
        collectables[i] = (Point){x, y};
    }
}

// Print the maze
void printMaze(int maze[HEIGHT][WIDTH], Point start, Point exit) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == start.x && y == start.y) {
                printf("P ");
            } else if (x == exit.x && y == exit.y) {
                printf("E ");
            } else if (maze[y][x] == 0) {
                printf("  ");
            } else if (maze[y][x] == 'C') {
                printf("C ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }
}

// Save the maze to a .ber file
void saveMazeToFile(int maze[HEIGHT][WIDTH], Point start, Point exit) {
    char filename[32];
    int count = 0;
    FILE *file;

    // Find a unique filename
    do {
        sprintf(filename, "dfs_maze_%d.ber", count++);
        file = fopen(filename, "r");
        if (file) fclose(file);
    } while (file);

    file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == start.x && y == start.y) {
                fputc('P', file);
            } else if (x == exit.x && y == exit.y) {
                fputc('E', file);
            } else if (maze[y][x] == 0) {
                fputc('0', file);
            } else if (maze[y][x] == 'C') {
                fputc('C', file);
            } else {
                fputc('1', file);
            }
        }
        fputc('\n', file);
    }

    fclose(file);
    printf("Maze saved to %s\n", filename);
}

int main() {
    srand(time(NULL));

    int maze[HEIGHT][WIDTH];
    Point start = {1, 1};
    Point exit = {WIDTH - 2, HEIGHT - 2};
    Point collectables[10];
    int collectableCount = 1 + rand() % ((WIDTH * HEIGHT) / 20);

    do {
        // Initialize maze and generate with DFS
        initializeMaze(maze);
        dfsMazeGeneration(maze, start.x, start.y);

        // Place collectables
        placeCollectables(maze, collectables, collectableCount);
    } while (!isValidMaze(maze, start, exit, collectables, collectableCount));

    // Print and save maze
    printMaze(maze, start, exit);
    saveMazeToFile(maze, start, exit);

    return 0;
}
