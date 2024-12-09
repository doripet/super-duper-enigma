#include <iostream>
#include "ComputerContainer.h"

int main() {
    ComputerContainer container;
	Computer computer1 ("cpu_brand", 2.1, "motherboard", "harddrive", "videocard", 1000, 4);
	Computer computer2 {computer1} ;
	std::cout << computer2.cpu_brand << std::endl;
		    //данные из файла
    container.loadFromFile("computers.txt");

    //содержимое
    std::cout << "Содержимое контейнера:\n";
    container.display();

    //общ стоимость всех компьютеров
    double total = container.totalCost();
    std::cout << "Общая стоимость всех компьютеров: " << total << " рублей\n";

    //поиск по марке процессора
    std::string searchBrand;
    std::cout << "Введите марку процессора для поиска: ";
    std::cin >> searchBrand;
    container.findByCpuBrand(searchBrand);

    // Добавление нов компьютера
    std::string cpu_brand, motherboard, harddrive, videocard;
    double cpu_clock, price;
    int store;

    std::cout << "Введите данные нового компьютера:\n";
    std::cout << "Марка процессора: ";
    std::cin >> cpu_brand;
    std::cout << "Тактовая частота процессора: ";
    std::cin >> cpu_clock;
    std::cout << "Материнская плата: ";
    std::cin >> motherboard;
    std::cout << "Жесткий диск: ";
    std::cin >> harddrive;
    std::cout << "Видеокарта: ";
    std::cin >> videocard;
    std::cout << "Цена: ";
    std::cin >> price;
    std::cout << "Количество в магазине: ";
    std::cin >> store;

    Computer newComp(cpu_brand, cpu_clock, motherboard, harddrive, videocard, price, store);
    container.addComputer(newComp);

    // Сохр изменения в файл
    container.saveToFile("computers.txt");

    // Удаление компьютера
    int indexToRemove;
    std::cout << "Введите номер компьютера для удаления (1 - " << container.getCount() << "): ";
    std::cin >> indexToRemove;

    container.removeComputer(indexToRemove - 1);

    // Сохр изменения в файл после удаления
    container.saveToFile("computers.txt");

    // обновлённое содержимое контейнера
    std::cout << "Обновлённое содержимое контейнера:\n";
    container.display();

    return 0;
}
