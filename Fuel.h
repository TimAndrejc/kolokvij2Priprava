//
// Created by Tim Andrejc on 28. 5. 24.
//

#ifndef KOLOKVIJ2_FEL_H
#define KOLOKVIJ2_FEL_H

#include "Date.h"
#include <vector>
#include <fstream>
#include "UnparseableDateException.h"
#include <iostream>
#include <stdarg.h>

class Fuel {
private:
    Date date;
    unsigned int mileage;
    float fuelAmount;
    std::string fuelType;
    float pricePerLiter;
public:
    Fuel(Date date, unsigned int mileage, float fuelAmount, std::string fuelType, float pricePerLiter) : date(date),
                                                                                                         mileage(mileage),
                                                                                                         fuelAmount(
                                                                                                                 fuelAmount),
                                                                                                         fuelType(
                                                                                                                 fuelType),
                                                                                                         pricePerLiter(
                                                                                                                 pricePerLiter) {}

    std::string toString() const {
        return date.toString() + "," + std::to_string(mileage) + "," +
               std::to_string(fuelAmount) + "," + fuelType + "," +
               std::to_string(pricePerLiter) + "\n";
    }

    float getPrice() const {
        return pricePerLiter;
    }

    static std::vector<Fuel> LoadFromFile(const std::string &fileName) {
        std::ifstream file(fileName);
        std::vector<Fuel> fuel;
        std::string line;
        int mileage;
        float fuelAmount;
        std::string type;
        float price;
        Date date(1, 1, 1);
        int i = 0;
        while (getline(file, line, ',')) {
            switch (i) {
                case 0:
                    try {
                        date = Date::getDateFromString(line);
                    } catch (UnparseableDateException &e) {
                        std::cout << e.what();
                        date = Date(1, 1, 1);
                    }
                    i++;
                    break;
                case 1:
                    mileage = std::stoi(line);
                    i++;
                    break;
                case 2:
                    fuelAmount = std::stof(line);
                    i++;
                    break;
                case 3:
                    type = type;
                    i++;
                    break;
                case 4:
                    price = std::stof(line);
                    fuel.push_back(Fuel(date, mileage, fuelAmount, type, price));
                    i = 0;
                    break;
            }
        }
        return fuel;
    }

    static void SortRefuels(std::vector<Fuel> &refuels, bool (*c)(const Fuel &, const Fuel &)) {
        std::sort(refuels.begin(), refuels.end(), c);
    }

    static void saveToFile(const std::vector<Fuel> &athletes, const std::string &fileName) {
        std::ofstream file(fileName);
        for (const Fuel &f: athletes) {
            file << f.toString();
        }
    }

    static float avgPricePerLiter(int j, ...) {
        va_list args; // variable arguments list
        float arg, vsota = 0;
        int k;
        va_start(args, j); //set the last parameter before variable arguments list
        for (k = 0; k < j; k++) {
            arg = va_arg(args, double); // take one argument from variable arguments list
            vsota += arg;
        }
        va_end(args); //End using variable argument list
        return vsota / j;
    }

};

#endif //KOLOKVIJ2_FEL_H
