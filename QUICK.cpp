#include<iostream>
using namespace std;

int partition(int array[], int no, int s, int e)
{
    int i, j;
    int pivot = array[s];
    i = s + 1;
    j = no - 1;

    while (i <= j)
    {
        while (i <= e)
        {
            if (array[i] < pivot)
            {
                i++;
            }
            else
            {
                break;
            }
        }

        while (j > s)
        {
            if (array[j] > pivot)
            {
                j--;
            }
            else
            {
                break;
            }
        }

        if (i < j)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    swap(array[s], array[j]);
    return j;
}

int quicksort(int arr[], int n, int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, n, s, e);
        quicksort(arr, n, s, p - 1);
        quicksort(arr, n, p + 1, e);
    }
    return 0; // Ensuring proper return from the quicksort function
}

int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int arr[n];
    
    cout << "Enter the array elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = 0;
    int e = n - 1;

    cout << "The original array is:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    quicksort(arr, n, s, e);

    cout << "The sorted array is  :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}

