#include <stdio.h>
#include <stdlib.h>

char human;

void select_turn(void) {
  printf("Select your turn.(o/x)\n");
  scanf("%s", &human);
}

int input_AI(char board[]) {
  int ainum;
  while (1) {
    ainum = rand() % 9;
    if ((board[ainum] == 'o') || (board[ainum] == 'x')) {
      continue;
    }
    break;
  }
  return ainum+1;
}

int input(int turn, char board[]) {
  int num;
  if (turn % 2 == 0) {
    printf("\'o\' turn\n");
  } else {
    printf("\'x\' turn\n");
  }
  if (((human == 'o') && (turn % 2 == 0)) || ((human == 'x') && (turn % 2 == 1))) {
    printf("input number\n");
    scanf("%d", &num);
  } else {
    num = input_AI(board);
    printf("AI puts %d.\n", num);
  }
  return num-1;
}

void init(char board[]) {
  int i;
  for (i = 0; i < 9; i++) {
    board[i] = (char)(i+49);
  }
}

void update(char board[], int num, int turn) {
  if (turn % 2 == 0) {
    board[num] = 'o';
  } else {
    board[num] = 'x';
  }
}

void show(char board[]) {
  printf("%c%c%c\n", board[0], board[1], board[2]);
  printf("%c%c%c\n", board[3], board[4], board[5]);
  printf("%c%c%c\n", board[6], board[7], board[8]); }

int judge(char board[], int turn) {
  int res;
  if ((board[0] == board[1]) && (board[1] == board[2])) {
    if (board[0] == 'o') {
      res = 1;
    } else {
      res = 2;
    }
  } else if ((board[3] == board[4]) && (board[4] == board[5])) {
    if (board[3] == 'o') {
      res = 1;
    } else {
      res = 2;
    }
  } else if ((board[6] == board[7]) && (board[7] == board[8])) {
    if (board[6] == 'o') {
      res = 1;
    } else {
      res = 2;
    }
  } else if ((board[0] == board[3]) && (board[3] == board[6])) {
    if (board[0] == 'o') {
      res = 1;
    } else {
      res = 2;
    }
  } else if ((board[1] == board[4]) && (board[4] == board[7])) {
    if (board[1] == 'o') {
      res = 1;
    } else {
      res = 2;
    }
  } else if ((board[2] == board[5]) && (board[5] == board[8])) {
    if (board[2] == 'o') {
      res = 1;
    } else {
      res = 2;
    }
  } else if ((board[0] == board[4]) && (board[4] == board[8])) {
    if (board[0] == 'o') {
      res = 1;
    } else {
      res = 2;
    }
  } else if ((board[2] == board[4]) && (board[4] == board[6])) {
    if (board[2] == 'o') {
      res = 1;
    } else {
      res = 2;
    }
  } else {
    res = 0;
  }
  if (res == 1 || res == 2) {
    return res;
  } else if (turn == 8) {
    return 3;
  } else {
    return res;
  }
}

void result(int res) {
  if (res == 1) {
    if (human == 'o') {
      printf("You win !\n");
    } else {
      printf("You lose.\n");
    }
  } else if (res == 2) {
    if (human == 'x') {
      printf("You win !\n");
    } else {
      printf("You lose.\n");
    }
  } else {
    printf("draw !\n");
  }
}

int main(void) {
  char board[9];
  char cont;
  int num, res;

  while (1) {
    select_turn();
    init(board);
    int turn = 0;
    while (1) {
      show(board);

      num = input(turn, board);

      update(board, num, turn); 

      res = judge(board, turn);
      if (res) {
        break;
      }

      turn++;
    } 

    show(board);
    result(res);

    printf("continue?(y/n)\n");
    scanf("%s", &cont);
    if (cont == 'y') {
      continue;
    } else {
      break;
    }
  }
  
  return 0;
}
