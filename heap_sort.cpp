#include<iostream>
#define MAX 10
using namespace std;

class heap_sort
{
    int arr[MAX],i,n;

    public:
            heap_sort()
            {
                for(int i=0;i<MAX;i++)
                    arr[i] = 0;
            }

            void get();
            void print(int n);
            void heapsort(int choice);
            void maxheap(int n, int i);
            void minheap(int n, int i);
};

void heap_sort :: get()
{
    cout<<"\n ENTER NUMBER OF ELEMENTS : ";
    cin>>n;
    cout<<"\nENTER ELEMENTS : \n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}

void heap_sort :: maxheap(int n, int i)
{
    int largest = i;
    int l = (2*i)+1;
    int r = (2*i)+2;

    if(l<n && arr[l] > arr[largest])
        largest = l;

    if(r<n && arr[r] > arr[largest])
        largest = r;

    if( largest != i)
    {
        swap(arr[i], arr[largest]);
        maxheap(n, largest);
    }
}

void heap_sort :: minheap(int n, int i)
{
    int smallest = i;
    int l = (2*i)+1;
    int r = (2*i)+2;

    if(l<n && arr[l] < arr[smallest])
        smallest = l;

    if(r<n && arr[r] < arr[smallest])
        smallest = r;

    if( smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minheap(n, smallest);
    }
}


void heap_sort :: heapsort(int choice)
{
    for(i = (n/2)-1; i >= 0; i--)
    {
        if(choice == 1)
            maxheap(n, i);
        else
            minheap(n, i);
    }

    for(i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        if(choice == 1)
            maxheap(i, 0);
        else
            minheap(i, 0);
    }

    print(n);
}

void heap_sort :: print(int n)
{
    cout<<"\nDISPLAYING ELEMENTS : \n";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"\n";
    }
}

int main()
{
    heap_sort h;
    h.get();
    h.heapsort(2);
    return 0;
}
