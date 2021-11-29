#include <iostream>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>

using namespace std;

#define bucketSize 512

int random(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void bktInput(int a, int b)
{
    if (a > bucketSize)
        cout << "\n\t\tBucket overflow";
    else
    {
        Sleep(500);
        while (a > b)
        {
            cout << "\n\t\t" << b << " bytes outputted."<<"\t Remaining bytes "<<a;
            a -= b;
            Sleep(500);
        }
        if (a > 0)
            cout << "\n\t\tLast " << a << " bytes sent\t";
        cout << "\n\t\tBucket output successful";
    }
}

int main()
{
    int op, pktSize;
    // randomize();
    cout << "Enter output rate : ";
    cin >> op;
    for (int i = 1; i <= 5; i++)
    {
        Sleep(random(100,1000));
        pktSize = random(100,700);
        cout << "\nPacket no " << i << "\tPacket size = " << pktSize;
        bktInput(pktSize, op);
    }
    return 0;
}
