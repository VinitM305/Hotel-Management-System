#include<iostream>
#include<string.h>
#include<conio.h>
#include <bits/stdc++.h>
#define max 100
using namespace std;
class Customer
{
    
    public:
    
    char name[100];
    char address[100];
    char phone[12];
    char from_date[20];
    char to_date[20];
    float payment_advance;
    int booking_id;
    
};

class Room
{
    
    public:
    char type;
    char stype;
    char ac;
    int roomNumber;
    int rent;
    int status;
    class Customer cust;
    class Room addRoom(int);
    void searchRoom(int);
    void deleteRoom(int);
    void displayRoom(Room);
    
};

class Room rooms[max];

int count1=0,count2=0;

Room Room::addRoom(int rno)
{
    Room room;
    room.roomNumber=rno;
    
    do{
    cout<<"\nType AC/Non-AC (A/N) : ";
    cin>>room.ac;
    }while(room.ac!='A' and room.ac!='N' and (cout<<"\nEnter valid Type\n"));
    
    do{
    cout<<"\nType Comfort (L/D) : ";
    cin>>room.type;
    }while(room.type!='L' and room.type!='D' and (cout<<"\nEnter valid Comfort\n"));
    
    do{
    cout<<"\nType Size (B/S) : ";
    cin>>room.stype;
    }while(room.stype!='B' and room.stype!='S' and (cout<<"\nEnter valid size\n"));
    
    cout<<"\nDaily Rent : ";
    cin>>room.rent;
    room.status=0;
    cout<<"\n Room Added Successfully!";
    getch();
    return room;
}

void Room::searchRoom(int rno)
{
    int i,found=0;
    for(i=0;i<count1;i++)
    {
        if(rooms[i].roomNumber==rno)
        {
            found=1;
            break;
        }
        
    }
    if(found)
    {
        cout<<"Room Details\n";
        if(rooms[i].status==1)
        {
            cout<<"\nRoom is Reserved";
        }
        else
        {
            cout<<"\nRoom is available";
            
        }
        displayRoom(rooms[i]);
        getch();
    }
    else
    {
        cout<<"\nRoom not found";
        getch();
    }
}

void Room::displayRoom(Room tempRoom)
{
    cout<<"\nRoom Number: \t"<<tempRoom.roomNumber;
    cout<<"\nType AC/Non-AC (A/N) "<<tempRoom.ac;
    cout<<"\nType Comfort (L/D) "<<tempRoom.type;
    cout<<"\nType Size (B/S) "<<tempRoom.stype;
    cout<<"\nRent: "<<tempRoom.rent;
}

class HotelMgnt:protected Room
{
    public:
    void checkIn();
    void getAvailRoom();
    void searchCustomer(char *);
    void checkOut(int);
    void guestSummaryReport();
};
void HotelMgnt::guestSummaryReport()
{
    if(count2==0)
    {
        cout<<"\n No Guest in Hotel !!";
    }
    for(int i=0;i<count1;i++)
    {
        if(rooms[i].status==1)
        {
            cout<<"\n Customer First Name : "<<rooms[i].cust.name;
            cout<<"\n Room Number : "<<rooms[i].roomNumber;
            cout<<"\n Address (only city) : "<<rooms[i].cust.address;
            cout<<"\n Phone : "<<rooms[i].cust.phone;
            cout<<"\n---------------------------------------";
        }
    }
    getch();
}
void HotelMgnt::checkIn()
{
    int i,found=0,rno;
    class Room room;
    
    start :{};
    
    cout<<"\nEnter Room number : ";
    cin>>rno;
    for(i=0;i<count1;i++)
    {
        if(rooms[i].roomNumber==rno)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        if(rooms[i].status==1)
        {
            cout<<"\nRoom is already Booked";
            getch();
            return;
        }
        cout<<"\nEnter booking id: ";
        cin>>rooms[i].cust.booking_id;
        cout<<"\nEnter Customer Name (First Name): ";
        cin>>rooms[i].cust.name;
        cout<<"\nEnter Address (only city): ";
        cin>>rooms[i].cust.address;
        cout<<"\nEnter Phone: ";
        cin>>rooms[i].cust.phone;
        cout<<"\nEnter From Date: ";
        cin>>rooms[i].cust.from_date;
        cout<<"\nEnter to Date: ";
        cin>>rooms[i].cust.to_date;
        cout<<"\nEnter Advance Payment: ";
        cin>>rooms[i].cust.payment_advance;
        rooms[i].status=1;
        cout<<"\n Customer Checked-in Successfully..";getch();
        
        ++count2;
        
    }else{
        
        cout<<"\nEnter existing room no.\n";
        
        goto start;
    }
    
}
void HotelMgnt::getAvailRoom()
{
    
    int i,found=0;
    for(i=0;i<count1;i++)
    {
        if(rooms[i].status==0)
        {
            displayRoom(rooms[i]);
            cout<<"\n\nPress enter for next room";
            found=1;
            getch();
        }
    }
    if(found==0)
    {
        cout<<"\nAll rooms are reserved";
        getch();
    }
}
void HotelMgnt::searchCustomer(char *pname)
{
    int i,found=0;
    for(i=0;i<count1;i++)
    {
        if(rooms[i].status==1 && strcmp(rooms[i].cust.name,pname)==0)
        {
            cout<<"\nCustomer Name: "<<rooms[i].cust.name;
            cout<<"\nRoom Number: "<<rooms[i].roomNumber;
            cout<<"\n\nPress enter for next record";
            found=1;
            getch();
        }
    }
    if(found==0)
    {
        cout<<"\nPerson not found.\n";
        getch();
    }
}
void HotelMgnt::checkOut(int roomNum)
{
    int i,found=0,days,rno;
    float billAmount=0;
    for(i=0;i<count1;i++)
    {
        if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        cout<<"\nEnter Number of Days:\t";
        cin>>days;
        billAmount=days * rooms[i].rent;
        cout<<"\n\t######## CheckOut Details ########\n";
        cout<<"\nCustomer Name : "<<rooms[i].cust.name;
        cout<<"\nRoom Number : "<<rooms[i].roomNumber;
        cout<<"\nAddress : "<<rooms[i].cust.address;
        cout<<"\nPhone : "<<rooms[i].cust.phone;
        cout<<"\nTotal Amount Due : "<<billAmount<<" /";
        cout<<"\nAdvance Paid: "<<rooms[i].cust.payment_advance<<" /";
        cout<<"\n*** Total Payable: "<<billAmount-rooms[i].cust.payment_advance<<"/ only";
        rooms[i].status=0;
    }
    getch();
}
void manageRooms()
{
    Room room;
    int opt,rno,i,flag=0;
    char ch;
    do
    {
        
        cout<<"\n### Manage Rooms ###";
        cout<<"\n1. Add Room";
        cout<<"\n2. Search Room";
        cout<<"\n3. Back to Main Menu";
        cout<<"\n\nEnter Option: ";
        cin>>opt;
        switch(opt)
        {
            case 1:
            top:{};
            cout<<"\nEnter Room Number: ";
            cin>>rno;
            i=0;
            for(i=0;i<count1;i++)
            {
                if(rooms[i].roomNumber==rno)
                {
                    flag=1;
                }
                
            }
            if(flag==1)
            {
                cout<<"\nRoom Number is Present. Please enter unique Number\n";
                flag=0;
                goto top;
                getch();
            }
            else
            {
                rooms[count1]=room.addRoom(rno);
                count1++;
            }
            break;
            case 2:
            cout<<"\nEnter room number: ";
            cin>>rno;
            room.searchRoom(rno);
            break;
            case 3:
            break;
            default:
            cout<<"\nPlease Enter correct option";
            break;
        }
    }while(opt!=3);
}


void intro()
{
    
     cout<<" ------------------------------------------------\n";
     cout<<"|                                                |\n";
     cout<<"|     ######## Hotel Management #########        |\n";
     cout<<"|              Team Size : 2                     |\n";
     cout<<"|              Members Name :                    |\n";
     cout<<"|              Vinit Mehta                       |\n";
     cout<<"|              Dabhi Dipak                       |\n";
     cout<<"|                                                |\n";
     cout<<" ------------------------------------------------\n";
};


int main()
{
    intro();
    class HotelMgnt hm;
    int i,j,opt,rno;
    char ch;
    char pname[100];
    
    do
    {
        cout<<"\n ****____________Main Menu_______________****\n";
        cout<<"\n1. Manage Rooms";
        cout<<"\n2. Check-In Room";
        cout<<"\n3. Available Rooms";
        cout<<"\n4. Search Customer";
        cout<<"\n5. Check-Out Room";
        cout<<"\n6. Guest Summary Report";
        cout<<"\n7. Exit";
        cout<<"\n\nEnter Option: ";
        cin>>opt;
        switch(opt)
        {
            case 1:
            
                manageRooms();
                break;
                
            case 2:
            
                if(count1==0)
                {
                    cout<<"\nRooms data is not available. Please add the rooms first.\n";
                    getch();
                }
                else
                hm.checkIn();
                break;
                
            case 3:
            
                if(count1==0)
                {
                    cout<<"\nRooms data is not available. Please add the rooms first.\n";
                    getch();
                }
                else
                hm.getAvailRoom();
                break;
                
            case 4:
            
                if(count2==0)
                {
                    cout<<"\nThere are no customers\n";
                    getch();
                }
                else
                {
                    cout<<"Enter Customer Name: ";
                    cin>>pname;
                    hm.searchCustomer(pname);
                }
                break;
                
            case 5:
            
                if(count1==0)
                {
                    cout<<"\nRooms are not available. Please add the rooms first.\n";
                    getch();
                }
                else
                {
                    cout<<"Enter Room Number : ";
                    cin>>rno;
                    hm.checkOut(rno);
                }
                break;
                
            case 6:
            
                hm.guestSummaryReport();
                break;
                
            case 7:
            
                cout<<"\nTHANK YOU! \n";
                break;
                
            default:
            
                cout<<"\nPlease Enter correct option";
                break;
                
        }
        
    }while(opt!=7);
    
    getch();
}
    
    
        
        
        
