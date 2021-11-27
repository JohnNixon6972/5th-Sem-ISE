#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long int>

void BellmanFord(int network[3][3], int routers, int connections, int source, int arr[3][3])
{
    int dist[routers];
    for (int i = 0; i < routers; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    for (int i = 0; i < routers - 1; i++)
    {
        for (int j = 0; j < connections; j++)
        {
            if (dist[network[j][0]] != INT_MAX && dist[network[j][0]] + network[j][2] < dist[network[j][1]])
                dist[network[j][1]] = dist[network[j][0]] + network[j][2];
        }
    }

    // cout << "Router Distance from Source-router " << source + 1 << endl;
    for (int i = 0; i < routers; i++)
    {
        arr[source][i] = min(arr[source][i], dist[i]);
        arr[i][source] = min(arr[source][i], dist[i]);
        // cout << i + 1 << "\t\t" << dist[i] << endl;
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif

    std::ios::sync_with_stdio(false);
    int routers;
    cout << "Enter the number of routers :: ";
    cin >> routers;
    int connections;
    cout << "Enter the number of connections :: ";
    cin >> connections;
    int s, d, hc;
    int network[3][3];
    int arr[3][3];
    for (int i = 0; i < routers; i++)
    {
        for (int j = 0; j < routers; j++)
        {
            network[i][j] = INT_MAX;
        }
    }
    cout << "Enter " << connections << " details in (source_router,destination_router,hop_cost) format " << endl;
    for (int i = 0; i < connections; i++)
    {
        cin >> s >> d >> hc;
        network[s - 1][d - 1] = hc;
        network[d - 1][s - 1] = hc;
        // cout << network[d - 1][s - 1];
        // cout << network[s - 1][d - 1];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = INT_MAX;
        }
    }
    int choice;
    while (1)
    {
        cout << "Do you want to compute the shortest hops ? press 1 to compute ,any other character to exit :: ";
        cin >> choice;
        if (choice == 1)
        {
            int src;
            cout << "Enter the source router to compute the shortest hops to other routers :: ";
            cin>>src;
            BellmanFord(network, routers, connections, src-1, arr);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}