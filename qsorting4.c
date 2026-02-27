#include <stdio.h>
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high + 1;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] >= pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

            int temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
}
void quicks(int a[], int low, int high)
{
    int partitionInd; // ind of pivot after partition
    if (low < high)
    {
        partitionInd = partition(a, low, high);
        quicks(a, low, partitionInd); // sort left sub array
        quicks(a, partitionInd + 1, high);
    } // sort right sub array
}
int main()
{
    int a[] = {56, 8, 2, 99, 31, 28};
    int n = 6;
    printArray(a, n);
    quicks(a, 0, n - 1);
    printArray(a, n);
    return 0;
}