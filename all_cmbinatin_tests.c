/* In this programm we will attempt to do the following:
    1.Run the simulation for all possible 10-digit numbers
    2.Check and verify the results
    3.Save and print them(possibly in a file)
To check the results:
    1.We check if there is a stable or an oscillating pattern for just the last 2 arrays(for now)
    2.If there is we save
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define Num_of_repetitions 100

void process(void); // Handles the proccess of the array
void print_arr(int arr1[10]);
void check_and_save(unsigned long long int n);
void order_and_print(void);
void function(int arr1[10]);
int is_circular(void);
unsigned long long int arr_to_num(int arr1[10]); // packs the array into just a number to check faster
unsigned long long *results = NULL;              // This creates a pointer for results(is used in check and save)
size_t count = 0, capacity = 0;                  // count is the number of distinct cases and capacity is the space allocated to the memory if a number is present

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
        printf("%2d\n", arr1[i]);
    }
    printf("\n");
}

void process(void)
{
    unsigned long long int prev_num, prev_num_1, num; // prev_num is the third to last num of the sequence, prev_num1 is the second to last and num is the last
    int arr[10] = {0};                                // The intial array of numbers
    for (int a = 0; a <= 9; a++)
        for (int b = a; b <= 9; b++)
            for (int c = b; c <= 9; c++)
                for (int d = c; d <= 9; d++)
                    for (int e = d; e <= 9; e++)
                        for (int f = e; f <= 9; f++)
                            for (int g = f; g <= 9; g++)
                                for (int h = g; h <= 9; h++)
                                    for (int i = h; i <= 9; i++)
                                        for (int j = i; j <= 9; j++)
                                        {
                                            arr[0] = a;
                                            arr[1] = b;
                                            arr[2] = c;
                                            arr[3] = d;
                                            arr[4] = e;
                                            arr[5] = f;
                                            arr[6] = g;
                                            arr[7] = h;
                                            arr[8] = i;
                                            arr[9] = j;
                                            for (int k = 0; k < Num_of_repetitions; k++)
                                            {
                                                function(arr);
                                                num = arr_to_num(arr);
                                                if (is_circular(num,k) == 1)
                                                {
                                                
                                                }
                                            }

                                            if (num == prev_num)
                                            {
                                                check_and_save(num);
                                                check_and_save(prev_num_1);
                                            }
                                        }
    order_and_print();
}

unsigned long long int arr_to_num(int arr1[10])
{
    unsigned long long int number = 0;
    for (int i = 0; i < 10; i++)
    {
        number = number * 10 + (long long unsigned)arr1[i];
    }
    return number;
}

void check_and_save(unsigned long long int n)
{
    if (capacity == 0)
    {                                                            // For the first save
        capacity = 4096;                                         // reserve space
        results = malloc(capacity * sizeof(unsigned long long)); // Checks and allocates memory for the array of numbers
    }
    if (count == capacity)
    {                  // If the space is full
        capacity *= 2; // double the space
        results = realloc(results, capacity * sizeof(unsigned long long));
    }
    results[count] = n; // saves the number to dynamic memory
    count++;
}
void order_and_print(void)
{
    long long unsigned int temp = 0;
    // We will implement a bublesort technique to store the data in an ordered way
    for (size_t i = 0; i < count; i++)
    {
        for (size_t k = 0; k < count - 1; k++)
        {
            if (results[k] >= results[k + 1])
                ; // if the order is correct do not do anything
            else
            {
                temp = results[k];           // stores the value of the results[k] temporarily
                results[k] = results[k + 1]; // puts the value of k to results[k]
                results[k + 1] = temp;       // puts temp in results[k+1]
            }
        }
    }
    for (size_t i = 0; i < count; i++)
    {
        if (i == 0 || results[i] != results[i - 1]) // Because we ordered the numbers now it is easy to check only sequential
            printf("%llu\n", results[i]);
    }
    free(results); // give the memory back to the OS
    results = NULL;
}
int main(void)
{

    process();
    return 0;
}
