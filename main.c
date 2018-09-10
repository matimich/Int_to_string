#include <stdio.h>
#include "int_to_string.h"

int main(void)
{
    //EXAMPLE
    int a =-100;
    unsigned int b = 105;

    printf("\n%s\n",IntToString(&a));   //display result
    printf("\n%s\n",UIntToString(&b));   //display result


    return 0;
}
