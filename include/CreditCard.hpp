#pragma once
#ifndef CREDIT_CARD_HPP
#define CREDIT_CARD_HPP

#include <string>
#include <iostream>

//constructor
class CreditCard {
    public: //constructor
    CreditCard(const std::string& no, const std::string& nm, int lim, double bal=0);

    std::string getNumber() const{
        return number;
    }

    std::string getName() const{
        return name;
    }

    double getBalance() const {
        return balance;
    }
    
    int getLimit() const {
        return limit;
    }

    bool chargelt(double price); // make a change
    void makePayment(double payment); // make a payment
    private: //private member data
    std::string number; // card number
    std::string name; // name
    int limit; //credit limit
    double balance; //balance
};

std::ostream& operator<<(std::ostream& out, const CreditCard& c);
#endif
