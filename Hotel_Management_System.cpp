#include <bits/stdc++.h>
#include <conio.h>
#define max 100
using namespace std;

class HotelMgnt;
class Customer
{
    
    protected:
    // char name[100];
    // char address[100];
    // char phone[12];
    // char from_date[20];
    // char to_date[20];
    string name;
    string address;
    string phone;
    string from_date;
    string to_date;
    float payment_advance;
    int booking_id;
    
};
class Room: public Customer
{
    
    protected:
    char type;
    char stype;
    char ac;
    int roomNumber;
    int rent;
    int status;
    friend class HotelMgnt;
    public:
    class Room addRoom(int);
    int searchRoom(int,bool);
    void deleteRoom(int);
    void displayRoom(Room);
};

class Room rooms[max];

int count1=0,count2=0;
Room Room::addRoom(int rno)
{
    Room room;
    room.roomNumber=rno;
    
    do
    {
    cout<<"\nType AC/Non-AC (A/N) : ";
    cin>>room.ac;
    }while(room.ac!='A' and room.ac!='N' and (cout<<"\nEnter valid Type\n"));
    
    do
    {
    cout<<"\nType Comfort (L/D) : ";
    cin>>room.type;
    }while(room.type!='L' and room.type!='D' and (cout<<"\nEnter valid Comfort\n"));
    
    do
    {
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
int Room::searchRoom(int rno, bool flag =0)
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
    
    if(flag) return found;
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
    return 0;
}

void Room::displayRoom(Room tempRoom)
{
    cout<<"\nRoom Number: \t"<<tempRoom.roomNumber;
    cout<<"\nType AC/Non-AC (A/N) "<<tempRoom.ac;
    cout<<"\nType Comfort (L/D) "<<tempRoom.type;
    cout<<"\nType Size (B/S) "<<tempRoom.stype;
    cout<<"\nRent: "<<tempRoom.rent;
}
class HotelMgnt
{
    public:
    void checkIn();
    void getAvailRoom();
    void searchCustomer(string);
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
            cout<<"\n Customer First Name : "<<rooms[i].name;
            cout<<"\n Room Number : "<<rooms[i].roomNumber;
            cout<<"\n Address (only city) : "<<rooms[i].address;
            cout<<"\n Phone : "<<rooms[i].phone;
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
        cin>>rooms[i].booking_id;
        cout<<"\nEnter Customer Name (First Name): ";
        cin>>rooms[i].name;
        cout<<"\nEnter Address (only city): ";
        cin>>rooms[i].address;
        cout<<"\nEnter Phone: ";
        cin>>rooms[i].phone;
        cout<<"\nEnter From Date: ";
        cin>>rooms[i].from_date;
        cout<<"\nEnter to Date: ";
        cin>>rooms[i].to_date;
        cout<<"\nEnter Advance Payment: ";
        cin>>rooms[i].payment_advance;
        rooms[i].status=1;
        cout<<"\n Customer Checked-in Successfully..";getch();
        
        ++count2;
    }
    else
    {
        
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
            rooms[i].displayRoom(rooms[i]);
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
void HotelMgnt::searchCustomer(string pname)
{
    int i,found=0;
    
    for(i=0;i<count1;i++)
    {
        if(rooms[i].status==1 && rooms[i].name == pname)
        {
            cout<<"\nCustomer Name: "<<rooms[i].name;
            cout<<"\nRoom Number: "<<rooms[i].roomNumber;
            found=1;
            getch();
            break;
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
        cout<<"\nCustomer Name : "<<rooms[i].name;
        cout<<"\nRoom Number : "<<rooms[i].roomNumber;
        cout<<"\nAddress : "<<rooms[i].address;
        cout<<"\nPhone : "<<rooms[i].phone;
        cout<<"\nTotal Amount Due : "<<billAmount<<" /";
        cout<<"\nAdvance Paid: "<<rooms[i].payment_advance<<" /";
        cout<<"\n*** Total Payable: "<<billAmount-rooms[i].payment_advance<<"/ only";
        rooms[i].status=0;
        --count2;
    }
    getch();
}
void manageRooms()
{
    Room room;
    int opt,rno,flag=0;
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
            flag = room.searchRoom(rno, 1);
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
     cout<<"|              Dipak Dabhi                       |\n";
     cout<<"|                                                |\n";
     cout<<" ------------------------------------------------\n";
};
int main()
{
    intro();
    
    class HotelMgnt hm;
    
    int opt;
    
    do
    {
        cout<<"\n\n ****___________Main Menu______________****\n";
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
                    string pname;
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
                    int  rno;
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
    
    return 0;
}
