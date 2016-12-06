#include "sorts.h"

void Algorithms::bubbleSort(int a[], int size)
{
  int i, j, tmp;
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (a[j] > a[j+1])
      {
        tmp = a[j+1];
        a[j+1] = a[j];
        a[j] = tmp;
      }
    }
  }
}

void Algorithms::modifiedBubbleSort(int a[], int size)
{
  int i, c, tmp;
  for (i = 0; i < size; i++)
  {
    for (c = 0; c < size-i; c++)
    {
      if (a[c] > a[c+1])
      {
        tmp = a[c];
        a[c] = a[c+1];
        a[c+1] = tmp;
      }
    }
  }
}

// merge function from geeks4geeks.com
void Algorithms::merge(int a[], int l, int m, int r)
{
  int i, j, k,
      n1 = m - l + 1,
      n2 = r - m,
      L[n1],
      R[n2];

  // Populate temp as.
  for (i = 0; i < n1; i++) L[i] = a[l+i];
  for (j = 0; j < n2; j++) R[j] = a[m+1+j];

  // Merge the temp as back into arr[l..r]
  i = 0; // Initial index of first suba
  j = 0; // Initial index of second suba
  k = l; // Initial index of merged suba

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      a[k] = L[i];
      i++;
    }
    else
    {
      a[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements in L and R if any.
  while (i < n1)
  {
    a[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    a[k] = R[j];
    j++;
    k++;
  }
}

// MergeSort from geeks4geeks.com
void Algorithms::mergeSort(int a[], int l, int r)
{
  if (l < r)
  {
    int m = l+(r-l)/2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
  }
}
