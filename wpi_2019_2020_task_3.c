#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STRING_SIZE 128

double min(double a, double b)
{
    return (a<b) ? a : b;
}

double ocena(char S1[], char S2[], double KP, double KN)
{
    int S1_len, S2_len, grid_size;
    double* grid;
    int i, j;
    double min_KP, result;

    S1_len = strlen(S1);
    S2_len = strlen(S2);
    grid_size = (S1_len+1)*(S2_len+1);

    grid = (double*) malloc(grid_size*sizeof(double));
    memset(grid, 0, grid_size);
    
    j = S2_len;
    for(i = S1_len-1; i >= 0; --i)
    {
        grid[i*S2_len+j] = grid[(i+1)*S2_len+j] + KP;
    }

    i = S1_len;
    for(j = S2_len-1; j >= 0; --j)
    {
        grid[i*S2_len+j] = grid[i*S2_len+j+1] + KP;
    }

    for(i = S1_len-1; i >= 0; --i)
    {
        for(j = S2_len - 1; j >= 0; --j)
        {
            min_KP = min(grid[i*S2_len+j+1], grid[(i+1)*S2_len+j]) + KP;
            if(S1[i] == S2[j])
            {
                grid[i*S2_len+j] = min(min_KP, grid[(i+1)*S2_len+j+1]);
            }
            else
            {
                grid[i*S2_len+j] = min(min_KP, grid[(i+1)*S2_len+j+1] + KN);
            }
        }
    }
    result = grid[0];
    free(grid);
    return result;
}

int main()
{
    char buffer[STRING_SIZE], string1[STRING_SIZE], string2[STRING_SIZE];
    double KP, KN, result;

    fgets(buffer, STRING_SIZE, stdin);
    sscanf(buffer, "%s\n", string1);
    fgets(buffer, STRING_SIZE, stdin);
    sscanf(buffer, "%s\n", string2);
    
    scanf("%lf%lf", &KP, &KN);

    result = ocena(string1, string2, KP, KN);

    printf("%f\n", result);
    return 0;
}
