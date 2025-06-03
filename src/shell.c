#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

extern int currentColor;
extern char companyTitle[16];

int strlen(char *str);  // Prototipe fungsi

void shell() {
  char username[64];
  char suffix[4]; // Buat array suffix secara manual

  suffix[0] = '>';
  suffix[1] = ' ';
  suffix[2] = '\0';

  strcpy(username, "user"); // default username

  printString("Welcome to IT09 OS\r\n");

  while (1) {
  char input[100];
  char cmd[64];
  char arg[2][64];
  char prompt[128];
  int i = 0, len = 0;

  // Bangun prompt: username + companyTitle + "> "
  strcpy(prompt, username);
  len = strlen(prompt);

  i = 0;
  while (companyTitle[i] != '\0') {
    prompt[len++] = companyTitle[i++];
  }

  i = 0;
  while (suffix[i] != '\0') {
    prompt[len++] = suffix[i++];
  }

  prompt[len] = '\0';

  setColor(currentColor);         // Set warna sebelum prompt
  printString(prompt);            // Tampilkan prompt
  readString(input);             // Ambil input user
  parseCommand(input, cmd, arg); // Parsing input jadi cmd & arg

  if (strcmp(cmd, "yo")) {
    printString("gurt\r\n");
  } else if (strcmp(cmd, "gurt")) {
    printString("yo\r\n");
  } else if (strcmp(cmd, "user")) {
    if (arg[0][0] != '\0') {
      strcpy(username, arg[0]);
      printString("Username changed to ");
      printString(username);
      printString("\r\n");
    } else {
      strcpy(username, "user");
      printString("Username changed to user\r\n");
    }
  } else if (strcmp(cmd, "grandcompany")) {
    if (strcmp(arg[0], "maelstrom")) {
      currentColor = 0x04;
      strcpy(companyTitle, "@Storm");
    } else if (strcmp(arg[0], "twinadder")) {
      currentColor = 0x0E;
      strcpy(companyTitle, "@Serpent");
    } else if (strcmp(arg[0], "immortalflames")) {
      currentColor = 0x01;
      strcpy(companyTitle, "@Flame");
    } else {
      printString("Grand Company name required\r\n");
      continue;
    }
    clearScreen();
    setColor(currentColor);
    continue; // lompat ke iterasi berikutnya supaya prompt baru ditampilkan dengan warna baru
  } else if (strcmp(cmd, "clear")) {
    currentColor = 0x07;
    companyTitle[0] = '\0';
    clearScreen();
    setColor(currentColor);
    continue;
  } else if (strcmp(cmd, "add") || strcmp(cmd, "sub") || strcmp(cmd, "mul") || strcmp(cmd, "div")) {
    int a, b, result;
    char resStr[64];

    atoi(arg[0], &a);
    atoi(arg[1], &b);

    if (strcmp(cmd, "add")) result = a + b;
    else if (strcmp(cmd, "sub")) result = a - b;
    else if (strcmp(cmd, "mul")) result = a * b;
    else {
      if (b == 0) {
        printString("Error: division by zero\r\n");
        continue;
      }
      result = div(a, b);
    }
    itoa(result, resStr);
    printString(resStr);
    printString("\r\n");
  }  else {
    printString(cmd);
    printString("\r\n");
  }
  }
}



void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  int i = 0, j = 0;
  int word = 0; // 0 = cmd, 1 = arg1, 2 = arg2

  for (i = 0; i < 64; i++) {
    cmd[i] = '\0';
    arg[0][i] = '\0';
    arg[1][i] = '\0';
  }

  i = 0; j = 0;
  while (buf[i] != '\0') {
    if (buf[i] == ' ') {
      if (word < 2) word++;
      j = 0;
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

int strlen(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

