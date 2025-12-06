#include <string.h>
#include <stdio.h>
#define Num_of_repetitions 100
void process(void); // Handles the proccess of the array
void print_arr(int arr1[10]);
void function(int arr1[10]);
void function(int arr1[10])
{
    int temp[10] = {0};
    for (int i = 0; i < 10; i++) // for every number i(i \in [0-9])of the array we are checking for which integer k from 0 to 9 arr[i]=k and if so we increase it

    {
        for (int k = 0; k < 10; k++)
        {
            if (arr1[i] == k)
            {
                temp[k]++;
                if (temp[k] == 10)
                    temp[k] = 0;
            }
        }
    }
    memcpy(arr1, temp, 10 * sizeof(arr1[0])); // copying the temp to arr1 to prepare it for the next repetition
}

void print_arr(int arr1[10])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%2d", arr1[i]);
    }
    printf("\n");
}
void process(void)
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // The intial array of numbers
    for (int i = 0; i < Num_of_repetitions; i++)
    {
        function(arr);
        if (i == Num_of_repetitions - 2)//printing the second to last array to check for oscillation
            print_arr(arr);
    }
    print_arr(arr);
}
int main(void)
{

    process();
    return 0;
}
