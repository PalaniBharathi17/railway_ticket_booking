#include <bits/stdc++.h>
#include "passengers.cpp"
#include "ticketbook.cpp"

using namespace std;

void bookticket(Passenger &p)
{

    TicketBook tb;

    //---------------------------------------waitinglist-----------------------
    
    
   

    //----------------------------------BOOKING TICKET--------------------------
    if (((p.bp == "L")&& TicketBook::aLB > 0) || ((p.bp == "M ")&& TicketBook::aMB > 0) || ((p.bp == "U") && TicketBook::aUB > 0))
    {

        cout << "\n";

        if (p.bp == "L")
        {
            cout << "Lower Berth Alloted\n";
            tb.bookticket(p, TicketBook::lBP[0], "LB"); // bookticket function is called from ticketbook.cpp
            TicketBook::lBP.erase(TicketBook::lBP.begin());
            TicketBook::aLB--;
        }
        else if (p.bp == "M")
        {
            cout << "Middle Berth Alloted\n";
            tb.bookticket(p, TicketBook::mBP[0], "MB");
            TicketBook::mBP.erase(TicketBook::mBP.begin());
            TicketBook::aMB--;
        }
        else if (p.bp == "U")
        {
            cout << "Upper Berth Alloted\n";
            tb.bookticket(p, TicketBook::uBP[0], "UB");
            TicketBook::uBP.erase(TicketBook::uBP.begin());
            TicketBook::aUB--;
        }
   }
        //--------------------- -------------- AVALABLE TICKETS -----------------------
        else if (TicketBook::aLB > 0)
        {
            cout << "Lower Berth Alloted\n";
            tb.bookticket(p, TicketBook::lBP[0], "LB");
            TicketBook::lBP.erase(TicketBook::lBP.begin());
            TicketBook::aLB--;
        }
        else if (TicketBook::aMB > 0)
        {
            cout << "Middle Berth Alloted\n";
            tb.bookticket(p, TicketBook::mBP[0], "MB");
            TicketBook::mBP.erase(TicketBook::mBP.begin());
            TicketBook::aMB--;
        }
        else if (TicketBook::aUB > 0)
        {
            cout << "Upper Berth Alloted\n";
            tb.bookticket(p, TicketBook::uBP[0], "UB");
            TicketBook::uBP.erase(TicketBook::uBP.begin());
            TicketBook::aUB--;
        }
        else if(TicketBook::aRAC > 0)
        {
            cout << "RAC Berth Alloted\n";
            tb.racticket(p, TicketBook::racBP[0], "RAC");
            TicketBook::racBP.erase(TicketBook::racBP.begin());
            TicketBook::aRAC--;
        }
        else if(TicketBook:: aWL >0){
            cout<<"You are in waiting list\n";
            tb.waitlistticket(p, TicketBook::wlBP[0], "WL");
            TicketBook::wlBP.erase(TicketBook::wlBP.begin());
            TicketBook::aWL--;
        }
}

void cancelticket(int cid)
{
    TicketBook tb;

    if (TicketBook::passenger_stored_data.find(cid) == TicketBook::passenger_stored_data.end())
    {
        std::cout << "No such passenger id found\n";
        return;
    }
    else{
        tb.cancel(cid);
    }
}

int main()
{
    bool loop = true;
   
    while (loop)
    {

        cout << " 1.Book\n 2. Cancel\n 3.Available Tickets\n 4.Booked Tickets\n 5.Exit\n";
        TicketBook tb;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (TicketBook::aWL == 0)
            {
                cout << "No tickets Available\n";
                return 0;
            }
            else{
            cout << "Enter the passenger name : ";
            string name;
            getline(cin >> ws, name);

            cout << "Enter the passenger age : ";
            int age;
            cin >> age;
            cout << "Enter the passenger gender [M/F] : ";
            string gender;
            cin >> gender;
            cout << "Enter the berth preference [L/M/U] : ";
            string bp;
            cin >> bp;

            Passenger p(name, age, gender, bp);
            bookticket(p);
            break;
            }
        }

        case 2:
            // cout << "Cancelled\n";
            cout<<"Enter the passenger id to cancel the ticket\n";
            int cid;
            cin>>cid;
            cancelticket(cid);
            break;
        case 3:
            

           
            tb.passengersdetail();

            break;

        case 4:
            tb.availabletickets();
            break;
        case 5:
            loop = false;
            break;

        default:
            cout << "Invalid choice\n";
            break;
        }
    }
    return 0;
}