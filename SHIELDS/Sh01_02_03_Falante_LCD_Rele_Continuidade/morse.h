/*
 * Como usar:
 */
 
// Pino do falante
#define falante  3

// Frequencia do morse
#define frequencia 785

// Rápido
int dit = 50;
int dah = 250;
int intervalodit = 100;
int intervalodah = 300;
int intervalopalavra = 200;

int playDit(){
    tone(falante,frequencia, dit);
    delay(intervalodit);
}
int playDah(){
    tone(falante,frequencia, dah);
    delay(intervalodah);
}

char teclar(char codigo){
  switch (codigo) {
  case 'a':
    playDit();
    playDah();
    delay(intervalopalavra);
    break;
  case 'b':
    playDah();
    playDit();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case 'c':
    playDah();
    playDit();
    playDah();
    playDit();
    delay(intervalopalavra);
    break;
  case 'd':
    playDah();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case 'e':
    playDit();
    delay(intervalopalavra);
    break;
  case 'f':
    playDit();
    playDit();
    playDah();
    playDit();
    delay(intervalopalavra);
    break;
  case 'g':
    playDah();
    playDah();
    playDit();
    delay(intervalopalavra);
    break;
  case 'h':
    playDit();
    playDit();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case 'i':
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case 'j':
    playDit();
    playDah();
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case 'k':
    playDah();
    playDit();
    playDah();
    delay(intervalopalavra);
    break;
  case 'l':
    playDit();
    playDah();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case 'm':
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case 'n':
    playDah();
    playDit();
    delay(intervalopalavra);
    break;
  case 'o':
    playDah();
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case 'p':
    playDit();
    playDah();
    playDah();
    playDit();
    delay(intervalopalavra);
    break;
  case 'q':
    playDah();
    playDah();
    playDit();
    playDah();
    delay(intervalopalavra);
    break;
  case 'r':
    playDit();
    playDah();
    playDit();
    delay(intervalopalavra);
    break;
  case 's':
    playDit();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case 't':
    playDah();
    delay(intervalopalavra);
    break;
  case 'u':
    playDit();
    playDit();
    playDah();
    delay(intervalopalavra);
    break;
  case 'v':
    playDit();
    playDit();
    playDit();
    playDah();
    delay(intervalopalavra);
    break;
  case 'w':
    playDit();
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case 'x':
    playDah();
    playDit();
    playDit();
    playDah();
    delay(intervalopalavra);
    break;
  case 'y':
    playDah();
    playDit();
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case 'z':
    playDah();
    playDah();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case '0':
    playDah();
    playDah();
    playDah();
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case '1':
    playDit();
    playDah();
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case '2':
    playDit();
    playDit();
    playDah();
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case '3':
    playDit();
    playDit();
    playDit();
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case '4':
    playDit();
    playDit();
    playDit();
    playDit();
    playDah();
    delay(intervalopalavra);
    break;
  case '5':
    playDit();
    playDit();
    playDit();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case '6':
    playDah();
    playDit();
    playDit();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case '7':
    playDah();
    playDah();
    playDit();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case '8':
    playDah();
    playDah();
    playDah();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;
  case '9':
    playDah();
    playDah();
    playDah();
    playDah();
    playDit();
    delay(intervalopalavra);
    break;
  case '.':
    playDit();
    playDah();
    playDit();
    playDah();
    playDit();
    playDah();
    delay(intervalopalavra);
    break;
  case ',':
    playDah();
    playDah();
    playDit();
    playDit();
    playDah();
    playDah();
    delay(intervalopalavra);
    break;
  case '?':
    playDit();
    playDit();
    playDah();
    playDah();
    playDit();
    playDit();
    delay(intervalopalavra);
    break;

  default:
    // comando(s)
    break;
    
  }
}

String teclarFrase(String frase){
  String str = frase;

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
