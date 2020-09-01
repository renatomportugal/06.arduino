#include "morse.h"

int falante = 3;

void setup()
{

  String str = "sos";

  // Length (with one extra character for the null terminator)
  int str_len = str.length() + 1;

  // Prepare the character array (the buffer)
  char char_array[str_len];

  // Copy it over
  str.toCharArray(char_array, str_len);

  for (int i = 0; i < str.length(); i++)
  {
    teclar(str[i]);
  }
}

void loop()
{
}