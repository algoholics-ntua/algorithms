Find kth Algorithm

#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int arr[30];
int n;
cout<<"How many numbers do you want to add?\n";
cin>>n;
cout<<"Enter data : \n";
for(int j=0;j<n;j++)
{
cin>>arr[j];
}

int x;
cout<<"Enter the number to be searched\n";
cin>>x;

int i;
for(i=0;i<n;i++)
{
if(x==arr[i])
cout<<"Found at: "<<i+1;
}
if(i==n-1)
cout<<"Not found";
getch();
return 0;
}
