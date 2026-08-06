#include <stdio.h>
#include <stdlib.h>

int main0()
{
    printf("Hello world!\n");

    int i,a[5],large = 0,n;
    printf("Enter n value: ");
    scanf("%d",&n);

    printf("Enter arr elements: ");
    for(i = 0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
        if(a[i]>large)
            large = a[i];

    printf("large element is: %d",large);

    return 0;
}
