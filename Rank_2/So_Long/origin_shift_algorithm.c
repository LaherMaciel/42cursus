#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 10

typedef struct {
    int x;
    int y;
} Point;

void printMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH], Point start, Point exit);
void originShift(char maze[MAZE_HEIGHT][MAZE_WIDTH]);
void loadMaze(const char *filename, char maze[MAZE_HEIGHT][MAZE_WIDTH]);

// ANSI color codes
#define COLOR_RESET "\033[0m"
#define COLOR_BLUE "\033[34m"    // Player
#define COLOR_YELLOW "\033[33m"  // Exit
#define COLOR_RED "\033[31m"     // Collectable
#define COLOR_GREEN "\033[32m"   // Root

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <maze_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char maze[MAZE_HEIGHT][MAZE_WIDTH];
    loadMaze(argv[1], maze); // Load maze from the provided file

    Point start = {0, 0};
    Point exit = {0, 0};

    // Find start and exit points
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j] == 'P') {
                start.x = j;
                start.y = i;
            } else if (maze[i][j] == 'E') {
                exit.x = j;
                exit.y = i;
            }
        }
    }

    while (1) {
        printf("\033[H\033[J"); // Clear the screen
        printMaze(maze, start, exit);  // Print the maze with start and exit points
        sleep(15); // Wait for 15 seconds
        originShift(maze); // Apply origin shift algorithm (abstract)
        printf(COLOR_GREEN "Origin Shifted Point\n" COLOR_RESET);
    }

    return 0;
}

void loadMaze(const char *filename, char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            fscanf(file, " %c", &maze[i][j]);
        }
    }
    fclose(file);
}

void printMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH], Point start, Point exit) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (x == start.x && y == start.y) {
                printf(COLOR_BLUE "P " COLOR_RESET); // Print Player in blue
            } else if (x == exit.x && y == exit.y) {
                printf(COLOR_YELLOW "E " COLOR_RESET); // Print Exit in yellow
            } else if (maze[y][x] == '0') {
                printf("  "); // Print floor (space)
            } else if (maze[y][x] == 'C') {
                printf(COLOR_RED "C " COLOR_RESET); // Print Collectable in red
            } else if (maze[y][x] == '1') {
                printf("##"); // Print wall
            }
        }
        printf("\n"); // Move to the next line after each row
    }
}

void originShift(char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    // Example of simple origin shift logic
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j] == 'C') {
                maze[i][j] = '0'; // Collectables turn into floor
            } else if (maze[i][j] == '0') {
                maze[i][j] = 'C'; // Floors turn into collectables
            }
        }
    }
}
