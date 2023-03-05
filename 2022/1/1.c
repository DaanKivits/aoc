#include <stdio.h>  // reading input file
#include <stdlib.h> // reading input file

#define LEN 999

int compare_ints(const void *a, const void *b)
{
  int arg1 = *(int *)a;
  int arg2 = *(int *)b;

  if (arg1 < arg2)
    return 1;
  if (arg1 > arg2)
    return -1;
  return 0;

  // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
  // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int main()
{
  // read input
  const char *input_path = "input";
  FILE *fin = fopen(input_path, "r");
  char buff[10];
  int elfsum = 0;
  int calorie_sum[LEN] = {};
  int max_sum = 0;
  int i = 0;
  while (fgets(buff, 255, fin) != NULL)
  {
    // buff holds every line, loops until EOF
    if (buff[0] == '\n')
    {
      calorie_sum[i++] += elfsum;
      if (elfsum > max_sum)
      {
        max_sum = elfsum;
      }
      elfsum = 0;
    }
    else
    {
      int newsum = strtol(buff, NULL, 10);
      // printf("newsum: %d\n", newsum);
      elfsum += newsum;
      // printf("elfsum: %d\n", elfsum);
    }
  }

  // sort calorie array
  qsort(calorie_sum, LEN, sizeof(int), compare_ints);

  // print all the elfsums
  for (int j = 0; j < LEN; j++)
  {
    if (calorie_sum[j] == 0) {
      break;
    }
    printf("%d\n", calorie_sum[j]);
  }

  // TAKE FIRST ELEMENT OF ARRAY
  long answerb = calorie_sum[0] + calorie_sum[1] + calorie_sum[2]; 

  printf("answer b: %ld\n", answerb);
  printf("super ultimate maximum sum: %d\n", max_sum);
}
