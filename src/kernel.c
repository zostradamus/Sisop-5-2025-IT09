#include "shell.h"
#include "kernel.h"

int main() {
  clearScreen();
  shell();
}

void printString(char *str) {
    while (*str != '\0') {
        interrupt(0x10, 0x0E00 + *str, 0, 0, 0);        
        str++;
    }
}

void readString(char *buf) {
  int i = 0;
  char c;
  char out[2];

  while (1) {
    c = interrupt(0x16, 0x0000, 0, 0, 0); // BIOS keyboard input

    if (c == 0x0D) { // Enter
      buf[i] = '\0';
      printString("\r\n");
      return;
    } else if (c == 0x08) { // Backspace
      if (i > 0) {
        i--;
        printString("\b \b");
      }
    } else {
      buf[i++] = c;
      out[0] = c;
      out[1] = '\0';
      printString(out);
    }
  }
}

void clearScreen()
{
  int i;
  for (i = 0; i < 80 * 25 * 2; i += 2) {
    putInMemory(0xB800, i, ' ');
    putInMemory(0xB800, i + 1, 0x07); 
  }
  
  interrupt(0x10, 0x0200, 0, 0, 0);
}