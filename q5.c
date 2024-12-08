#include<stdio.h>
#include<stdlib.h>



int main(){
  int data[3][4]; // 4 trainees with 3 rounds
  int sum[4];
  for(int i = 0; i < 4; ++i){
    sum[i] = 0;
  }

  for(int i = 0; i < 3; ++i){
    printf("Enter the  data for round %d\n", i+1);
    for(int j = 0; j < 4; ++j){
      printf("Enter the data for trainee %d : ", j+1);
      scanf("%d", &data[i][j]);
      if(data[i][j] > 200 || data[i][j] < 0){
        printf("Invalid Input\n");
        exit(0);
      }
      sum[j] += data[i][j];
    }
  }

  int flag = 0;

  for(int i = 0; i < 4; ++i){
    sum[i] /= 3;
    if(sum[i] > 100){
      flag = 1;
    }
  }

  if(flag == 0){
    printf("All trainees are unfit\n");
    return 0;
  }

  int max = sum[0];
  for(int i = 1; i< 4; ++i){
    if(sum[i] > max){
      max = sum[i];
    }
  }
  for(int i = 0; i<4; ++i){
    if(sum[i] == max){
      printf("Trainee Number %d\n", i+1);
    }
  }

  return 0;
}
