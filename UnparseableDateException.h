//
// Created by Tim Andrejc on 27. 5. 24.
//

#ifndef KOLOKVIJ2_UNPARSEABLEDATEEXCEPTION_H
#define KOLOKVIJ2_UNPARSEABLEDATEEXCEPTION_H

#include <string>

class UnparseableDateException : public std::exception {
private:
    std::string message;
public:
    UnparseableDateException(std::string date) {
        message = "\nUnparseable date: " + date;
    };

    const char *what() const noexcept {
        return message.c_str();
    }

};

#endif //KOLOKVIJ2_UNPARSEABLEDATEEXCEPTION_H
