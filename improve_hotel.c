#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/////////////////////////////////////////////////////////////////////////////////////
typedef struct Room
{
    int roomID;
    int status;
    char customerName[20];
}R;
/////////////////////////////////////////////////////////////////////////////////////
void listOccupiedRooms();
void assignRoom();
void removeRoom();
void findCustomer();
/////////////////////////////////////////////////////////////////////////////////////
struct Room R1[5];
int main()
{   
    int choice,k=1,status;
    for(int i=0;i<5;i++)
    {
        R1[i].status=0;
    }
    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n1: listOccupiedRooms()\n2: assignRoom()\n3: removeRoom()\n4: findCustomer()\n5: quit\n");
    while(k==1)
    {
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            listOccupiedRooms();
            break;
        case 2:
            assignRoom();
            break;
        case 3:
            removeRoom();
            break;
        case 4:
            findCustomer();
            break;
        case 5:
            exit(0);
        default:
            exit(0);
    }
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
void listOccupiedRooms()
{
    int counter2=0;
    printf("listOccupiedRooms():\n");
    for(int i=1;i<=5;i++)
    {
        if(R1[i].status==0)
        {
            counter2+=1;
            if(counter2==5)
            {
                printf("The hotel is empty\n");
                break;
            }
            continue;
        }
        else
        {
            counter2=0;
            break;
        }
    }
    for(int j=1;j<=5;j++)
    {
        if(R1[j].roomID>=1 && R1[j].roomID<=5)
        {
        printf("roomID: %d\n",R1[j].roomID);
        printf("customer name: %s\n",R1[j].customerName);
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////
void assignRoom()
{
    static int counter3=0;
    int a;
    printf("assignRoom():\n");
    for(int i=1;i<=5;i++)
    {
        if(R1[i].status==1)
        {
            if(i==5)
            {
                printf("The hotel is full\n");
                return;
            }
            continue;
        }
        break;
    }
    printf("Enter a roomID between 1 and 5:\n");
    scanf("%d",&a);
    R1[a].roomID=a;
    while(R1[a].roomID<1 || R1[a].roomID>5)
    {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d",&a);
        R1[a].roomID=a;
    }
    for(int i=1;i<=5;i++)
    {
        if(R1[i].roomID==R1[a].roomID && R1[a].status==1)
        {
            printf("Occupied! Enter another roomID\n");
            printf("Enter a roomID between 1 and 5:\n");
            scanf("%d",&a);
            R1[a].roomID=a;
            while(R1[a].roomID<1 || R1[a].roomID>5)
            {
                printf("Enter a roomID between 1 and 5:\n");
                scanf("%d",&a);
                R1[a].roomID=a;
            }
            continue;
        }
        else
        {
            if(i==5)
            {
                break;
            }
            continue;
        }
    }
    printf("Enter customer name:\n");
    scanf("\n%[^\n]",R1[a].customerName);
    printf("The room has been assigned successfully\n");
    R1[a].status=1;
}
/////////////////////////////////////////////////////////////////////////////////////
void removeRoom()
{
    int counter1=0,inp;
    printf("removeRoom():\n");
    for(int i=1;i<=5;i++)
    {
        if(R1[i].status==0)
        {
            counter1+=1;
            if(counter1==5)
            {
                printf("All the rooms are empty\n");
                return;
            }
            continue;
        }
        else
        {
            counter1=0;
            break;
        }
    }
    printf("Enter a roomID between 1 and 5:\n");
    scanf("%d",&inp);
    while(inp<1 || inp>5)
    {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d",&inp);
    }
    for(int j=1;j<=5;j++)
    {
        if(R1[j].roomID==inp)
        {
            R1[j].status=0;
            R1[j].status=-1;
            printf("Removal is successful\n");
            return;
        }
        else
        {
            if(j==5)
            {
            printf("Empty! Enter another roomID for removal\n");
            printf("Enter a roomID between 1 and 5:\n");
            scanf("%d",&inp);
            while(inp<1 || inp>5)
            {
            printf("Enter a roomID between 1 and 5:\n");
            scanf("%d",&inp);
            }
            j=1;
            continue;
            }
            continue;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////
void findCustomer()
{
    char inpa[20];
    int b;
    printf("findCustomer():\n");
    printf("Enter customer name:\n");
    scanf("\n%[^\n]",inpa);
    for(int i=1;i<=5;i++)
    {
        b=strcasecmp(R1[i].customerName,inpa);
        if(b==0)
        {
            printf("The target customer name is found\n");
            printf("roomID: %d\n",R1[i].roomID);
            printf("customer name: %s\n",R1[i].customerName);
            break;
        }
        else 
        {
            if(i==5)
            {
                printf("The target customer name is not found\n");
                return;
            }
            continue;
        }
    }
}