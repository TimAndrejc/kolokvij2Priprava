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
#include "FileNotFoundException.h"
#include <sstream>

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
        if (!file) {
            throw FileNotFoundException(fileName);
        }
        std::vector<Fuel> fuel;
        std::string line;


        while (getline(file, line)) {
            std::vector<std::string> temp;
            std::istringstream ss(line);
            std::string item;
            while (getline(ss, item, ',')) {
                temp.push_back(item);
            }
            try {
                fuel.push_back(Fuel(Date::getDateFromString(temp[0]), std::stoi(temp[1]), std::stof(temp[2]), temp[3],
                                    std::stof(temp[4])));
            } catch (UnparseableDateException &e) {
                std::cout << e.what();
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

    friend std::ostream &operator<<(std::ostream &output, const std::vector<Fuel> &fuel) {
        for (const Fuel &f: fuel) {
            output << f.toString();
        }
        return output;
    }

};

#endif //KOLOKVIJ2_FEL_H
