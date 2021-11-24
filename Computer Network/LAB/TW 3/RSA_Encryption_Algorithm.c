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

int mod(int x,int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    int p,q,n,e,m,c,d,x,z;
    int en[100],de[100], j = 0,fact_z[100];
    printf("\nEnter the value of p and q: ");
    scanf("%d%d", &p, &q);
    n = p*q;
    int cnt;
    cnt = 0;
    z = (p-1)*(q-1);
    for(int i = 1;i<z;i++){
        if(z%i == 0){
            printf("%d ",i);
            fact_z[cnt] = i;
            cnt++;  
        }
    }
    printf("Choose a value for e from a number which is not in list :: ");
    scanf("%d",&e);
    for(int i=0;i<cnt;i++){
        if(fact_z[i] == e|| gcd(e,z) != 1){
            printf("e belongs to the factors list get lost!!");
            return 0;
        }
    }
    printf("Enter the message(int) to be encrypted: ");
    scanf("%d", &m);
    printf("Before encryption: %d\n", m);
    c = mod(m, e, n);
    printf("After encryption: %d\n", c);
    d = z;

    cnt = 2;
    while (1){
        if(d%e == 0){
            break;
        }else{
            d = (cnt*z)+1;
            cnt++;
        }
    }
    d = d/e;
    printf("\n%d\n",d);
    x = mod(c, d, n);
    printf("After decryption: %d\n", x);

    return 0;
}
