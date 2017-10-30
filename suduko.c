/*
 * Author : Vijay Nag
 * Date   : 21st Jun 2014
 * Brute force solution to suduko puzzle
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

#define MAX_SUDUKO_CELL 81
#define ROWIDX(cell_no) ((cell_no)/9)
#define COLIDX(cell_no) ((cell_no)%9)
#define BOXIDX(cell_no) ((cell_no)/27)

typedef struct Suduko {
    uint8_t cell[MAX_SUDUKO_CELL];
    int unfilled_cnt;
} Suduko;

#define SET_CELL(s,idx,_v)  \
({                          \
 (s)->cell[idx] = _v;       \
 (s)->unfilled_cnt--;       \
})

#define RESET_CELL(s,idx,_v)\
({                          \
 (s)->cell[idx] = 0;        \
 (s)->unfilled_cnt++;       \
})

void printSuduko(Suduko *s)
{
    for(int i=0;i<9;++i) {
      for(int j=0;j<9;++j) {
          printf("%d ", s->cell[i*9+j]);
      }
      printf("\n");
    }
}

int getFirstUnfilledCell(Suduko *s)
{
  for(int i=0;i<MAX_SUDUKO_CELL;++i)
    if (s->cell[i]==0) {
      return i;
    }
}

uint16_t getPossibleFills(Suduko *s, int cell_idx)
{
  uint16_t bmap=0x1FF;

  for(int i=0;i<MAX_SUDUKO_CELL;++i) {
    if (s->cell[i]!=0 && (ROWIDX(i)==ROWIDX(cell_idx) ||
        COLIDX(i)==COLIDX(cell_idx) ||
        (BOXIDX(i)==BOXIDX(cell_idx) &&
         (COLIDX(i)/3 == COLIDX(cell_idx)/3)))) {
      uint8_t val = s->cell[i];
      bmap&=~(1<<(val-1));
    }
  }
  return bmap;
}

int solve(Suduko *s)
{
    if (!s->unfilled_cnt) {
        printf("Solution found for the puzzle....\n");
        printSuduko(s);
        printf("End of the solution\n");
        return 1;
    }

    int cell_idx = getFirstUnfilledCell(s);
    uint16_t fills = getPossibleFills(s, cell_idx);
    uint8_t k=9; //start from digit 9

    while (k) {
      if (fills&(1<<(k-1))) {
        SET_CELL(s, cell_idx, k);
        if (!solve(s)) {
          RESET_CELL(s, cell_idx, k);
        }
      }
      k--;
    }
    return 0; //unsolved
}

int initSuduko(Suduko *s, char *str)
{
   s->unfilled_cnt=0;
   for (int i=0;i<MAX_SUDUKO_CELL;++i) {
     if (!isdigit(str[i])) {
      printf("Bad suduko puzzle...Try again\n");
      return -1;
     }
     s->cell[i] = str[i]-'0';
     if (s->cell[i]==0)
         s->unfilled_cnt++;
   }
   return 0;
}

int main()
{
    char str[MAX_SUDUKO_CELL+2];
    Suduko s;

    printf("Enter serialized suduko puzzle with unfilled cells as zero\n");
    printf("Eg: 7000240002323.....\n");

    scanf("%s", &str[0]);
    if (strlen(str)<81 || strlen(str) > 81) {
        printf("Bad suduko puzzle...Try again\n");
        return -1;
    }
    initSuduko(&s,str);
    printSuduko(&s);
    printf("Printing the solution now...\n");
    solve(&s);
    return 0;
}
