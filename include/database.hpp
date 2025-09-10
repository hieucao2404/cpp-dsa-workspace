#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#ifndef DATABASE_HPP
#define DATABASE_HPP

template<class T>
class Database{
    public:
    Database();
    void run();

    private:
    std::fstream database;
    char fName[20];
    std::ostream& print(std::ostream&);
    void add(T&);
    bool find(const T&);
    void modify(const T&);
    friend std::ostream& operator<<(std::ostream& out, Database& db){
        return db.print(out);
    }
};

template<class T>
Database<T>::Database() {
    std::cout << "File Name: ";
    std::cin >> fName;
}

template<class T>
void Database<T>::add(T& d){
    database.open(fName,std::ios::in|std::ios::out|std::ios::binary);
    database.seekp(0,std::ios::end);
    d.writeToFile(database);
    database.close();
}

template<class T>
void Database<T>::modify(const T& d) {
    T tmp;
    database.open(fName,std::ios::in|std::ios::out|std::ios::binary);
    while(!database.eof()){
        tmp.readFromFile(database);
        if(tmp == d){//over loaded ==
            std::cin >> tmp; //overloaded >>
            database.seekp(-d.size(),std::ios::cur);
            database.close();
            return;
        }
    }
    database.close();
    std::cout << "The record to be modified is not in the database \n";
}

template<class T>
bool Database<T>::find(const T& d){
    T tmp;
    database.open(fName,std::ios::in|std::ios::binary);
    while(!database.eof()){
        tmp.readFromFile(database);
        if (tmp == d) { //overloead ==
            database.close();
            return true;
        }
    }
    database.close();
    return false;
}

template<class T>
std::ostream& Database<T>::print(std::ostream& out){
    T tmp;
    database.open(fName,std::ios::in|std::ios::binary);
    while(1){
        tmp.readFromFile(database);
        if(database.eof())
            break;
        out << tmp << std::endl; //overloead <<
    }
    database.close();
    return out;
}

template<class T>
void Database<T>::run() {
    std::string option;
    T rec;
    std::cout << "1. Add 2. Find 3. Modify a record; 4. Exit\n";
    
    while (true){
        std::cout << "Enter an option: ";
        std::getline(std::cin, option);
        if(option == "1"){
            std::cin >> rec; 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            add(rec);
        }
        else if(option == "2"){
            rec.readKey();
            std::cout << "The record is ";
            if(!find(rec))
                std::cout << "not ";
            std::cout << "in the database\n";
        }
        else if(option == "3"){
            rec.readKey();
            modify(rec);
        }
        else if (option == "4")
            return;
        else 
            std::cout << "Wrong option\n";
        std::cout << *this;
    }
}


#endif