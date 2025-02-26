#include <bits/stdc++.h>

#include "passengers.cpp"

using namespace std;

class TicketBook
{
public:
    static int aLB;
    static int aMB;
    
    static int aUB;
    static int aRAC;
    static int aWL;

    static vector<int> lBP;
    static vector<int> mBP;
    static vector<int> uBP;
    static vector<int> racBP;
    static vector<int> wlBP;

    static queue<int> wlList;
    static queue<int> racList;
    static vector<int> bookedTicketList;
    static unordered_map<int, Passenger> passenger_stored_data;

    void bookticket(Passenger &p, int snumber, string allotedberth)
    {
        p.number = snumber;
        p.alloted = allotedberth;
        passenger_stored_data[p.passengerid] = p;
        bookedTicketList.push_back(p.passengerid);

        cout << "Ticket Booked Successfully\n";
        cout << "Passenger ID : " << p.passengerid << endl;
        cout << "Passenger Name : " << p.name << endl;
        cout << "Passenger Age : " << p.age << endl;
        cout << "Passenger Gender :" << p.gender << endl;
        cout << "Alloted Berth : " << p.number << p.alloted << endl;
        cout << "\n";

        cout << "*******************Booked Successfully*******************\n";
    }

    void racticket(Passenger &p, int snumber, string racberth)
    {
        p.number = snumber;
        p.alloted = racberth;
        passenger_stored_data[p.passengerid] = p;
        racList.push(p.passengerid);

        cout << "Ticket Booked Successfully\n";
        cout << "Passenger ID : " << p.passengerid << endl;
        cout << "Passenger Name : " << p.name << endl;
        cout << "Passenger Age : " << p.age << endl;
        cout << "Passenger Gender :" << p.gender << endl;
        cout << "Alloted Berth : " << snumber << racberth << endl;

        cout << "\n";

        cout << "*******************RAC- Ticket Given *******************\n";
    }

    void waitlistticket(Passenger &p, int snumber, string wlberth)
    {
        p.number = snumber;
        p.alloted = wlberth;
        passenger_stored_data[p.passengerid] = p;
        wlList.push(p.passengerid);

        cout << "Passenger ID : " << p.passengerid << endl;
        cout << "Passenger Name : " << p.name << endl;
        cout << "Passenger Age : " << p.age << endl;
        cout << "Passenger Gender" << p.gender << endl;
        cout << "Alloted Berth : " << snumber << wlberth << endl;

        cout << "\n";

        cout << "******************You are in Waitlist*******************\n";
    }
    // ---------------------------------------------------------------------

    void passengersdetail()
    {
        if (passenger_stored_data.size() == 0)
        {
            cout << "No passengers details found\n";
            return;
        }
        else
        {
            for (auto it : passenger_stored_data)
            {
                cout << "Passenger ID : " << it.first << endl;
                cout << "Passenger Name : " << it.second.name << endl;
                cout << "Passenger Age : " << it.second.age << endl;
                cout << "Passenger Gender : " << it.second.gender << endl;
                cout << "Alloted Berth : " << it.second.number << it.second.alloted << endl;
            }
        }
    }

    void cancel(int cid)
    {
        
        cout << "------------------------------CANCELLED SUCCESSFULLY\n";

        Passenger p = passenger_stored_data[cid];
        passenger_stored_data.erase(cid);
        for (int i = 0; i < bookedTicketList.size(); i++)
        {
            if (bookedTicketList[i] == cid)
            {
                bookedTicketList.erase(bookedTicketList.begin() + i);
                break;
            }
        }

        int psnumber = p.number;

        if(p.alloted=="L"){
            lBP.push_back(psnumber);
            aLB++;
        }
        else if(p.alloted=="M"){
            mBP.push_back(psnumber);
            aMB++;
        }
        else if(p.alloted=="U"){
            uBP.push_back(psnumber);
            aUB++;
        }

        if (racList.size() > 0)
        {
            Passenger passengerfromRAC = passenger_stored_data[racList.front()];
           
            racList.pop();
            int pracnumber = passengerfromRAC.number;
            aRAC++;
            racBP.push_back(pracnumber);

            if (wlList.size() > 0)
            {
                Passenger passengerfromWL = passenger_stored_data[wlList.front()];
                int pwlnumber = passengerfromWL.number;
                wlList.pop();
                wlBP.push_back(pwlnumber);

                passengerfromWL.number = racBP[0];
                passengerfromWL.alloted = "RAC";
                racBP.erase(racBP.begin());
                racList.push(passengerfromWL.passengerid);
               

                aWL++;
                aRAC--;
            }
           bookticket(passengerfromRAC, racBP[0], "RAC");
        }

        
    }

    void availabletickets(){
        cout<<"Available Lower Berth : "<<aLB<<endl;
        cout<<"Available Middle Berth : "<<aMB<<endl;
        cout<<"Available Upper Berth : "<<aUB<<endl;
        cout<<"Available RAC : "<<aRAC<<endl;
        cout<<"Available Waiting List : "<<aWL<<endl;
    }
};

int TicketBook::aLB = 1;
int TicketBook::aMB = 1;
int TicketBook::aUB = 1;
int TicketBook::aRAC = 1;
int TicketBook::aWL = 1;

vector<int> TicketBook::lBP = {1};
vector<int> TicketBook::mBP = {1};
vector<int> TicketBook::uBP = {1};
vector<int> TicketBook::racBP = {1};
vector<int> TicketBook::wlBP = {1};

queue<int> TicketBook::wlList;
queue<int> TicketBook::racList;
vector<int> TicketBook::bookedTicketList;
unordered_map<int, Passenger> TicketBook::passenger_stored_data;
