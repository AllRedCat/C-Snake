#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <maph.h>

#define WIDTH 60
#define HEIGHT 26
#define NUM_THREDS 4

// ┌─┐
// │.│
// └─┘

// Global buffer
char screen_buffer[HEIGHT][WIDTH + 3];

// Function to render the frame

int main() {
  // Hide cursor
  printf("\e[?25l");

  // Main loop
  int quit = 0;
  while(!quit) {
    // Create the frame
    printf("┌");
    for (int i = 0; i < WIDTH; i++) {
      printf("─");
    }
    printf("┐\n");

    for (int j = 0; j < HEIGHT; j++) {
      printf("│");
      for (int l = 0; l < WIDTH; l++) {
        printf(" ");
      }
      printf("│\n");
    }

    printf("└");
    for (int k = 0; k < WIDTH; k++) {
      printf("─");
    }
    printf("┘\n");

    // Move cursor to top
    printf("\e[%iA", HEIGHT + 2);

    // Time to set around 30 FPS
    usleep(33333);
  }
  return 0;
}
