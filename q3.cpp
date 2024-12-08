#include <bits/stdc++.h>
using namespace std;

int getMinOfMaxes(int* arr, int n, int k){
  deque<int> maxes(k);
  int i = 0;

  for(;i < k; ++i){
    while(!maxes.empty() && arr[i] >= arr[maxes.back()]){
      maxes.pop_back();
    }
    maxes.push_back(i);
  }

  int minOfMaxes = arr[maxes.front()];

  for(; i < n; ++i){
    while(!maxes.empty() && maxes.front() <= i - k){
      maxes.pop_front();
    }
    while(!maxes.empty() && arr[i] >= arr[maxes.back()]){
      maxes.pop_back();
    }
    maxes.push_back(i);

    if(arr[maxes.front()] < minOfMaxes){
      minOfMaxes = arr[maxes.front()];
    }
  }
  return minOfMaxes;
}

int main(){
  int n = 0;
  int k = 0;

  printf("Enter k : ");
  scanf("%d", &k);
  printf("Enter n : ");
  scanf("%d", &n);
  if(k > n || n < 1){
    printf("Invalid input");
    exit(1);
  }

  int* arr = (int*)malloc(sizeof(int)*n);
  for(int i = 0; i<n; ++i){
    printf("Enter element %d : ", i+1);
    scanf("%d", &arr[i]);
  }
  printf("The minimum of maximums is %d\n", getMinOfMaxes(arr, n, k));
  free(arr);

  return 0;
}
