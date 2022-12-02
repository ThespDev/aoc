#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int max = 0;
    int currSum = 0;
    FILE *file_data = fopen("input.txt", "r");
    char line[256];
    while (fgets(line, sizeof line, file_data) != NULL) {
        if (strcmp(line,"\n") == 0){
            if (currSum > max){
                max = currSum;
                printf("max: %d\n",max);
            }
            currSum = 0;
        }
        else{
            currSum += atoi(line);
        }
    }
    if (currSum > max){
            max = currSum;
    }
    printf("Max: %d\n",max);
    return 0;
}


