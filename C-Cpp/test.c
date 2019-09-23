#if 0
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num = rand();
  while (true)
  {
    int user_input = 0;

    printf("please input a num : ");
    scanf("%d", &user_input);

    if (user_input == num)
    {
      printf("猜对了\n");
    }
    else if (user_input < num)
    {
      printf("小了\n");
    }
    else 
    {
      printf("大了\n");
    }
  }

  return 0;
}
#endif

#include <stdio.h>
#include "test.h"

int arr[] = {1, 2,3,4,5,6,7,8};
#define TOTAL_ELEMENTS (sizeof(arr) / sizeof(arr[0]))

int main()
{
  int d = -1;

  if (d < TOTAL_ELEMENTS - 2)
  {
    printf("here.\n");
  }

  return 0;
}


