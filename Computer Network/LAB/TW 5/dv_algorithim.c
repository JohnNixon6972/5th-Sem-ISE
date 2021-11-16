#include <stdio.h>
#include <stdlib.h>
#define nodes 10
int no;

struct Nodes
{
    int a[nodes][4];
} router[nodes];

void init(int r)
{
    int i;
    for (i = 1; i <= no; i++)
    {

        router[r].a[i][1] = i;
        router[r].a[i][2] = 999;
    }
    router[r].a[r][2] = 0;
    router[r].a[r][3] = r;
}

void inp(int r)
{

    int i;
    printf("/n Enter distance from node %d to other nodes", r);
    printf("/n Enter 999 if there is no direct route", r);

    for (i = 1; i <= no; i++)
    {
        if (i != r)
        {
            printf("/n Enter distance to the node %d:", i);
            scanf("%d", &router[r].a[i][2]);
            router[r].a[i][3] = i;
        }
    }
}
void display(int r)
{
    int i, j;
    printf("/n/n the routing table for node %d is as follows:", r);
    for (i = 1; i <= no; i++)
    {
        if (router[r].a[i][2] >= 999)
            printf("\n\t\t %d \t no link \t no hop", router[r].a[i][1]);
        else
            printf("\n\t\t %d \t %d \t\t d", router[r].a[i][1], router[r].a[i][2], router[r].a[i][3]);
    }
}
void dv_alog(int r)
{

    int i, j, z;
    for (i = 1; i <= no; i++)
    {
        if (router[r].a[i][2] != 999 && router[r].a[i][2] != 0)
            for (j = 1; j <= no; j++)
            {

                z = router[r].a[i][2] + router[r].a[j][2];
                if (router[r].a[j][2] > z)
                {
                    router[r].a[j][2] = z;
                    router[r].a[i][3] = i;
                }
            }
    }
}

int main()
{
    int i, j, x, y;
    char choice;
    printf("\nEnter no.of nodes required (less than 10 pls) :\n");
    scanf("%d", &no);
    for (i = 1; i <= no; i++)
    {
        init(i);
        inp(i);
    }
    printf("\n the configuration of nodes after initialization is as follows :");
    for (i = 1; i <= no; i++)
        display(i);
    for (i = 1; i <= no; i++)
        dv_alog(i);
    printf("\n the configuration of nodes after computation paths is as follows :");
    for (i = 1; i <= no; i++)
        display(i);

    while (1)
    {
        printf("\nEnter the nodes to find shortest path for them (Press 0 to exit)\n");
        scanf("%d %d", &x, &y);
        if (x == 0 || y == 0)
            break;
        else
            printf("\n The lenfgth of the shortest path is %d", router[x].a[y][2]);
    }
}