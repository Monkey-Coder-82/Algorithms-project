#include <stdio.h>
#include <stdbool.h>

int missingInt(int A[], int N)
{
    int num = 1;

    while (1)
    {
        bool found = false;

        for (int i = 0; i < N; i++)
        {
            if (A[i] == num)
            {
                found = true;
                break;
            }
        }

        if (found == false)
        {
            return num;
        }

        num++;
    }
}

int main(){

    int A1[] = {1, 3, 6, 4, 1, 2};
    int n = sizeof(A1) / sizeof(A1[0]);
    printf("Test 1: A = [1, 3, 6, 4, 1, 2]\n");
    printf("Result: %d (Expected: 5)\n\n", missingInt(A1, n));

    int A2[] = {1, 2, 3};
    n = sizeof(A2) / sizeof(A2[0]);
    printf("Test 2: A = [1, 2, 3]\n");
    printf("Result: %d (Expected: 4)\n\n", missingInt(A2, n));

    int A3[] = {-1, -3};
    n = sizeof(A3) / sizeof(A3[0]);
    printf("Test 3: A = [-1, -3]\n");
    printf("Result: %d (Expected: 1)\n\n", missingInt(A3, n));

    int A4[100000];
    for(int i = 0 ; i < 100000 ; i++){
      if(i == 5000){
        continue;
      }
      A4[i] = i ;
    }
    n = sizeof(A4) / sizeof(A4[0]);
    printf("Test 4: A = [0...100000]\n");
    printf("Result: %d (Expected: 5000)\n\n", missingInt(A4, n));

    return 0;
}