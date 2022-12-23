#include<stdio.h>
#include<math.h>
#define f(x) 1/(1+pow(x,2))

int main(){
    int n;
    float i, a, b, integration=0, h;

    printf("Enter lower and higher limit of integration: ");
    scanf("%f%f" ,&a, &b);
    printf("Enter number of sub intervals: ");
    scanf("%d", &n);

    h = (b - a)/n;
    integration = f(a) + f(b);

    for(i=a+h; i<b; i+=h)  integration += 2 * f(i);
    
    integration = (integration * h)/2;
    printf("\nRequired value of integration is: %f", integration);
    return 0;
}