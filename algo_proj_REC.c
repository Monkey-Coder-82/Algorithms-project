#include <stdio.h>
#include<time.h>

void merge( int ARR1[] , int LARR1 , int ARR2[] , int LARR2 , int ARR3[]){
    int i = 0 , j = 0 , z = 0;
    while( i < LARR1 && j < LARR2 ){
        if( ARR1[i] < ARR2[j]){
          ARR3[z++] = ARR1[i++];
        }
        else{
          ARR3[z++] = ARR2[j++];
        }
    }
    while(i<LARR1){
        ARR3[z++] = ARR1[i++];
    }
    while(j < LARR2){
        ARR3[z++] = ARR2[j++];
    }
}  

void merge_sort(int array[] , int len){
    if (len <= 1) return ;
    int ls = len/2; int rs = len - ls;  
    merge_sort( array , ls );
    merge_sort( array + ls , rs );
    int tmp[len] ;
    merge( array , ls , array + ls , rs , tmp );
    for(int i = 0 ; i < len ; i++)
      array[i] = tmp[i] ;
}

int missingInt(int A[], int n , int missing , int index){
    if(index >= n)
      return missing; 
    if(A[index] <= 0 || A[index] < missing)
      return missingInt(A,n,missing,index+1);
    if(A[index] == missing)
      return missingInt(A,n,missing+1,index+1);
    if (A[index] > missing)
      return missing;
}

int solution(int A[] ,int n){
  merge_sort( A , n );
  return missingInt(A,n,1,0);
}

int main() {
  clock_t start, end;
  double cpu_time_used;

  start = clock();

  int A1[] = {1, 3, 6, 4, 1, 2};
  int n = sizeof(A1) / sizeof(A1[0]);
  printf("Test 1: A = [1, 3, 6, 4, 1, 2]\n");
  printf("Result: %d (Expected: 5)\n\n", solution(A1, n));

  int A2[] = {1, 2, 3};
  n = sizeof(A2) / sizeof(A2[0]);
  printf("Test 2: A = [1, 2, 3]\n");
  printf("Result: %d (Expected: 4)\n\n", solution(A2, n));

  int A3[] = {-1, -3};
  n = sizeof(A3) / sizeof(A3[0]);
  printf("Test 3: A = [-1, -3]\n");
  printf("Result: %d (Expected: 1)\n\n", solution(A3, n));
  
  int A4[100000];
  for(int i = 0 ; i < 100000 ; i++){
    if(i == 5000){
      continue;
    }
    A4[i] = i ;
  }
  n = sizeof(A4) / sizeof(A4[0]);
  printf("Test 4: A = [0...100000]\n");
  printf("Result: %d (Expected: 5000)\n\n", solution(A4, n));

  end = clock();

  // Calculate time in seconds
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Execution time: %f seconds\n", cpu_time_used);

  return 0;
}