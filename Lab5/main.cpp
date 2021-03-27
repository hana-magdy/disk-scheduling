#include <iostream>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include <bits/stdc++.h>


using namespace std;


void FIFO(queue<int> Q,int HeadPosition, int NumberOfRequests)
{
    cout<<endl;
    cout <<"********************************************"<<endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << "FIFO Algorithm :" << endl;
    int last=HeadPosition;
    cout<< HeadPosition;
    int HeadMoves=0;
    for(int i=0; i<NumberOfRequests; i++)
    {
        int turn=Q.front();
        HeadMoves+=abs(last-turn);
        last=turn;
        cout << " -> "<<turn;
        Q.pop();
    }
    cout<<endl;
    cout <<"Total head movements ="<<HeadMoves <<endl;
    float avg=(float)HeadMoves/NumberOfRequests;
    cout <<"Average head movement ="<<avg<<endl;
    cout <<"********************************************"<<endl;


}



void SCAN(int *Input,int HeadPosition,int NumberOfRequests,int HeadDirection)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << "SCAN Algorithm :" << endl;
    sort(Input,Input + NumberOfRequests);
    int pivot=0;
    for(int i=0; i<NumberOfRequests; i++)
    {
        if(Input[i]>=HeadPosition)
        {
            pivot=i;
            break;
        }
    }
    cout<< HeadPosition;
    int start=pivot;
    if(HeadDirection==1)
    {

        int HeadMoves=0;
        int last=HeadPosition;
        if(Input[pivot]==HeadPosition)
        {
            start++;
        }
        for(int i=start; i<NumberOfRequests; i++)
        {
            int turn=Input[i];
            HeadMoves+=abs(last-turn);
            last=turn;
            cout << " -> "<<turn;
        }//reached the end
        last=HeadPosition;
        HeadMoves+=abs(Input[NumberOfRequests-1]-HeadPosition);
        for(int i=pivot-1; i>=0; i--)
        {
            int turn=Input[i];
            HeadMoves+=abs(last-turn);
            last=turn;
            cout << " -> "<<turn;
        }
        cout<<endl;
        cout <<"Total head movements ="<<HeadMoves <<endl;
        float avg=(float)HeadMoves/NumberOfRequests;
        cout <<"Average head movement ="<<avg<<endl;
        cout <<"********************************************"<<endl;

    }
    else //if direction isn't 1
    {
        int HeadMoves=0;
        int last=HeadPosition;
        if(Input[pivot]>=HeadPosition)
        {
            start--;
            // pivot--;
        }

        for(int i=start; i>=0; i--)
        {
            int turn=Input[i];
            HeadMoves+=abs(last-turn);
            last=turn;
            cout << " -> "<<turn;
        }//reached 0
        last=HeadPosition;
        HeadMoves+=abs(Input[0]-HeadPosition);
        if(HeadPosition==Input[pivot])
            pivot++;
        for(int i=pivot; i<NumberOfRequests; i++)
        {
            int turn=Input[i];
            HeadMoves+=abs(last-turn);
            last=turn;
            cout << " -> "<<turn;
        }
        cout<<endl;
        cout <<"Total head movements ="<<HeadMoves <<endl;
        float avg=(float)HeadMoves/NumberOfRequests;
        cout <<"Average head movement ="<<avg<<endl;
        cout <<"********************************************"<<endl;

    }

}


void CSCAN(int* Input,int HeadPosition,int NumberOfRequests,int HeadDirection)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << "C-SCAN Algorithm :" << endl;
    sort(Input,Input + NumberOfRequests);
    int pivot=0;
    for(int i=0; i<NumberOfRequests; i++)
    {
        if(Input[i]>=HeadPosition)
        {
            pivot=i;
            break;
        }
    }
    cout<< HeadPosition;
    int start=pivot;
    if(HeadDirection==1)
    {

        int HeadMoves=0;
        int last=HeadPosition;
        if(Input[pivot]==HeadPosition)
        {
            start++;
        }
        for(int i=start; i<NumberOfRequests; i++)
        {
            int turn=Input[i];
            HeadMoves+=abs(last-turn);
            last=turn;
            cout << " -> "<<turn;
        }//reached the end
        // last=HeadPosition;
        //HeadMoves+=abs(Input[NumberOfRequests-1]-HeadPosition);
        for(int i=0; i<pivot; i++)
        {
            int turn=Input[i];
            HeadMoves+=abs(last-turn);
            last=turn;
            cout << " -> "<<turn;
        }
        cout<<endl;
        cout <<"Total head movements ="<<HeadMoves <<endl;
        float avg=(float)HeadMoves/NumberOfRequests;
        cout <<"Average head movement ="<<avg<<endl;
        cout <<"********************************************"<<endl;

    }
    else //if direction isn't 1
    {
        int HeadMoves=0;
        int last=HeadPosition;
        if(Input[pivot]>=HeadPosition)
        {
            start--;

        }
        if(Input[pivot]==HeadPosition)
        {
            pivot++;
        }
        for(int i=start; i>=0; i--)
        {
            int turn=Input[i];
            HeadMoves+=abs(last-turn);
            last=turn;
            cout << " -> "<<turn;
        }//reached 0
        //last=HeadPosition;
        //HeadMoves+=abs(Input[0]-HeadPosition);
        //if()
        for(int i=NumberOfRequests-1; i>=pivot; i--)
        {
            int turn=Input[i];
            HeadMoves+=abs(last-turn);
            last=turn;
            cout << " -> "<<turn;
        }
        cout<<endl;
        cout <<"Total head movements ="<<HeadMoves <<endl;
        float avg=(float)HeadMoves/NumberOfRequests;
        cout <<"Average head movement ="<<avg<<endl;
        cout <<"********************************************"<<endl;

    }


}









int main()

{
    int DiskSize,NumberOfRequests,Temp,HeadPosition,HeadDirection;
    queue<int> Q;
    cout << "Enter the size of disk:" << endl;
    cin>>DiskSize;
    cout << "Enter number of requests:" << endl;
    cin>>NumberOfRequests;
    int Input[NumberOfRequests];
    cout << "Enter the requests:" << endl;
    for(int i=0; i<NumberOfRequests; i++)
    {
        cin >>Temp;
        Q.push(Temp);
        Input[i]=Temp;
    }
    cout << "Enter the head position:" << endl;
    cin>>HeadPosition;
    cout << "Enter the head direction:" << endl;
    cin>>HeadDirection;

    FIFO(Q,HeadPosition,NumberOfRequests);
    SCAN(Input,HeadPosition,NumberOfRequests,HeadDirection);
    CSCAN(Input,HeadPosition,NumberOfRequests,HeadDirection);




    //cout << "Hello world!" << endl;
    return 0;
}
