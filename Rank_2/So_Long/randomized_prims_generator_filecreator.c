#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIDTH 29  // Width of the maze (must be odd)
#define HEIGHT 15 // Height of the maze (must be odd)
#define MAX_WALLS ((WIDTH * HEIGHT) / 2) // Max number of walls we can have

typedef struct {
    int x, y;
} Point;

// Check if a point is within bounds
int inBounds(int x, int y) {
    return (x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1);
}

// Place a wall in the maze
void placeWall(int maze[HEIGHT][WIDTH], int x, int y) {
    maze[y][x] = 1; // Wall
}

// Place a path in the maze
void placePath(int maze[HEIGHT][WIDTH], int x, int y) {
    maze[y][x] = 0; // Path
}

// Add a wall to the wall list
void addWall(Point walls[], int *wallCount, int x, int y) {
    if (inBounds(x, y) && *wallCount < MAX_WALLS && walls != NULL) { // Ensure walls are within bounds
        walls[*wallCount].x = x;
        walls[*wallCount].y = y;
        (*wallCount)++;
    }
}

// Randomly shuffle the wall list
void shuffleWalls(Point walls[], int wallCount) {
    for (int i = 0; i < wallCount; i++) {
        int j = rand() % wallCount;
        Point temp = walls[i];
        walls[i] = walls[j];
        walls[j] = temp;
    }
}

// Check if a wall can be turned into a path
int canBePath(int maze[HEIGHT][WIDTH], int x, int y) {
    int pathCount = 0;
    if (inBounds(x, y + 1) && maze[y + 1][x] == 0) pathCount++;
    if (inBounds(x, y - 1) && maze[y - 1][x] == 0) pathCount++;
    if (inBounds(x + 1, y) && maze[y][x + 1] == 0) pathCount++;
    if (inBounds(x - 1, y) && maze[y][x - 1] == 0) pathCount++;
    return pathCount == 1; // A valid path has exactly one adjacent path
}

// Generate the maze using Prim's algorithm
void generateMaze(int maze[HEIGHT][WIDTH], Point *start, Point *exit) {
    // Initialize maze with walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x] = 1; // Wall
        }
    }

    // Start at a random position
    int startX = 1 + (rand() % ((WIDTH - 2) / 2)) * 2;
    int startY = 1 + (rand() % ((HEIGHT - 2) / 2)) * 2;
    *start = (Point){startX, startY};
    placePath(maze, startX, startY); // Create starting path

    // Walls to consider for adding paths
    Point walls[MAX_WALLS]; 
    int wallCount = 0;

    // Add initial walls around the starting position
    addWall(walls, &wallCount, startX, startY + 1);
    addWall(walls, &wallCount, startX, startY - 1);
    addWall(walls, &wallCount, startX + 1, startY);
    addWall(walls, &wallCount, startX - 1, startY);

    // Prim's algorithm
    while (wallCount > 0) {
        shuffleWalls(walls, wallCount);
        
        // Choose a random wall
        Point currentWall = walls[--wallCount];  // Remove the last wall
        int x = currentWall.x;
        int y = currentWall.y;

        // Check if the wall can become a path (has one path and one wall around)
        if (canBePath(maze, x, y)) {
            placePath(maze, x, y);

            // Add neighboring walls if they are within bounds and valid
            addWall(walls, &wallCount, x + 1, y);
            addWall(walls, &wallCount, x - 1, y);
            addWall(walls, &wallCount, x, y + 1);
            addWall(walls, &wallCount, x, y - 1);
        }
    }

    // Set exit point
    *exit = (Point){WIDTH - 2, HEIGHT - 2}; // Bottom-right corner
    placePath(maze, exit->x, exit->y); // Open exit cell
}

// Place collectables in the maze
void placeCollectables(int maze[HEIGHT][WIDTH], int collectableCount) {
    for (int i = 0; i < collectableCount; i++) {
        int x, y;
        do {
            x = 1 + (rand() % ((WIDTH - 2) / 2)) * 2; // Random odd x-coordinate
            y = 1 + (rand() % ((HEIGHT - 2) / 2)) * 2; // Random odd y-coordinate
        } while (maze[y][x] != 0); // Ensure it's placed on a path

        maze[y][x] = 'C'; // Place collectable
    }
}

// Print the maze to console
void printMaze(int maze[HEIGHT][WIDTH], Point start, Point exit) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == start.x && y == start.y) {
                printf("P "); // Start point
            } else if (x == exit.x && y == exit.y) {
                printf("E "); // Exit point
            } else if (maze[y][x] == 0) {
                printf("  "); // Path
            } else if (maze[y][x] == 'C') {
                printf("C "); // Collectable
            } else {
                printf("##"); // Wall
            }
        }
        printf("\n");
    }
}

// Save the maze to a .ber file with a unique name
void saveMazeToFile(int maze[HEIGHT][WIDTH], Point start, Point exit) {
    char filename[20];
    int fileIndex = 1;

    // Create a unique filename (maze1.ber, maze2.ber, ...)
    do {
        snprintf(filename, sizeof(filename), "maze%d.ber", fileIndex);
        fileIndex++;
    } while (fopen(filename, "r") != NULL); // Check if file exists

    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == start.x && y == start.y) {
                fprintf(file, "P"); // Start point
            } else if (x == exit.x && y == exit.y) {
                fprintf(file, "E"); // Exit point
            } else if (maze[y][x] == 0) {
                fprintf(file, "0"); // Path
            } else if (maze[y][x] == 'C') {
                fprintf(file, "C"); // Collectable
            } else {
                fprintf(file, "1"); // Wall
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Maze saved to %s\n", filename);
}

int main() {
    srand(time(NULL));

    int maze[HEIGHT][WIDTH];
    Point start, exit;

    // Generate the maze using Prim's algorithm
    generateMaze(maze, &start, &exit);

    // Randomly determine the number of collectables (minimum 2)
    int collectableCount = 2 + rand() % ((WIDTH * HEIGHT) / 20); // Random based on maze size
    placeCollectables(maze, collectableCount);

    // Print the maze to console
    printMaze(maze, start, exit);

    // Save the maze to a file
    saveMazeToFile(maze, start, exit);

    return 0;
}
