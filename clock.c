#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int hour, min, sec;

void createTime()
{
    time_t s, val = 1;
    struct tm *current_time;
    // time in seconds
    s = time(NULL);
    // to get current time
    current_time = localtime(&s);
    hour = current_time->tm_hour;
    min = current_time->tm_min;
    sec = current_time->tm_sec;
}

void printTime(int hour, int min, int sec)
{
    while (1)
    {
        system("clear");

        // print time in minutes, hours and seconds
        printf("\n\n\n\n\t\t\t\t  %02d : %02d : %02d\n", hour, min, sec);

        fflush(stdout);

        sec++;

        // update hour, minute and second
        if (sec == 60)
        {
            min += 1;
            sec = 0;
        }
        if (hour == 24)
        {
            hour = 0;
            min = 0;
            sec = 0;
        }
        sleep(1);
    }
}

int main()
{
    createTime();
    printTime(hour, min, sec);

    return 0;
}