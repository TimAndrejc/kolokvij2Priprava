//
// Created by Tim Andrejc on 27. 5. 24.
//

#ifndef KOLOKVIJ2_DATE_H
#define KOLOKVIJ2_DATE_H

#include <string>
#include "UnparseableDateException.h"

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date(unsigned int day, unsigned int month, unsigned int year) : day(day),
                                                                    month(month), year(year) {}

    std::string toString() const {
        return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
    }

    static Date getDateFromString(std::string date) {
        int first = -1, second = -1;

        for (int i = 0; i < strlen(date.c_str()); i++) {
            if (date[i] == '.') {
                if (first == -1) {
                    first = i;
                } else {
                    second = i;
                    break;
                }
            }
        }
        std::string day, month, year;
        for (int i = 0; i < first; i++) {
            if (date[i] >= '0' && date[i] <= '9')
                day += date[i];
            else
                throw UnparseableDateException(date);

        }
        for (int i = first + 1; i < second; i++) {
            if (date[i] >= '0' && date[i] <= '9')
                month += date[i];
            else
                throw UnparseableDateException(date);
        }
        for (int i = second + 1; i < date.size(); i++) {
            if (date[i] >= '0' && date[i] <= '9')
                year += date[i];
            else
                throw UnparseableDateException(date);
        }

        return Date(std::stoi(day), std::stoi(month), std::stoi(year));
    }

};

#endif //KOLOKVIJ2_DATE_H
