# LAPORAN RESMI MODUL 5 SISOP

## ANGGOTA KELOMPOK
| Nama                           | NRP        |
| -------------------------------| ---------- |
| Shinta Alya Ramadani           | 5027241016 |
| Prabaswara Febrian Winandika   | 5027241069 |
| Muhammad Farrel Rafli Al Fasya | 5027241075 |

## Daftar Isi

- [Kelompok](#kelompok)
- [Daftar Isi](#daftar-isi)
- [Soal](#soal)
- [Petunjuk Soal](#petunjuk-soal)
  - [Source](#source)
  - [Headers](#headers)
  - [Makefile](#makefile)
  - [Video Demonstrasi](#video-demonstrasi)
- [Laporan](#laporan)

## Soal

Pada suatu hari, anda merasa sangat lelah dari segala macam praktikum yang sudah ada, sehingga anda berencana untuk tidur yang nyenyak di sebuah jam 3:34AM yang cerah. Tetapi, anda terbangun di dalam dunia berbeda yang bernama "Eorzea". Ada sesuatu yang mengganggu pikiran anda sehingga anda diharuskan membuat sebuah operating system bernama "EorzeOS" untuk mendampingi diri anda dalam dunia ini.

1. Sebagai seorang main character dari dunia ini, ternyata anda memiliki kekuatan yang bernama "The Echo", kekuatan ini memungkinkan anda untuk berbicara pada Operating System ini (mungkin sebenarnya bukan ini kekuatannya, tetapi ini cukup kuat juga), dengan tujuan agar semua hal yang anda katakan, bila bukan merupakan sebuah command yang valid, akan mengulang hal yang anda katakan.

   Ilustrasi:
   ```
   user> Hello!
   Hello!
   user> I have the Echo
   I have the Echo
   ```

2. gurt: yo

   Ilustrasi:
   ```
   user> yo
   gurt
   user> gurt
   yo
   ```

3. Seorang main character memerlukan sebuah nama yang semua orang bisa ingat dengan baik. Buatlah sebuah command yang memungkinkan pengguna untuk mengubah nama user pada shell yang digunakan:
   * `user <username>` = mengubah username menjadi `<username>`
   * `user` = mengubah username menjadi default `user`
   
   Ilustrasi:
   ```
   user> user Tia
   Username changed to Tia
   Tia> user
   Username changed to user
   user>
   ```

4. Tiga negara besar dari Eorzean Alliance butuh bantuan anda untuk ikut serta dalam "Grand Company" mereka sehingga anda bisa mengubah warna terminal ajaib anda sesuai warna utama dari company mereka:
   * `grandcompany maelstrom` = clear terminal, ubah semua teks berikutnya jadi merah
   * `grandcompany twinadder` = clear terminal, ubah semua teks berikutnya jadi kuning
   * `grandcompany immortalflames` = clear terminal, ubah semua teks berikutnya jadi biru
   * `grandcompany <selain atau kosong>` = tunjukkan error message
   * `clear` = clear terminal, ubah semua teks berikutnya kembali jadi awal (para Grand Company sedih kamu netral)

   Selain mengubah seluruh warna terminal, nama anda di dalam terminal akan diberikan tambahan nama judul Grand Company:
   * Maelstrom = `user@Storm`
   * Twin Adder = `user@Serpent`
   * Immortal Flames = `user@Flame`
   * `clear` = menghapus nama grand company

   Ilustrasi:
   ```
   gurt> grandcompany maelstrom
   -- terminal clear menjadi warna merah --
   gurt@Storm> clear
   -- terminal clear menjadi warna putih --
   ```

5. Sebagai pahlawan terkenal di antara ketiga negara besar Eorzean Alliance, salah satu supplier senjata terbesar di seluruh Eorzea bernama "Rowena's House of Splendors" tiba-tiba memerlukan bantuan anda untuk membuat sebuah sistem kalkulator sederhana melalui command karena pemimpin mereka tertidur setelah mengurus semua orang di dalam Eorzea:
   * `add <x> <y>` = x + y
   * `sub <x> <y>` = x - y
   * `mul <x> <y>` = x * y
   * `div <x> <y>` = x / y

   Ilustrasi:
   ```
   user> add 4 2
   6
   user> sub 4 2
   2
   user> mul 3 -2
   -6
   user> div -6 -2
   3
   ```

6. me: yogurt
   
   gurt:
   * `yo`
   * `ts unami gng </3`
   * `sygau`

   pilih secara *random*

   Ilustrasi:
   ```
   user> yogurt
   gurt> yo
   user> yogurt
   gurt> ts unami gng </3
   user> yogurt
   gurt> sygau
   ```

8. Perusahaan mesin "Garlond Ironworks" tiba-tiba lelah mengurus permintaan senjata perang untuk orang ke-148649813234 yang berusaha menghadapi final boss yang sama, sehingga mereka perlu bantuan kamu untuk melengkapi `Makefile` yang diberikan dengan command-command yang sesuai untuk compile seluruh operating system ini.

## Petunjuk Soal

### Source

* [kernel.asm](src/kernel.asm)
  * `_putInMemory`: penjelasan terdapat dalam modul
  * `_interrupt`: fungsi untuk interrupt
    * `number`: interrupt vector number
    * `AX`,`BX`,`CX`,`DX`: register untuk diisi
    * `AX` merupakan kombinasi dari `AH` dan `AL`, pola ini juga berlaku untuk `BX`,`CX`, dan `DX`
    * Untuk menggabungkan jenis register `H` dan `L` menjadi `X` bisa menggunakan salah satu metode berikut:
      ```c
      AX = AH << 8 | AL    // first method
      AX = AH * 256 + AL   // second method
      ```
   * `getBiosTick`: fungsi untuk mendapatkan tick dari BIOS
* [kernel.c](src/kernel.c)
  * Diisi penerapan fungsi `printString`, `readString`, dan `clearScreen` dengan bantuan `kernel.asm`
    * untuk `printString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk _teletype output_. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (_null-terminated_) ke layar.
    * untuk `readString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk _keyboard input_. Fungsi ini akan membaca karakter ASCII (_non-control_) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan.
    * untuk `clearScreen`: Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video.
* [shell.c](src/shell.c)
  * Diisi penerapan shell yang menggunakan fungsi kernel untuk parsing keseluruhan command yang diinput

### Headers

* [std_type.h](include/std_type.h)
  * `byte`: unsigned char data type, untuk angka 0-255 (`0x00`-`0xFF`)
  * `bool`: untuk boolean (true/false), karena boolean tidak built-in
* [std_lib.h](include/std_lib.h)
  * `div`: division
  * `mod`: modulo
  * Pembagian dan modulo tidak ada dalam assembly, sehingga harus dilengkapi dengan operator yang tersedia (`+`,`-`,`*`,`<<`,`>>`)
  * `strcmp`: membandingkan dua string
  * `strcpy`: copy string
  * `clear`: fill memory dengan `0`
  * `atoi`: alphanumeric to integer (string menjadi angka)
  * `itoa`: integer to alphanumeric (angka menjadi string)
* [kernel.h](include/kernel.h)
  * Deklarasi header untuk fungsi-fungsi dalam `kernel.c`
* [shell.h](include/shell.h)
  * Deklarasi header untuk fungsi-fungsi dalam `shell.c`

### Makefile

* [makefile](./makefile)
   * `prepare` : membuat disk image baru `floppy.img` pada direktori `bin/` dengan ukuran 1.44 MB.
   * `bootloader` : mengkompilasi `bootloader.asm` menjadi `bootloader.bin` pada direktori `bin/`.
   * `stdlib` : mengkompilasi `std_lib.c` menjadi `std_lib.o` pada direktori `bin/`.
   * `shell`: mengkompilasi `shell.c` menjadi `shell.o` pada direktori `bin/`.
   * `kernel` : mengkompilasi `kernel.c` menjadi `kernel.o` pada direktori `bin/` dan mengkompilasi `kernel.asm` menjadi `kernel_asm.o` pada direktori `bin/`.
   * `link` : menggabungkan `bootloader.bin`, `kernel.o`, `kernel_asm.o`, dan `std_lib.o` menjadi `floppy.img`.
   * `build` : menjalankan perintah `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link`.

### Video Demonstrasi

[Akses Video dalam Assets](./assets/demo.mp4)

https://github.com/user-attachments/assets/1cfa66b1-b2f5-4e3e-a4b2-ec8b012f6fbb


## Laporan

### 🧠 Deskripsi

Modul ini berfokus pada pembuatan sistem operasi sederhana dari awal menggunakan bahasa Assembly dan bahasa C. OS yang dibangun bernama EorzeOS, dijalankan menggunakan emulator Bochs, dan memiliki fitur seperti tampilan shell interaktif, pengolahan perintah (command execution), dan manajemen file dasar.

### 📂 Struktur Folder
```
.
├── bin/               # Berisi binary hasil kompilasi
├── build.sh           # Script otomatisasi build
├── bochsrc            # File konfigurasi Bochs
├── kernel/            # File kernel utama dan interrupt
│   └── kernel.c
├── lib/               # Library fungsi-fungsi utilitas
│   ├── stdio.c
│   ├── stdlib.c
│   └── string.c
├── program/           # Berisi shell dan command lain
│   └── shell.c
├── sector-loader/     # Bootloader ASM
│   └── bootloader.asm
└── docs/              # Dokumentasi teknis tambahan
```
### ⚙️ Cara Build dan Menjalankan
🔨 Build

Untuk membangun sistem operasi :
```
./build.sh
```
Script ini akan :
- Compile bootloader dengan nasm
- Compile kernel dan program CLI
- Menggabungkan semua ke dalam satu disk image (system.img)

🚀 Menjalankan di Bochs
```
bochs -f bochsrc.txt -q
```
### 📝 Pembagian Tugas

| Nama       | Tugas dan Kontribusi                                                                                                                         |
| ---------- | -------------------------------------------------------------------------------------------------------------------------------------------- |
| **Shinta** | Mencoba mengerjakan modul namun mengalami kendala teknis; akhirnya fokus membantu pembuatan laporan praktik (lapres).                        |
| **Ryan**   | Berhasil mengimplementasikan sebagian besar fitur hingga nomor 5 dalam soal; menjadi dasar awal pengembangan sistem.                         |
| **Farrel** | Melengkapi seluruh fitur sesuai soal, memastikan semua berjalan sempurna, dan melakukan debugging akhir dalam demo praktikum.                |

### 📚 Source Code Lengkap

#### 🔹 std_lib.c
```
#include "std_lib.h"

int div(int a, int b)
{
  int dividend = a;
  int divisor = b;
  int result = 0;
  int polarity = 1;

  if (divisor == 0) {
    return 0;
  }

  if (dividend < 0) {
    polarity = -polarity;
    dividend = -dividend;
  }
  if (divisor < 0) {
    polarity = -polarity;
    divisor = -divisor;
  }

  while (dividend >= divisor) {
    dividend -= divisor;
    result++;
  }

  return result * polarity;
}

int mod(int a, int b)
{
  int dividend = a;
  int divisor = b;

  if (divisor == 0) {
    return 0;
  }
  
  if (divisor < 0) {
    divisor = -divisor;
  }
  if (dividend < 0) {
    while (dividend <= -divisor) {
      dividend += divisor;
    }
  } else {
    while (dividend >= divisor) {
      dividend -= divisor;
    }
  }
  
  return dividend;
}

bool strcmp(char *str1, char *str2)
{
  char *s1 = str1;
  char *s2 = str2;

  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }

  return (*s1 == *s2);
}

void strcpy(char *dst, char *src)
{
  char* destination = dst;
  char* source = src;
  int i = 0;

  for (i = 0; source[i] != '\0'; i++) {
    destination[i] = source[i];
  }
  destination[i] = '\0';
}

void clear(byte *buf, unsigned int size)
{
  byte *buffer = buf;
  byte *end_ptr = buffer + size;
  
  while (buffer < end_ptr) {
    *buffer = 0;
    buffer++;
  }
}

void atoi(char *str, int *num)
{
  char* current_char = str;
  int value = 0;
  int polarity = 1;

  while (*current_char == ' ') {
    current_char++;
  }

  if (*current_char == '-') {
    polarity = -1;
    current_char++;
  } else if (*current_char == '+') {
    current_char++;
  }

  while (*current_char >= '0' && *current_char <= '9') {
    value = (value * 10) + (*current_char - '0');
    current_char++;
  }

  *num = value * polarity;
}

void itoa(int num, char *str)
{
  char* buffer_ptr = str;
  int i = 0;
  int j = 0;
  bool is_negative = false;

  if (num == 0) {
    buffer_ptr[i++] = '0';
    buffer_ptr[i] = '\0';
    return;
  }

  if (num < 0) {
    is_negative = true;
    num = -num;
  }

  while (num > 0) {
    buffer_ptr[i++] = mod(num, 10) + '0';
    num = div(num, 10);
  }

  if (is_negative) {
    buffer_ptr[i++] = '-';
  }

  buffer_ptr[i] = '\0';

  // Reverse the string
  for (j = 0; j < i / 2; j++) {
    char temp = buffer_ptr[j];
    buffer_ptr[j] = buffer_ptr[i - 1 - j];
    buffer_ptr[i - 1 - j] = temp;
  }
}
```
#### 🔹 kernel.c 
```
#include "shell.h"
#include "kernel.h"

int main() {
    clearScreen(0x07); // Default white background, grey text
    shell();
}

void printString(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        interrupt(0x10, 0x0E00 | str[i], 0, 0, 0);
        i++;
    }
}

void readString(char *buf) {
    int i = 0;
    char ch;
    while (1) {
        ch = interrupt(0x16, 0, 0, 0, 0) & 0xFF;
        if (ch == 0x0D) { // Enter key
            buf[i] = '\0';
            printString("\r\n");
            return;
        } else if (ch == 0x08) { // Backspace
            if (i > 0) {
                i--;
                printString("\b \b");
            }
        } else {
            buf[i] = ch;
            interrupt(0x10, 0x0E00 | ch, 0, 0, 0);
            i++;
        }
    }
}

void clearScreen(int color) {
    int i;
    for (i = 0; i < 80 * 25; i++) { // Loop through all 2000 character positions
        putInMemory(0xB000, 0x8000 + (i * 2), 0x00); // Character (space)
        putInMemory(0xB000, 0x8000 + (i * 2) + 1, color); // Attribute (color)
    }
    // Set cursor to top-left
    interrupt(0x10, 0x0200, 0, 0, 0);
}
```
#### 🔹 shell.c 
```
#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

char user[64];
char host[64];
int currentTextColor; // Renamed for consistency with general OS terms, but functions still use it as 'color'

void executeCommand(char *cmd, char arg[2][64], char *original_buf);
void prompt(char* name);
void randomAnswer();


void shell() {
    char buf[128];
    char cmd[64];
    char arg[2][64];

    strcpy(user, "user"); // Default user
    host[0] = '\0';       // No host initially
    currentTextColor = 0x07; // Default white (grey text on black background)

    printString("Welcome to EorzeOS!\r\n");

    while (true) {
        prompt(user);
        readString(buf);
        parseCommand(buf, cmd, arg);
        executeCommand(cmd, arg, buf);
    }
}

void prompt(char* name) {
    printString(name);
    if (host[0] != '\0') {
        printString(host);
    }
    printString("> "); // Changed prompt symbol
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
    int i = 0, j = 0, k = 0;
    int arg_idx = 0;

    clear(cmd, 64);
    clear(arg[0], 64);
    clear(arg[1], 64);

    // Skip leading whitespace
    while (buf[i] == ' ' || buf[i] == '\r' || buf[i] == '\n') {
        i++;
    }

    // Extract command
    while (buf[i] != ' ' && buf[i] != '\r' && buf[i] != '\n' && buf[i] != '\0' && j < 63) {
        cmd[j++] = buf[i++];
    }
    cmd[j] = '\0';

    // Extract arguments
    for (arg_idx = 0; arg_idx < 2; arg_idx++) {
        while (buf[i] == ' ') { // Skip spaces before argument
            i++;
        }
        k = 0; // Reset arg char index
        while (buf[i] != ' ' && buf[i] != '\r' && buf[i] != '\n' && buf[i] != '\0' && k < 63) {
            arg[arg_idx][k++] = buf[i++];
        }
        arg[arg_idx][k] = '\0';
    }
}

void randomAnswer() {
    int random_val = mod(getBiosTick(), 3); // Use mod from std_lib.h

    if (random_val == 0) {
        printString("yo\r\n");
    } else if (random_val == 1) {
        printString("ts unami gng </3\r\n");
    } else {
        printString("sygau\r\n");
    }
}

void executeCommand(char *cmd, char arg[2][64], char *original_buf) {
    int num1, num2, result;
    char result_str[32]; // Buffer for integer to string conversion

    if (strcmp(cmd, "yo")) {
        printString("gurt\r\n");
    } else if (strcmp(cmd, "gurt")) {
        printString("yo\r\n");
    } else if (strcmp(cmd, "user")) {
        if (arg[0][0] == '\0') { // If no argument, set to default "user"
            strcpy(user, "user");
            printString("Username changed to user\r\n");
        } else { // Set to provided username
            strcpy(user, arg[0]);
            printString("Username changed to ");
            printString(user);
            printString("\r\n");
        }
    } else if (strcmp(cmd, "grandcompany")) {
        if (strcmp(arg[0], "maelstrom")) {
            currentTextColor = 0x0C; // Merah
            clearScreen(currentTextColor);
            strcpy(host, "@Storm");
        } else if (strcmp(arg[0], "twinadder")) {
            currentTextColor = 0x0E; // Kuning
            clearScreen(currentTextColor);
            strcpy(host, "@Serpent");
        } else if (strcmp(arg[0], "immortalflames")) {
            currentTextColor = 0x01; // Biru
            clearScreen(currentTextColor);
            strcpy(host, "@Flame");
        } else {
            printString("Unknown Grand Company. Options: maelstrom, twinadder, immortalflames.\r\n");
        }
    } else if (strcmp(cmd, "clear")) {
        host[0] = '\0'; // Remove Grand Company name
        currentTextColor = 0x07; // Default white
        clearScreen(currentTextColor);
    } else if (strcmp(cmd, "add")) {
        atoi(arg[0], &num1);
        atoi(arg[1], &num2);
        result = num1 + num2;
        itoa(result, result_str);
        printString(result_str);
        printString("\r\n");
    } else if (strcmp(cmd, "sub")) {
        atoi(arg[0], &num1);
        atoi(arg[1], &num2);
        result = num1 - num2;
        itoa(result, result_str);
        printString(result_str);
        printString("\r\n");
    } else if (strcmp(cmd, "mul")) {
        atoi(arg[0], &num1);
        atoi(arg[1], &num2);
        result = num1 * num2;
        itoa(result, result_str);
        printString(result_str);
        printString("\r\n");
    } else if (strcmp(cmd, "div")) {
        atoi(arg[0], &num1);
        atoi(arg[1], &num2);
        if (num2 == 0) {
            printString("Error: Division by zero is not allowed.\r\n");
        } else {
            result = div(num1, num2); // Use div from std_lib.h
            itoa(result, result_str);
            printString(result_str);
            printString("\r\n");
        }
    } else if (strcmp(cmd, "yogurt")) {
        randomAnswer();
    } else if (cmd[0] != '\0') { // Echo command if not recognized and not empty
        printString(original_buf); // Print the whole original buffer
        printString("\r\n");
    }
}
```
#### 🔹 makefile
```
l to image..."
	dd if=$(BDIR)/kernel.bin of=$(IMG) bs=512 seek=1 conv=notrunc >/dev/null 2>&1
	@echo "==> Build finished: $(IMG)"


$(BDIR)/kernel.bin: $(OBJS)
	@echo "==> Linking object files to create kernel.bin..."
	$(LD) -o $@ -d $^

$(BDIR)/bootloader.bin: $(SDIR)/bootloader.asm
	@echo "==> Assembling bootloader..."
	$(NASK) -f bin $< -o $@

$(BDIR)/kernel-asm.o: $(SDIR)/kernel.asm
	@echo "==> Assembling kernel ASM ($<)..."
	$(NASK) -f as86 $< -o $@

# Rule untuk mengkompilasi file .c menjadi .o
$(BDIR)/%.o: $(SDIR)/%.c
	@echo "==> Compiling C source ($<)..."
	$(BCC) $(CFLAGS) -c $< -o $@
```
