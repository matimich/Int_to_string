#include <stdio.h>
#include "int_to_string.h"

int main(void)
{
    int a =-10;
    unsigned int b =15;

    printf("%s\n",IntToString(&a));   //display result
    printf("%s",UIntToString(&b));   //display result


    return 0;
}
