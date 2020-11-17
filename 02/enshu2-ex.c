#include <stdio.h>

int input(int turn) {
  int num;
  if (turn % 2 == 0) {
    printf("\'o\' turn\n");
  } else {
    printf("\'x\' turn\n");
  }
  printf("input number\n");
  scanf("%d", &num);
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
    printf("\'o\' player is win !\n");
  } else if (res == 2) {
    printf("\'x\' player is win !\n");
  } else {
    printf("draw !\n");
  }
}

int main(void) {
  char board[9];
  char cont;
  int num, res;

  while (1) {
    init(board);
    int turn = 0;
    while (1) {
      show(board);

      num = input(turn);

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
