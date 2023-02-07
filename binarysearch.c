#include<stdio.h>
void main()
{
int num,n,i,mid,l,f;
    printf("SUDHANSHU SHEKHAR PANDEY\nIT-2C\n2100320130172\n");
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter Sorted array\n");
    for(i=0;i<n;i++)
    {scanf("%d",&a[i]);}
    printf("Enter number to be searched\n");
    scanf("%d",&num);
    f=0;l=n-1;
    mid=(f+l)/2;
    while(f<=l)
    {
    if(a[mid]==num)
    {printf("Number found at %d location",mid+1);
     break;
    }
    else if(num>a[mid])
    {f=mid+1;}
    else if(num<a[mid])
    {l=mid-1;}
    mid=(f+l)/2;
    }
    if(f>l){printf("Number not found");}
}
