#include "std_lib.h"

int div(int a, int b)
{
  //TODO: Implementasi pembagian
  //NOTE: HARUS BISA ANGKA NEGATIF
}

int mod(int a, int b)
{
  //TODO: Implementasi modulus
}

bool strcmp(char *str1, char *str2)
{
  while (*str1 && *str2) {
    if (*str1 != *str2) return 0;
    str1++;
    str2++;
  }
  return *str1 == *str2;

}

void strcpy(char *dst, char *src)
{
  //TODO: Implementasi penyalinan string
}

void clear(byte *buf, unsigned int size)
{
  //TODO: Implementasi pembersihan buffer
}

void atoi(char *str, int *num)
{
  //TODO: Implementasi konversi string ke integer
  //NOTE: HARUS BISA ANGKA NEGATIF
}

void itoa(int num, char *str)
{
  //TODO: Implementasi konversi integer ke string
  //NOTE: HARUS BISA ANGKA NEGATIF
}