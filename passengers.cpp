#pragma once


#include <bits/stdc++.h>

using namespace std;

class Passenger
{

public:
    static int id;

    string name;
    int age;
    string gender;
    string bp;
    int passengerid;
    string alloted;
    int number;

    Passenger() : name(""), age(0), gender(""), bp(""),passengerid(0),alloted("") {}

    Passenger(string name, int age, string gender,string bp){
        this->name = name;
        this->age= age;
        this->gender = gender;
        this->bp = bp;
        this->passengerid = id++;
        alloted = "";
        number =-1;

    }
};

int Passenger::id = 1;

