#include "../include/input.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

InputBufferType* createInputBuffer() {
  InputBufferType* input = malloc(sizeof(InputBufferType));
  if (input == NULL) { panic("Error creating input buffer"); }

  input->buffer = NULL;
  input->buffer_length = 0;
  input->input_length = 0;
  return input;
}

void freeInputBuffer(InputBufferType* input) {
  free(input->buffer);
  free(input);
}

void readInput(InputBufferType* input, FILE* file) {
  ssize_t bytes_read = getline(&(input->buffer), &(input->buffer_length), file);

  if (bytes_read <= 0) { panic("Error reading input\n"); }

  // Ignore trailing newline
  input->input_length = bytes_read - 1;
  input->buffer[bytes_read - 1] = 0;
}

void printPrompt() { printf(PROMPT); }
