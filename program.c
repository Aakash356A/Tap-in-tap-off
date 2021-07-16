#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct bill // structure declaration
{
    int distance;
    int balance;
    int fare;
    char source[50];
    char destination[50];
};

int input() // function to accept boarding point
{
    int m;
    printf("Enter boarding point code\n");
    printf("1.sion 2.dadar 3.parel 4.dadar plaza 5.shivaji park 6.mahim 7.worli 8.green park\n");
     scanf("%d",&m);

    return m;
}

int input2() // function to accept stopping point
{
    int n;
    printf("Enter stopping point code\n");
    printf("1.sion 2.dadar 3.parel 4.dadar plaza 5.shivaji park 6.mahim 7.worli 8.green park\n");
    scanf("%d",&n);
    return n;

}
int renew(int balance)
{
return balance-50;
}

int bcal(int fare,int *balance,int k) // function to calculate balance
{
    balance[k]=balance[k]-fare;
    return balance[k];
}


int fcal(int distance,int i,int balance[]) // function to calculate fare
{
    int f;

    char concession[10]={'y','y','n','n','y','n','n','y','n','y'}; // character array for concession details
    f=distance*5;
    if(concession[i]=='y')
        f=f/2;
    if(f>balance[i])
        printf("Not enough balance\n");

    return f;
}

int main()
{

    int a,flag=0,i,s,d,distance=0,fare,b;
     int z,y;
    struct bill w;
 int balance[10]={5000,100,4000,50,10000,800,800,856,569,999};
int validity[10] = {2019,2018,2019,2019,2019,2019,2019,2018,2019,2019};
    int ID[10]={1,2,3,4,5,6,7,8,9,10};



for(z=1;z<=10;z++)
    {

    flag=0;

    printf("Welcome to Tap in/Tap off system\n\n");



ask:
printf("Please tap in card\n");

    while(flag!=1) // to check weather entered card is valid or not
    {
  a=0;
    printf("Enter ID number\n");
    scanf("%d",&a);
    for(i=0;i<10;i++)
    {

        if(a==ID[i])
            {
                flag=1;
            break;
            }
    }
if(flag==0)
       {

        printf("Invalid ID\n\n");
        goto ask;
       }
     }
     if (validity[i] != 2019)
{
char ch2;
printf("\nThe card is expired !\nAccess Denied!\nRenewal cost for one year : 50\nDo you want to renew the validity ?[y/n] : \n");
scanf(" %c",&ch2);
if (ch2=='y')
{
balance[i]=renew(balance[i]);
printf("New balance is:%d \n\n",balance[i]);

validity[i]=validity[i]+1;


}
        else
{
exit(0);
}
}
y=0;
     printf("1.Book ticket\n2.Check balance\n3.Fare calculator\n\n");
    scanf("%d",&y);

    if(y==1) //reservation of ticket
    {

    flag=0;


     char *c[][10]={"Sion","Dadar","Parel","Dadar plaza","Shivaji park","Mahim","Worli","Green park"};
     s=input();



     d=input2();

      distance=(d-s)*5;
      w.distance=distance;
       printf("Total distance covered is %d kms\n\n",w.distance);


      fare=fcal(distance,i,balance);
      w.fare=fare;
      printf("Fare is %d\n",w.fare);
      w.balance=bcal(fare,balance,i);

      printf("***********TICKET SUMMARY************\n\n");// bill summary

      printf(" SOURCE: %s\n DESTINATION: %s\n DISTANCE: %d \n FARE: %d \n BALANCE REMAINING: %d\n\n",c[0][s-1],c[0][d-1],w.distance,w.fare,w.balance);






      goto ask;

    }




    else if(y==2) // balance checker
    {
        printf("Your balance is %d\n\n",balance[i]);
flag=0;
goto ask;

    }
    else if(y=3) // fare calculator
    {

       s=input();
       d=input2();
       fare=(d-s)*5*10;
       printf("Fare is %d\n\n",fare);
       flag=0;
       goto ask;
    }


}

    }
