#include <stdio.h>
#include <time.h>

int main()
{
    time_t dateTime;
    time(&dateTime);

    printf ("The current local time is: %s", ctime(&dateTime));
    return 0;
}
