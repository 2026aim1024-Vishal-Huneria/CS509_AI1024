#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100000


void printArray(int arr[], int sz)
{
    for(int i=0;i<sz;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}


int main()
{
     int choice;
    string fileName;

    cout << "1. Run Test 01\n";
    cout << "2. Run Test 02\n";
    cout << "3. Run Test 03\n";
    cout << "4. Run Test 04\n\n";

    cout << "Enter Choice : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
    fileName = "tests/graph_test_01.txt";
    break;

case 2:
    fileName = "tests/graph_test_02.txt";
    break;

case 3:
    fileName = "tests/graph_test_03.txt";
    break;

case 4:
    fileName = "tests/graph_test_04.txt";
    break;

        default:
            cout << "Invalid Choice\n";
            return 0;
    }

    ifstream fin(fileName);

    if(!fin)
    {
        cout << "Cannot open file\n";
        return 0;
    }



    int vertices, edges;

    fin>>vertices>>edges;



    // adjacency list

    map<int, vector<pair<int,int>>> graph;



    for(int i=0;i<vertices;i++)
    {

        int vertex,outDegree;

        fin>>vertex>>outDegree;


        for(int j=0;j<outDegree;j++)
        {

            int neighbor,weight;

            fin>>neighbor>>weight;


            graph[vertex].push_back({neighbor,weight});

        }

    }



    // CSR arrays

    int offset[MAX_SIZE];

    int intermediate[MAX_SIZE];

    int property[MAX_SIZE];



    fill(offset,offset+MAX_SIZE,-1);

    fill(intermediate,intermediate+MAX_SIZE,0);

    fill(property,property+MAX_SIZE,0);



    int pos=0;



    // Convert adjacency list to CSR

    for(int i=0;i<vertices;i++)
    {

        offset[i]=pos;


        for(int j=0;j<graph[i].size();j++)
        {

            intermediate[pos]=graph[i][j].first;

            property[pos]=graph[i][j].second;


            pos++;

        }

    }



    // last position stores total edges

    offset[vertices]=pos;



    cout<<"CSR Representation"<<endl;

    cout<<endl;


    cout<<"Offset : ";

    printArray(offset,vertices+1);



    cout<<"Intermediate : ";

    printArray(intermediate,pos);



    cout<<"Property : ";

    printArray(property,pos);



    return 0;

}