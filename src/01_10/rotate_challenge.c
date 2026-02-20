/**
 * @file rotate_challenge.c
 * @author MK
 * @brief
 * @version 0.1
 * @date 20-02-2026
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_1_R 3
#define MATRIX_1_C 8
#define MATRIX_2_R 5
#define MATRIX_2_C 5
#define MATRIX_3_R 6
#define MATRIX_3_C 4

// 3 matrices
char matrix_1[MATRIX_1_R][MATRIX_1_C];
char matrix_2[MATRIX_2_R][MATRIX_2_C];
char matrix_3[MATRIX_3_R][MATRIX_3_C];

// Rotated matrices
char matrix_1_rot[MATRIX_1_C][MATRIX_1_R];
char matrix_2_rot[MATRIX_2_C][MATRIX_2_R];
char matrix_3_rot[MATRIX_3_C][MATRIX_3_R];

void print_matrix(uint8_t rows, uint8_t cols, char matrix[rows][cols]);
void init_matrix(uint8_t rows, uint8_t cols, char matrix[rows][cols]);
void rotate_matrix(uint8_t rows, uint8_t cols, char matrix[rows][cols], char matrix_rot[cols][rows]);

int main(void)
{
  // initialize the RNG with seed as current time
  srand((unsigned)time(NULL));
  // initialize the matrix
  printf("MATRIX 1\n");
  init_matrix(MATRIX_1_R, MATRIX_1_C, matrix_1);
  rotate_matrix(MATRIX_1_R, MATRIX_1_C, matrix_1, matrix_1_rot);
  printf("MATRIX 2\n");
  init_matrix(MATRIX_2_R, MATRIX_2_C, matrix_2);
  rotate_matrix(MATRIX_2_R, MATRIX_2_C, matrix_2, matrix_2_rot);
  printf("MATRIX 3\n");
  init_matrix(MATRIX_3_R, MATRIX_3_C, matrix_3);
  rotate_matrix(MATRIX_3_R, MATRIX_3_C, matrix_3, matrix_3_rot);

  return 0;
}

void print_matrix(uint8_t rows, uint8_t cols, char matrix[rows][cols])
{
  for (uint8_t r = 0; r < rows; r++)
  {
    for (uint8_t c = 0; c < cols; c++)
    {
      printf("%c ", matrix[r][c]);
    }
    printf("\n");
  }
}

void init_matrix(uint8_t rows, uint8_t cols, char matrix[rows][cols])
{
  for (uint8_t r = 0; r < rows; r++)
  {
    for (uint8_t c = 0; c < cols; c++)
    {
      matrix[r][c] = 'a' + (rand() % 26);
    }
  }
  print_matrix(rows, cols, matrix);
}

void rotate_matrix(uint8_t rows, uint8_t cols, char matrix[rows][cols], char matrix_rot[cols][rows])
{
  for (uint8_t r = 0; r < rows; r++)
  {
    for (uint8_t c = 0; c < cols; c++)
    {
      matrix_rot[c][rows - 1 - r] = matrix[r][c];
    }
  }
  printf("Rotated matrix = \n");
  print_matrix(cols, rows, matrix_rot);
}
