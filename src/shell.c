#include "shell.h"
#include "kernel.h"
#include "std_lib.h"


void shell() {
  printString("ryan os\r\n");
  while (1) {
    char input[100];
    char cmd[64];
    char arg[2][64];

    printString("user> ");
    readString(input);
    parseCommand(input, cmd, arg);

    if (strcmp(cmd, "yo")) {
      printString("gurt\r\n");
    } else if (strcmp(cmd, "gurt")) {
      printString("yo\r\n");
    } else {
      printString(cmd);
      printString("\r\n");
    }
  }
}

// Memisahkan input menjadi cmd (perintah utama) dan argumen (maks 2)
void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  int i = 0, j = 0, k = 0;
  int word = 0; // 0 = cmd, 1 = arg1, 2 = arg2

  // Kosongkan cmd dan arg dulu
  for (i = 0; i < 64; i++) {
    cmd[i] = '\0';
    arg[0][i] = '\0';
    arg[1][i] = '\0';
  }

  i = 0;
  while (buf[i] != '\0') {
    if (buf[i] == ' ') {
      if (word < 2) word++;
      j = 0; // reset index karakter arg
      i++;
      continue;
    }

    if (word == 0) {
      cmd[j++] = buf[i];
      cmd[j] = '\0';
    } else if (word == 1) {
      arg[0][j++] = buf[i];
      arg[0][j] = '\0';
    } else if (word == 2) {
      arg[1][j++] = buf[i];
      arg[1][j] = '\0';
    }

    i++;
  }
}

// Tambahkan fungsi bila perlu