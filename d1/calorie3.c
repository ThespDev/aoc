#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int max = 0;
    int currSum = 0;
    int count = 0;
    int *results = NULL;

    results=(int*)malloc(sizeof(int));
    FILE *file_data = fopen("input.txt", "r");
    char line[256];
    while (fgets(line, sizeof line, file_data) != NULL) {
        if (strcmp(line,"\n") == 0){
            results = realloc(results,(count + 1) * sizeof(int));
            results[count] = currSum;
            currSum = 0;
            count++;
        }
        else{
            currSum += atoi(line);
        }
    }
    results = realloc(results,(count + 1) * sizeof(int));
    results[count] = currSum;
    int third,second,first = 0;
    for (int i = 0; i<count+1; i++){
    if (results[i] > first){
        third = second;
        second = first;
        first = results[i];
        continue;
    }
    else if(results[i] > second){
        third = second;
        second = results[i];
        continue;
    }
    else if (results[i] > third){
        third = results[i];
        continue;
    }
    }
    printf("FIRST: %d\nSECOND %d\nTHIRD: %d\n",first,second,third);
    printf("final result: %d\n",(first+second+third));
    return 0;
}


