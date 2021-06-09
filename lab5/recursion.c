#include <stdio.h>

int find_max(int a[], int n);
int find_min(int a[], int n);
int find_sum(int a[], int n);
float find_avg(int a[], int n);

int main() {
  int a[4] = {3,5,2,4};
  int max = find_max(a, 4);
  printf("Maximum of the array is: %d\n", max);
  int min = find_min(a, 4);
  printf("Minimum of the array is: %d\n", min);
  int sum = find_sum(a, 4);
  printf("Sum of the array is: %d\n", sum);
  float avg = find_avg(a, 4);
  printf("Average of the array is: %f\n", avg);

  return 0;
}

// a recursive function to find the maximum element in the array.
int find_max(int a[], int n) {
  if(n == 1)
    return a[0];

  if(a[0] > find_max((a+1), n-1)) {
    return a[0];
  } else {
    return find_max((a+1), n-1);
  }
}

// a recursive function to find the minimum element in the array.
int find_min(int a[], int n) {
  if(n == 1)
    return a[0];

  if(a[0] < find_min((a+1), n-1)) {
    return a[0];
  } else {
    return find_min((a+1), n-1);
  }
}

// function to calcaulte the sum of the array elements.
// first argument is a reference to the array.
// second argument is the size of the array.
int find_sum(int a[], int n) {
  if(n == 1)
    return a[0];
  return a[0] + find_sum((a+1), n-1);
}

// average of the array
float find_avg(int a[], int n)
{
    float sum,avg;
    if(n==1) {
        sum=a[0];
    } else {
        sum= a[n-1]+ (n-1) * find_avg(a,n-1);
    }
    avg = sum/n;
    return avg;
}
