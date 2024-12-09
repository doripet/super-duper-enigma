#include "Computer.h"

// конструктор
Computer::Computer(std::string cpu_brand, double cpu_clock, std::string motherboard,
                   std::string harddrive, std::string videocard, double price, int store)
    : cpu_brand(cpu_brand), cpu_clock(cpu_clock), motherboard(motherboard),
      harddrive(harddrive), videocard(videocard), price(price), store(store) {}

// деструктор
Computer::~Computer() {
    // Освобождение памяти ;/
}
