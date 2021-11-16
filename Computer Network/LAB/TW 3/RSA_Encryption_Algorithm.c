#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b)
{
    int c;
    while(a != b)
    {
        if(a < b)
        {
            c = a;
            a = b;
            b = c;
        }
        a -= b;
    }
    return a;
}

int mod(int m, int e, int n)
{
    int a = 1;
    while(e--)
    {
        a = (a*m) % n;
    }
    return a;
}

int main()
{
    int p,q,n,e,m,c,d,x,z;
    int en[100],de[100], j = 0;
    printf("\nEnter the value of p and q: ");
    scanf("%d%d", &p, &q);
    n = p*q;
    z = (p-1)*(q-1);
    for(e = 1; e < n; ++e)
    {
        if(gcd(e,z) == 1)
        {
            en[j] = e;
            printf(" %d", en[j++]);
        }
    }
    printf("\nchoose e: ");
    scanf("%d", &e);
    if(gcd(e,z) != 1)
    {
        printf("The value not from list");
        return 0;
    }
    printf("Enter the message(int) to be encrypted: ");
    scanf("%d", &m);
    printf("Before encryption: %d\n", m);
    c = mod(m, e, n);
    printf("After encryption: %d\n", c);
    for(d = 0; d < n; ++d)
    {
        if((d*e) % z == 1)
        {
            de[j] = d;
            printf("choose D: ");
            scanf("%d", &d);
            x = mod(c, d, n);
            printf("After decryption: %d\n", x);
            return 0;
        }
    }



    return 0;
}
