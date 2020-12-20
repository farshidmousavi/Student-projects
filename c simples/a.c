#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int arr1[5][5],i,j,sum,m;
  float d,jazr,nums[5],jaz[5];
  printf("Input elements in the matrix :\n");
  for(i=0;i<5;i++)
  {
      for(j=0;j<5;j++)
      {
          //get 5*5 matrix data from input
	      printf("a(%d,%d) : ",i+1,j+1);
	      scanf("%d",&arr1[i][j]);
      }
  }
  //print matrix to output
  for(i=0;i<5;i++)
  {
      sum =0;
      m = 1;
      printf("\n");
      for(j=0;j<5;j++){
           printf("%d\t",arr1[i][j]);
           sum +=arr1[i][j];
           m = m*arr1[i][j];
      }
      d = (float)sum/(float)5;//Calculate the arithmetic mean محاسبه میانگین اعداد سطر
      nums[i] = d;
      jazr = pow(m,0.2);//Calculate the geometric mean of row  محاسبه مسانگین هندسی سطر
      jaz[i] = jazr;
  }
  printf("\n\n");
  printf("AA={%.2f,%.2f,%.2f,%.2f,%.2f}",nums[0],nums[1],nums[2],nums[3],nums[4]);
  printf("\n\n");
  printf("AE={%.2f,%.2f,%.2f,%.2f,%.2f}",jaz[0],jaz[1],jaz[2],jaz[3],jaz[4]);//geometric mean
  printf("\n\n");
  return 0;
}
