#include <stdio.h>
#include <time.h> //for sleep() function
#include <unistd.h>
#include <stdlib.h>

//////////////////// Copyright : I am learning, https://www.youtube.com/watch?v=954J7uCVHLA&list=PLiLzqLEAMKr7_oTKOosIP1QH4GTlZe29G ////////////////////

int main(int argc, char *argv[])
{
    int hour, minute, second;
    hour = second = 0;
    minute = atoi(argv[1]);

    if (minute > 60 || minute < 1)
    {
        system("clear");
        printf("\033[0;36m");
        printf("Please select a valid number of minutes.\n");
        return 0;
    }

    while (1)
    {
        // clear output screen
        system("clear");
        // print time in HH : MM : SS format
        printf("\n\t%02d : %02d : %02d\n", hour, minute, second);
        // clear output buffer in gcc
        fflush(stdout);
        // descrease second
        second--;
        // update hour, minute and second
        if (hour == 0 && minute == 0 && second == -1)
        {
            system("clear");
            printf("\033[0;36m");
            printf("Time is up !\n");
            return 0;
        }

        if (second == -1)
        {
            minute--;
            second = 59;
        }

        sleep(1);
    }
    return 0;
}