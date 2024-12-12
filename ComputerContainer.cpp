#include "ComputerContainer.h"
#include <iostream>
//добавить конструктор 
ComputerContainer::ComputerContainer() {}

ComputerContainer::~ComputerContainer() {}

void ComputerContainer::addComputer(const Computer& computer) {
    computers.push_back(computer);
}
//добавление функций
void ComputerContainer::removeComputer(int index) {
    if (index >= 0 && index < computers.size()) {
        computers.erase(computers.begin() + index);
        std::cout << "Компьютер удалён." << std::endl;
    } else {
        std::cerr << "Индекс вне диапазона!" << std::endl;
    }
}
//111коммит...)(
//проверка открытия файла
void ComputerContainer::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return;
    }

    std::string cpu_brand, motherboard, harddrive, videocard;
    double cpu_clock, price;
    int store;

    while (file >> cpu_brand >> cpu_clock >> motherboard >> harddrive >> videocard >> price >> store) {
        computers.emplace_back(cpu_brand, cpu_clock, motherboard, harddrive, videocard, price, store);
    }

    file.close();
}

void ComputerContainer::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return;
    }

    for (const auto& computer : computers) {
        file << computer.cpu_brand << " "
             << computer.cpu_clock << " "
             << computer.motherboard << " "
             << computer.harddrive << " "
             << computer.videocard << " "
             << computer.price << " "
             << computer.store << "\n";
    }

    file.close();
}
//функция вывода на экран

void ComputerContainer::display() const {
    for (size_t i = 0; i < computers.size(); ++i) {
        const auto& computer = computers[i];
        std::cout << i + 1 << ". Марка процессора: " << computer.cpu_brand 
                  << ", Тактовая частота: " << computer.cpu_clock 
                  << ", материнская плата: " << computer.motherboard 
                  << ", жесткий диск: " << computer.harddrive 
                  << ", видеокарта: " << computer.videocard 
                  << ", цена: " << computer.price 
                  << ", количество на складе: " << computer.store 
                  << "\n";
    }
}


double ComputerContainer::totalCost() const {
    double total = 0;
    for (const auto& computer : computers) {
        total += computer.price * computer.store;
    }
    return total;
}

void ComputerContainer::findByCpuBrand(const std::string& brand) const {
    for (const auto& computer : computers) {
        if (computer.cpu_brand == brand) {
            std::cout << "НАЙДЕН: " << computer.cpu_brand 
                      << ", Тактовая частота: " << computer.cpu_clock 
                      << ", материнская плата: " << computer.motherboard 
                      << ", жесткий диск: " << computer.harddrive 
                      << ", видеокарта: " << computer.videocard 
                      << ", цена: " << computer.price 
                      << ", количество на складe: " << computer.store 
                      << "\n";
        }
    }
}

int ComputerContainer::getCount() const {
    return computers.size();
}
