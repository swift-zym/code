// Brainfuck complier version 0.0 beta
// develop by swift
// last update @ 2020.1.26

#include <bits/stdc++.h>
#ifndef MAX_CODE_LENGTH
#define MAX_CODE_LENGTH 1000000
#endif
#ifndef VM_MAX_MEMORY
#define VM_MAX_MEMORY 1000000
#endif
#ifndef START_MEMORY
#define START_MEMORY 100000
#endif
#ifndef STACK_SIZE
#define STACK_SIZE 100000
#endif
using namespace std;
int code_length, i;
char code[MAX_CODE_LENGTH];
struct BrainFuckVM {
  char memory[VM_MAX_MEMORY];
  char stack[STACK_SIZE];
  int ptr, stack_length;
  void check_memory() {
    if (ptr < 0 || ptr >= VM_MAX_MEMORY) {
      printf("Runtime Error: segement fault,ptr:%d", ptr);
      exit(1);
    }
  }
  void init() {
    ptr = START_MEMORY;
    stack_length = 0;
    memset(memory, 0, sizeof(memory));
  }
  void run(char command) {
    switch (command) {
      case '>':
        ptr++;
        check_memory();
        break;
      case '<':
        ptr--;
        check_memory();
        break;
      case '+':
        memory[ptr]++;
        break;
      case '-':
        memory[ptr]--;
        break;
      case '.':
        putchar(memory[ptr]);
        break;
      case ',':
        memory[ptr] = getchar();
        break;
      case '[':
        if (memory[ptr]) {
          stack[stack_length++] = i;
        } else {
          int j, k;
          for (k = i, j = 0; k < code_length; k++) {
            code[k] == '[' && j++;
            code[k] == ']' && j--;
            if (j == 0) break;
          }
          if (j == 0)
            i = k;
          else {
            printf("Runtime Error");
            exit(1);
            exit(1);
          }
        }
        break;
      case ']':
        i = stack[stack_length-- - 1] - 1;
        break;
      default:
        printf("Runtime Error: VM accept unexpected command \"%c\"", command);
        exit(1);
        break;
    }
  }
} VM;
int main(int argc, char* argv[]) {
  VM.init();
  if (argc > 2) {
    printf("Complie Error:too much parameters expect:0/1 read:%d\n", argc - 1);
    return 1;
  }
  if (argc == 2) {
    FILE* input;
    input = fopen(argv[1], "rw");
    char ch;
    while (fscanf(input, "%c", &ch) != EOF) {
      if (ch != '	' && ch != ' ' && ch != '\r' && ch != '\n' &&
          ch != '>' && ch != '<' && ch != '+' && ch != '-' && ch != '.' &&
          ch != ',' && ch != ']' && ch != '[') {
        printf("Complie Error:read unexpected character: \"%c\"\n", ch);
        return 1;
      }
      if (ch == ' ' || ch == '	' || ch == '\r' || ch == '\n') continue;
      code[code_length++] = ch;
    }
  } else {
    char ch;
    while (scanf("%c", &ch) != EOF) {
      if (ch != '	' && ch != ' ' && ch != '\r' && ch != '\n' &&
          ch != '>' && ch != '<' && ch != '+' && ch != '-' && ch != '.' &&
          ch != ',' && ch != ']' && ch != '[') {
        printf("Complie Error:read unexpected character: \"%c\"\n", ch);
        return 1;
      }
      if (ch == ' ' || ch == '	' || ch == '\r' || ch == '\n') continue;
      code[code_length++] = ch;
    }
  }
  for (i = 0; i < code_length; i++) {
    VM.run(code[i]);
  }
  return 0;
}