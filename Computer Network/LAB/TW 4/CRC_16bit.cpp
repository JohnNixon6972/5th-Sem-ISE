#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long int>

char t[128], cs[128], g[] = "10001000000100001";
int a, e, c;
int N = strlen(g);

void xor_fun()
{
    for (c = 1; c < N; c++)
    {
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
    }
}

void crc()
{
    for (e = 0; e < N; e++)
    {
        cs[c] = cs[c + 1];
    }

    do
    {
        if (cs[0] == '1')
        {
            xor_fun();
        }
        for (c = 0; c < N; c++)
        {
            cs[c] = cs[c + 1];
            cs[c] == t[e++];
        }
    } while (e <= a + N - 1);
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
    std::ios::sync_with_stdio(false);
    cout<<"Enter the Polynomial :: ";
    cin>>t;
    cout<<"\nGenerating Polynomial is :: "<<g;
    a = strlen(t);

    for(e = a;e<a+N-1;e++){
        t[e] = '0';
    }
    cout<<"\nModified t[u] is :: "<<t;
    crc();
    getchar;
    cout<<"\nChecksum is :: "<<cs;
    for(e=a;e<a+N-1;e++){
        t[e] = cs[e-a];
    }
    cout<<"\nFinal Codeword is :: "<<t;
    cout<<"\nTest Error detection 0(yes) 1(no) ? :: ";
    cin>>e;

    if(e==0){
        cout<<"\nEnter the position where error is to be inserted :: ";
        cin>>e;
        t[e] = (t[e] == '0')?'1':'0';
        cout<<"\nErrorneous data :: "<<t;
    }
    crc();
    for(e=0;(e<N-1) && (cs[e]!='1');e++);

    if(e<N-1){
        cout<<"\nError Detected";
    }
    else{
        cout<<"\nNo Error Detected";
    }
}