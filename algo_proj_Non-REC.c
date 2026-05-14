#include <stdio.h>
#include<time.h>
void insertionSort(int arr[], int n){
    int key, j;
    for (int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int missingInt(int arr[], int n){
    insertionSort(arr, n);
    int missing = 1;
    for (int i = 0; i < n; i++){
        if (arr[i] <= 0)
            continue;
        if (arr[i] == missing){
            missing++;
        }
        else if (arr[i] > missing){
            break;
        }
    }
    return missing;
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

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

    end = clock();

    // Calculate time in seconds
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}