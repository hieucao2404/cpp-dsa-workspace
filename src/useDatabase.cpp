#include <iostream>
#include "student.hpp"
#include "personal.hpp"
#include "database.hpp"

int main() {
    Database<Personal> db;
    db.run();
}