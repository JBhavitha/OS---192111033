#include<stdio.h>
int main() 
{
  int p,c,count=0,i,j,alc[5][3],max[5][3],need[5][3],safe[5],available[3],done[5],terminate = 0;
  printf("Enter the number of process and resources");
  scanf("%d %d", & p, & c);
  printf("enter allocation of resource of all process %dx%d matrix", p, c);
  for (i = 0; i < p; i++) 
  {
    for (j = 0; j < c; j++) 
	{
      scanf("%d", & alc[i][j]);
    }
  }
  printf("enter the max resource process required %dx%d matrix", p, c);
  for (i = 0; i < p; i++) 
  {
    for (j = 0; j < c; j++) 
	{
      scanf("%d", & max[i][j]);
    }
  }
  printf("enter the  available resource");
  for (i = 0; i < c; i++)
    scanf("%d", & available[i]);
  printf("\n need resources matrix are\n");
  for (i = 0; i < p; i++) 
  {
    for (j = 0; j < c; j++) 
	{
      need[i][j] = max[i][j] - alc[i][j];
      printf("%d\t", need[i][j]);
    }
    printf("\n");
  }
  return 0;
}
OUTPUT:
Enter the number of process and resources5
3
enter allocation of resource of all process 5x3 matrix
1 1 2
2 1 2
3 0 1
0 2 0
1 1 2
enter the max resource process required 5x3 matrix
5 4 4
4 3 3
9 1 3
8 6 4
2 2 3
enter the  available resource
3 2 1

 need resources matrix are
4       3       2
2       2       1
6       1       2
8       4       4
1       1       1
