#include <bits/stdc++.h>
using namespace std;
void countsort(int a[], int n)
{
    //Find the max element in a
    int Max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Max)
            Max = a[i];
    }
    int h[Max] = {0};
    //increment the correspodnding element in h array
    for (int i = 0; i < n; i++)
    {
        h[a[i]]++;
    }
    int i = 0;
    int j = 0; //sorting the value of from h to a
    while (i <= Max)
    {
        if (h[i] > 0)
        {
            a[j] = i;
            h[i]--;
            j++;
        }
        else //if in h value o then increment
            i++;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    countsort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}