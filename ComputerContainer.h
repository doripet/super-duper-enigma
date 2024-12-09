#ifndef COMPUTERCONTAINER_H
#define COMPUTERCONTAINER_H

#include <vector>
#include <string>
#include <fstream>
#include "Computer.h"

class ComputerContainer {
private:
    std::vector<Computer> computers;

public:
    ComputerContainer();
    ~ComputerContainer();

    void addComputer(const Computer& computer);
    void removeComputer(int index);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
    void display() const;
    double totalCost() const;
    void findByCpuBrand(const std::string& brand) const;
    int getCount() const; // Новый метод
};

#endif // COMPUTERCONTAINER_H
