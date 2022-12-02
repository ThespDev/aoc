#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//true if opponent move
int convert(char letter, bool opponent){
  if (opponent){
    switch(letter)
      {
      case 'A':
        return 1;
        break;
      case 'B':
        return 2;
        break;
      case 'C':
        return 3;
        break;
    }
  }

  else if (!opponent){
    switch(letter)
      {
      case 'X':
        return 1;
        break;
      case 'Y':
        return 2;
        break;
      case 'Z':
        return 3;
        break;
    }
  }
return 0;
}
// 1 beats 3
// 2 beats 1
// 3 beats 2
int main (int argc, char *argv[])
{
  FILE *file_data = fopen("input", "r");
  char line[256];
  char opp;
  char self;
  int oppint;
  int result;
  int totalscore;
  while (fgets(line, sizeof line, file_data) != NULL) {
    sscanf(line,"%c %c",&opp,&self);
    oppint = convert(opp,true);
    result = convert(self,false);
    switch (result) {
      case 1:
        if (oppint == 1){
          totalscore += 3;
        }
        else if (oppint == 2){
          totalscore += 1;
        }
        else{
          totalscore += 2;
        }
        break;
      case 2:
        totalscore += 3;
        totalscore += oppint;
        break;
      case 3:
        if (oppint == 1){
          totalscore += 2;
        }
        else if (oppint == 2){
          totalscore += 3;
        }
        else{
          totalscore += 1;
        }
        totalscore += 6;
        break;
    }
  }
  printf("score: %d\n",totalscore);
  return 0;
}
