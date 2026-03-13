#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int n, i;
    int H, M, S;
    int x = 0;

    printf("Enter the number of tasks you want to perform: ");
    scanf("%d", &n);

    char **strings = (char **)malloc(n * sizeof(char *));
    int *alarmH = (int *)malloc(n * sizeof(int));
    int *alarmM = (int *)malloc(n * sizeof(int));
    int *alarmS = (int *)malloc(n * sizeof(int));

    if (strings == NULL || alarmH == NULL || alarmM == NULL || alarmS == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        strings[i] = (char *)malloc(100 * sizeof(char));

        if (strings[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter task %d: ", i + 1);
        scanf(" %[^\n]", strings[i]);

        printf("Set alarm for task %d [HH:MM:SS]: ", i + 1);
        scanf("%d:%d:%d", &alarmH[i], &alarmM[i], &alarmS[i]);
    }

    printf("\nYou have stored the following tasks:\n");

    for (i = 0; i < n; i++)
    {
        printf("Task %d: %s\n", i + 1, strings[i]);
    }

    printf("\nEnter current time [HH:MM:SS]: ");
    scanf("%d:%d:%d", &H, &M, &S);

    while (1)
    {
        for (i = 0; i < n; i++)
        {
            if (H == alarmH[i] && M == alarmM[i] && S == alarmS[i])
            {
                if (x <= 20)
                {
                    system("cls");
                    printf("\n..... Time up for task: %s .....\a\n", strings[i]);
                    Sleep(3000);
                    x++;
                }
            }
        }

        system("cls");
        printf("Current Time: %02d:%02d:%02d\n", H, M, S);

        Sleep(1000);

        S++;

        if (S == 60)
        {
            S = 0;
            M++;
        }

        if (M == 60)
        {
            M = 0;
            H++;
        }

        if (H == 24)
        {
            H = 0;
        }
    }

    return 0;
}
