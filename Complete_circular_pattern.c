/* In this programm we will attempt to do the following:
    1.Run the simulation for all possible 10-digit numbers
    2.Check and verify the results
    3.Save and print them(possibly in a file)
    4.The main differnce between this and the other simulations is that all possible circular patterns are checked
To check the results:
    1.We now stop the repetition each time a cirular pattern is found.
    2.We then just save the repetitive sequence of digits as a 10-digit number.
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
int is_circular(int repetitions);                                // This function checks for circular patterns. It does not have parameters since it is checking for circular patters for numbers that are stored in dynamic memory(malloc)
unsigned long long int arr_to_num(int arr1[10]);                 // packs the array into just a number to check faster
unsigned long long *results = NULL;                              // This creates a pointer for results(is used in check and save)
size_t count = 0, capacity = 0, numbers = 0;                     // count is the number of distinct cases and capacity is the space allocated to the memory if a number is present
unsigned long long int arr_of_numbers[Num_of_repetitions] = {0}; // Creates space in memory for 100 size_t numbers
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
    int arr[10] = {0}; // The intial array of numbers
    for (int a = 0; a <= 9; a++)
    {
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
                                            memset(arr_of_numbers, 0, sizeof(arr_of_numbers));
                                            for (int k = 0; k < Num_of_repetitions; k++)
                                            {
                                                // Now we need to check and terminate the sequence when a pattern is found
                                                // So we need to first place all existing numbers into order and then check
                                                // For sorting we will use the same technique as in the order_and_print function
                                                // So we will create a similar function int with parameters the numbers.
                                                function(arr);
                                                arr_of_numbers[k] = arr_to_num(arr); // We first convert the sequence to a number and then implement the function over them
                                                if (is_circular(k) == 0)
                                                    ;
                                                else
                                                {
                                                    check_and_save(arr_of_numbers[k]);
                                                    break;
                                                }
                                            }
                                        }
        printf("Progess is in......%i%%\n", (a + 1)*10);
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
int is_circular(int repetitions)
{
    long long unsigned int temp = 0;
    // We will implement a bublesort technique to store the data in an ordered way
    for (int i = 0; i < repetitions; i++)
    {
        for (int k = 0; k < repetitions - 1; k++)
        {
            if (arr_of_numbers[k] >= arr_of_numbers[k + 1])
                ; // if the order is correct do not do anything
            else
            {
                temp = arr_of_numbers[k];                  // stores the value of the arr_of_numbers[k] temporarily
                arr_of_numbers[k] = arr_of_numbers[k + 1]; // puts the value of k to arr_of_numbers[k]
                arr_of_numbers[k + 1] = temp;              // puts temp in arr_of_numbers[k+1]
            }
        }
    }
    for (int i = 0; i < repetitions; i++)
    {
        if (i == 0 || arr_of_numbers[i] != arr_of_numbers[i - 1] || arr_of_numbers[i] == 0) // Because we ordered the arr_of_numbers, now it is easy to check. Only sequential!
            ;
        else
            return 1; // If a pattern is found then return!
    }
    return 0; // When no pattern has been found
}
int main(void)
{

    process();
    return 0;
}