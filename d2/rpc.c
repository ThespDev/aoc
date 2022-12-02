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

int main (int argc, char *argv[])
{
  FILE *file_data = fopen("input", "r");
  char line[256];
  char opp;
  char self;
  int oppint;
  int selfint;
  int totalscore;
  while (fgets(line, sizeof line, file_data) != NULL) {
    sscanf(line,"%c %c",&opp,&self);
    oppint = convert(opp,true);
    selfint = convert(self,false);
    if (oppint == selfint){
        totalscore += 3;
        totalscore += convert(opp,true);
      }
    else{
      switch(oppint)
          {
          case 1:
            if (selfint == 2){
              totalscore += 6;
              }
            totalscore += selfint;
            break;
              
          case 2:
            if(selfint == 3){
                totalscore += 6;
            }
            totalscore+= selfint;
            break;
            
          case 3:
            if (selfint == 1){
                totalscore += 6;
            }
            totalscore += selfint;
            break;
          } 
      }
  }
  printf("score: %d\n",totalscore);
  return 0;
}
