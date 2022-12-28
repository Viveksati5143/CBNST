#include<stdio.h>
#include<math.h>
#include<string.h>

float fun(float,float);

int main(){
    int i,j,c;
    float x[100],y[100],h,m[100],m1,m2,a,s[100],w;
    printf("\n     C program for Modified Euler Method \n\n");
    printf("  Enter the initial value of x:");
    scanf("%f",&x[0]);
    printf("\n  Enter the value of increment h:");
    scanf("%f",&h);
    printf("\n  Enter the final value of x:");
    scanf("%f",&a);
    printf("\n  Enter the initial value of the variable y :");
    scanf("%f",&y[0]);
    s[0]=y[0];
    for(i=1;x[i-1]<a;i++){
        w=100.0;
        x[i]= x[i-1]+h;
        m[i]=fun(x[i-1],y[i-1]);
        c=0;
        while(w>0.0001){
            m1=fun(x[i],s[c]);
            m2=(m[i]+m1)/2;
            s[c+1]=y[i-1]+m2*h;
            w=s[c]-s[c+1];
            w=fabs(w);
            c=c+1;
        }
        y[i]=s[c];
    }
    printf("\n\n The respective values of x and y are\n     x  \t     y\n\n");
    for(j=0;j<i;j++){
        printf("  %f\t%f",x[j],y[j]);
        printf("\n");
    }
}
float fun(float a,float b){
    float c;
    c=a*a+b;
    return(c);
}