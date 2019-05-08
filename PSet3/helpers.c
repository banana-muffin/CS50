// Helper functions

#include <cs50.h>

#include "helpers.h"

// Returns true if value is in array of n values, else false
bool search(int value, int values[], int n) // Implements the binary search
{
    if (value < 0) // Check if value is a positive number
        return false;
    else
    {
        int start = 0; // The start of the array
        int end = n - 1; // The end of the array
        if (start > end) // If the first integer in the array is larger than the last integer in the array, it means that the value that is being searched is not in the array
            return false;
        else
        {
            while (start <= end)
            {
                int middle = (start + end)/2; // Calculate the middle point of the array
                if (values[middle] < value) // Check if the value is larger than the middle point
                {
                    start = middle + 1; // If the value is larger, move the start to the right of the middle point
                }
                else if (values[middle] == value) // Check if the value is the middle point (BINGO!)
                {
                    return true;
                    break;
                }
                else // If the value is smaller than the middle point
                {
                    end = middle - 1; // Move the start to the left of the middle point
                }
            }
        }
    }
    return false;
}

void sort(int values[], int n) // Implements the insertion sort
{
    for (int i = 1; i < n; i++) // Iterate over each integer in the array
    {
        int temp = values[i]; // Select the (next) unsortd element and save in temp
        int j = i; // int j holds the position where the unsorted element will be inserted
        while (j > 0 && temp < values[j-1]) // Check if previous element is larger than the element to be inserted
        // To sort elements in descending order, change temp < data[j] to temp > data[j]
        {
            values[j] = values[j-1]; // If the element is smaller, insert it before the element that is larger
            j--; //
        }
        values[j] = temp; //
    }
}
