#include "database.hpp"

template<class T>
Database<T>::Database(){
    cout << "File name: ";
    cin >> fName;
}

template<class T>
void Database<T>::add(T& d){
    database.open(fName,ios::in|ios::out|ios::binary);
    database.seekp(0,ios::end);
    d.writeToFile(database);
    database.close();
}


template<class T>
void Database<T>::modify(const T& d){
    T tmp;
    database.open(fName,ios::in|ios::out|ios::binary);
    while (!database.eof()) {
        tmp.readFromFile(database);
        if(tmp == d){
            cin >> tmp;
            database.seekp(-d.size(),ios::cur);
            tmp.writeToFile(database);
            database.close();
            return;
        }
    }
    database.close();
    cout << "The record to be modified is not in the database\n";
}

template<class T>
bool Database<T>::find(const T& d){
    T tmp;
    database.open(fName,ios::in|ios::binary);
    while(!database.eof()){
        tmp.readFromFile(database);
        if(tmp == d){
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
    database.open(fName, ios::in|ios::binary);
    while(1) {
        tmp.readFromFile(database);
        if(database.eof())
            break;
        out << tmp << endl;
    }
    database.close();
    return out;
}