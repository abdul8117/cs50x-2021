#include <stdio.h>
#include <cs50.h>

int get_start_size();
int get_end_size();

int main(void)
{

    int start_size = get_start_size();
    while (start_size < 9)
    {
        start_size = get_start_size();
    }

    int end_size = get_end_size();
    while (end_size < start_size)
    {
        end_size = get_end_size();
    }

    int curr_size = start_size;
    int years = 0;
    int newborns = 0;
    int deaths = 0;

    while (curr_size < end_size)
    {
        newborns = curr_size / 3;
        deaths = curr_size / 4;

        curr_size += newborns - deaths;

        years++;
    }

    printf("Years: %d\n", years);
}

int get_start_size()
{
    int n = get_int("Start size:");
    printf("\n");

    return n;
}

int get_end_size()
{
    int n = get_int("End size:");
    printf("\n");

    return n;
}