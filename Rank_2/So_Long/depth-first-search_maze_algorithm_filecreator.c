#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIDTH 29  // Width of the maze (must be odd)
#define HEIGHT 15 // Height of the maze (must be odd)

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *data;
    int top;
} Stack;

void initStack(Stack *stack, int size) {
    stack->data = (Point *)malloc(size * sizeof(Point));
    stack->top = -1;
}

void push(Stack *stack, Point p) {
    stack->data[++stack->top] = p;
}

Point pop(Stack *stack) {
    return stack->data[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Directions for moving in the maze (down, up, right, left)
int directions[4][2] = {
    {1, 0},  // down
    {-1, 0}, // up
    {0, 1},  // right
    {0, -1}  // left
};

// Check if a point is within bounds
int inBounds(int x, int y) {
    return (x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1);
}

// Check if a point has been visited (wall array)
int isVisited(int *visited, int x, int y) {
    return visited[y * WIDTH + x];
}

// Mark a point as visited
void markVisited(int *visited, int x, int y) {
    visited[y * WIDTH + x] = 1;
}

// Shuffle the directions for random movement
void shuffleDirections(int *directions) {
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp[2] = {directions[i * 2], directions[i * 2 + 1]};
        directions[i * 2] = directions[j * 2];
        directions[i * 2 + 1] = directions[j * 2 + 1];
        directions[j * 2] = temp[0];
        directions[j * 2 + 1] = temp[1];
    }
}

// Generate the maze using DFS
void generateMaze(int maze[HEIGHT][WIDTH], Point *start, Point *exit) {
    int *visited = (int *)calloc(WIDTH * HEIGHT, sizeof(int));
    Stack stack;
    initStack(&stack, WIDTH * HEIGHT);

    // Start from a random position
    int startX = 1 + (rand() % ((WIDTH - 2) / 2)) * 2;
    int startY = 1 + (rand() % ((HEIGHT - 2) / 2)) * 2;
    *start = (Point){startX, startY};
    push(&stack, *start);
    markVisited(visited, startX, startY);
    maze[startY][startX] = 0; // Open cell

    while (!isEmpty(&stack)) {
        Point current = pop(&stack);
        int unvisitedCount = 0;

        // Check unvisited neighbors
        Point neighbors[4];
        for (int i = 0; i < 4; i++) {
            int nx = current.x + directions[i][0] * 2;
            int ny = current.y + directions[i][1] * 2;
            if (inBounds(nx, ny) && !isVisited(visited, nx, ny)) {
                neighbors[unvisitedCount++] = (Point){nx, ny};
            }
        }

        // If there are unvisited neighbors, choose one and carve a path
        if (unvisitedCount > 0) {
            push(&stack, current); // Push current cell back to stack
            shuffleDirections((int *)directions); // Randomize directions

            Point next = neighbors[rand() % unvisitedCount];
            maze[current.y + (next.y - current.y) / 2][current.x + (next.x - current.x) / 2] = 0; // Remove wall
            maze[next.y][next.x] = 0; // Open next cell
            markVisited(visited, next.x, next.y); // Mark next cell as visited
            push(&stack, next); // Push next cell to stack
        }
    }

    // Set exit point
    *exit = (Point){WIDTH - 2, HEIGHT - 2}; // Bottom-right corner
    maze[exit->y][exit->x] = 0; // Open exit cell

    free(visited);
    free(stack.data);
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
    
    // Initialize maze with walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x] = 1; // Wall
        }
    }

    Point start, exit;
    generateMaze(maze, &start, &exit);

    // Randomly determine the number of collectables (minimum 2)
    int collectableCount = 2 + rand() % ((WIDTH * HEIGHT / 4) - 2);
    placeCollectables(maze, collectableCount);

    // Print the maze to the console
    printMaze(maze, start, exit);

    // Save the maze to a .ber file with a unique name
    saveMazeToFile(maze, start, exit);

    return 0;
}
