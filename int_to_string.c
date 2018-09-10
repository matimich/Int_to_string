#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "int_to_string.h"
#include <inttypes.h>




char *IntToString(int *number)
{

    uint8_t size_of_string=0;//uint8_t  //Number of signs which our string will take.
    int give_number = *number; //Copying number to the another variable
    int give_number_2 = *number; //Copying number to the another variable

    if(*number <= 2147483647 && *number >= 0 ) // Counting the number of signs in one string.
    {
        do
        {
            *number /=10;
            size_of_string++;
        }
        while(*number!=0);
        size_of_string++; //Adding extra field for '\0'.
    }
    else if(*number >= -2147483648 && *number < 0) // Counting the number of signs in string.
    {
        do
        {
            *number /=10;
            size_of_string++;
        }
        while(*number!=0);
        size_of_string+=2; //Adding extra field for '\0' and  '-'.
    }
    else//If variable doesn't contain in range - exit with error.
    {
        exit(1);
    }
    int power = 1;
    uint8_t strings_incrementation = 0;
    char *string = (char*)malloc(size_of_string*sizeof(char));  //A dynamic memory location for string.
    char char_number=48;  //Equivalent of '0';

    if(give_number >= -2147483648 && give_number < 0) //putting '-' into my string
    {
        string[0] = '-';   
        strings_incrementation++;
        for(int e = 1;e < (size_of_string-2);e++)
            {
                power *= 10;
            }
        give_number = abs(give_number);//An absolute value.
        give_number_2 = abs(give_number_2);// An absolute value.
    }
    else
    {
        for(int e = 1;e < (size_of_string-1);e++)
            {
                power *= 10;
            }
    }
    while(power!=0) //Changing a number to string.
        {
            give_number/=power;
            give_number_2 %= power;
            char_number=48+give_number;
            give_number = give_number_2;
            string[strings_incrementation]=char_number;
            strings_incrementation++;
            power/=10;
        }
    string[strings_incrementation]='\0';//The last sign for string.

    #if SAVE_TO_FILE_INT == 1
    FILE *new_int;

    if((new_int =fopen("int_txt.txt","a")) == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(new_int,"%s\n",string);
    fclose(new_int);

    #endif // SAVE_TO_FILE_INT

    return string;
}



char *UIntToString(unsigned int *number)
{

    uint8_t size_of_string =0;//uint8_t  //A number of signs which our string will take.
    int give_number = *number; //Copying a number to the another variable
    int give_number_2 = *number; //Copying a number to the another variable

    if(*number <= 4294967295 && *number >= 0 ) // Counting the number of signs in string.
    {
        do
        {
            *number /=10;
            size_of_string++;
        }
        while(*number!=0);
        size_of_string++; //Adding extra field for '\0'.
    }
    else//If a variable doesn't contain in range - exit with error.
    {
        exit(1);
    }

    unsigned int power = 1;
    uint8_t strings_incrementation = 0;
    char *string = (char*)malloc(size_of_string*sizeof(char));//A dynamic memory location for string.
    char char_number=48;  //Equivalent of '0';

    for(int e = 1;e < (size_of_string-1);e++)
    {
        power *= 10;
    }

    while(power!=0) //Changing a number to string.
        {
            give_number/=power;
            give_number_2 %= power;
            char_number=48+give_number;
            give_number = give_number_2;
            string[strings_incrementation]=char_number;
            strings_incrementation++;
            power/=10;
        }
    string[strings_incrementation]='\0';//The last sign for string.

    #if SAVE_TO_FILE_INT == 1

    FILE *uint_new;

    if((uint_new = fopen("uint_txt.txt","a")) == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(uint_new,"%s\n",string);
    fclose(uint_new);

    #endif // SAVE_TO_FILE_INT

    return string;
}

