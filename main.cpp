#include <iostream>
using namespace std;
int getMinimum(int arr[], int n, bool Check[])
{
    int temp=999;
    int index;
    for(int i=0; i<n; i++)
    {
        if(temp>arr[i] && Check[i]==false)
        {
            temp=arr[i];
            index=i;
        }

    }
    return index;
}

int main()
{
    int *parent; /// to be printed at the end that shows the parent of each vertix
    bool *Check;
    int *minimumValues;
    int **graph; ///taking the input as an adjacency matrix
    int size;
    cout<<"enter the number of Vertices "<<endl;
    cin>>size;
    parent = new int[size];
    minimumValues = new int[size];
    Check = new bool[size];
    graph = new int*[size]; ///to dynamically allocate space in the memory for number of rows
    int min =0;
    cout<<" enter the adjacency matrix elements of the graph , if there is no edge put 999 " <<endl;
    for (int i = 0; i < size; i++)
    {
        Check[i]=false;
        minimumValues[i]=999;
        graph[i] = new int[size]; ///to dynamically allocate space in the memory for number of columns
        for (int j = 0; j < size; j++)
            cin>>graph[i][j];
    }
    minimumValues[0]=0;
    parent[0]=-2;
    for(int i=0 ; i< size; i++)
    {
        for(int j =0 ; j < size; j++)
        {
            if(graph[min][j]>0 && !Check[j] && graph[min][j]<minimumValues[j])
            {
                minimumValues[j]=graph[min][j];
                parent[j]=min;
            }
        }
        min=getMinimum(minimumValues, size, Check);
        Check[min]=true;

    }

    for( int i=0 ; i < size ; i++)
    {
        cout<<" vertex " <<i+1<<" parent is " <<parent[i]+1<<endl;

    }
    return 0;

}
/*
999 2 4 1 999 999 999
2 999 999 3 10 999 999
4 999 999 2 999 5 999
1 3 2 999 7 8 4
999 10 999 7 999 999 6
999 999 5 8 999 999 1
999 999 999 4 6 1 999 */
