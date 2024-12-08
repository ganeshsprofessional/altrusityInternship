#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
  return a > b ? a : b;
}

int min(int a, int b){
  return a < b ? a : b;
}

int getMaxProfit(int* prices, int n){
  if(prices == NULL){
    return -1;
  }
  if(n < 2){
    return -1;
  }
  int minPrice = prices[0];
  int maxProfit = prices[1] - prices[0];

  for(int i = 1; i < n; ++i){
    maxProfit = max(maxProfit, prices[i] - minPrice);
    minPrice = min(minPrice, prices[i]);
  }

  return maxProfit;
}


int main(){
  int n = 0;
  printf("\nEnter the nunber of days : ");
  scanf("%d", &n);

  int* prices = (int*)malloc(sizeof(int)*n);

  for(int i = 0; i < n; ++i){
    printf("Enter price at day %d : ", i + 1);
    scanf("%d", &prices[i]);
  }

  int maxProfit = getMaxProfit(prices, n);

  if(maxProfit > 0){
    printf("The maximum profit is %d\n", maxProfit);
  }else{
    printf("No purchase made\n");
  }

  free(prices);
  return 0;
}
