#include<stdio.h>
float f(float x,float y)
{
    return x+y;
}
int main(){
    float xx,h,x,y;
    printf("\nEnter x0,y0,h,xn: ");
    scanf("%f%f%f%f",&x,&y,&h,&xx);
    int n=(xx-x)/h;
    for(int i=0;i<n;i++){
        y=y+(h*(f(x,y)));
        x=x+h;
    }
    printf("%f\n",y);
    return 0;
}