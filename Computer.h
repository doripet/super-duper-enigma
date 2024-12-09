#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

class Computer {
public:
    // Конструктор
    Computer(std::string cpu_brand, double cpu_clock, std::string motherboard,
             std::string harddrive, std::string videocard, double price, int store);
    
    // Деструктор
    ~Computer();

    // Поля класса
    std::string cpu_brand;
    double cpu_clock;
    std::string motherboard;
    std::string harddrive;
    std::string videocard;
    double price;
    int store;
};
//изменение строки ....))))(((
#endif // COMPUTER_H
