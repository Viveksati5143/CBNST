#include<stdio.h>
#include<math.h>
#define f(x) 1/(1+x*x)

int main()
{
    int n;
    float i, a, b, integration=0, h;
    int p=1;
    printf("Enter lower and upper limit of integration: ");
    scanf("%f%f", &a, &b);
    printf("Enter number of sub intervals: ");
    scanf("%d", &n);
    h = (b - a)/n;
    integration = f(a) + f(b);

    for(i=a+h; i< b; i+=h){
    if(p%3 == 0) integration += 2*f(i);
    else integration += 3 * f(i);
    p++;
    }
    integration = (3 * h)/8*integration;
    printf("\nRequired value of integration is: %f", integration);
    return 0;
}