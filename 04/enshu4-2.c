#include <stdio.h>
#define CODEEND 9999999

int codekey[26] = { 15, 7, 16, 20, 12, 4, 0, 24, 11, 13, 5, 3, 23, 8, 17, 2, 21, 18, 9, 6, 22, 1, 25, 14, 10, 19 };

void encode(char*, int*);

void decode(int*, char*);

int main() {
  char code_word[20] = "opensesame";
  char decoding[20];
  int encoding[20];
  int i;

  printf("Code word: %s\n", code_word);

  encode(code_word, encoding);
  printf("Encoding: ");
  for (i = 0; encoding[i] != CODEEND; i++) {
    printf("%d ", encoding[i]);
  }
  printf("\n");

  decode(encoding, decoding);
  printf("Decoded word: %s\n", decoding);

 return 0;
}

void encode(char *code_word, int *encoding) {
  int i = 0;
  while (code_word[i] != '\0') {
    encoding[i] = codekey[(int)code_word[i]-97];
    i++;
  }
  encoding[i] = CODEEND;
}

void decode(int *encoding, char *decoding) {
  int i = 0;
  int j;
  while (encoding[i] != CODEEND) {
    for (j = 0; j < 26; j++) {
      if (encoding[i] == codekey[j]) {
        decoding[i] = (char)(97+j);
      }
    } 
    i++;
  }
  decoding[i] = '\0';
}


