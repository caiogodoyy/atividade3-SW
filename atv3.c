#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int nums[0];

void *minimo(void *arg)
{
    int num = *(int *)arg;
    int min = nums[0];
    for (int i = 0; i < num; i++)
    {
        if (min > nums[i])
        {
            min = nums[i];
        }
    }

    int *retorno = malloc(sizeof(int));
    *retorno = min;
    return (void *)retorno;
}

void *maximo(void *arg)
{
    int num = *(int *)arg;
    int max = nums[0];
    for (int i = 0; i < num; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
        }
    }

    int *retorno = malloc(sizeof(int));
    *retorno = max;
    return (void *)retorno;
}

void *media(void *arg)
{
    int num = *(int *)arg;
    int med = 0;
    for (int i = 0; i < num; i++)
    {
        med = med + nums[i];
    }
    med = med / num;

    int *retorno = malloc(sizeof(int));
    *retorno = med;
    return (void *)retorno;
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        scanf("%d", &nums[i]);

    int *x = malloc(sizeof(int));
    *x = num;

    pthread_t t1, t2, t3;
    int* med;
    int* max;
    int* min;

    if (pthread_create(&t1, NULL, &media, x) != 0)
        return 1;
    if (pthread_join(t1, (void**) &med) != 0)
        return 2;

    if (pthread_create(&t2, NULL, &maximo, x) != 0)
        return 3;
    if (pthread_join(t2, (void**) &max) != 0)
        return 4;

    if (pthread_create(&t3, NULL, &minimo, x) != 0)
        return 5;
    if (pthread_join(t3, (void**) &min) != 0)
        return 6;

    printf("\nThe avarege value is %d", *med);
    free(med);
    printf("\nThe minimum value is %d", *min);
    free(min);
    printf("\nThe maximum value is %d", *max);
    free(max);
    return 0;
}