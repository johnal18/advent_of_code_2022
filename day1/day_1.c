#include <stdio.h>
#include <stdlib.h>

int most_calories = 0;
int second_most_calories = 0;
int third_most_calories = 0;

int main()
{
    int current_elf = 0;

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("./input.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {

        if (atoi(line) == 0)
        {
            if (current_elf > most_calories)
            {
                third_most_calories = second_most_calories;
                second_most_calories = most_calories;
                most_calories = current_elf;
            }
            else if (current_elf > second_most_calories)
            {
                third_most_calories = second_most_calories;
                second_most_calories = current_elf;
            }
            else if (current_elf > third_most_calories)
            {
                third_most_calories = current_elf;
            }
            current_elf = 0;
        }
        else
        {
            current_elf += atoi(line);
        }

        printf("%d\n", atoi(line));
    }

    fclose(fp);
    if (line)
        free(line);
    
    printf("most calories: %d, socond most: %d, third most: %d\n", most_calories, second_most_calories, third_most_calories);
    printf("sum of top three: %d\n", most_calories + second_most_calories + third_most_calories);
    return 0;
}