//
// Created by Tim Andrejc on 27. 5. 24.
//

#ifndef KOLOKVIJ2_FILENOTFOUNDEXCEPTION_H
#define KOLOKVIJ2_FILENOTFOUNDEXCEPTION_H

#include <string>

class FileNotFoundException : public std::exception {
private:
    std::string message;
public:
    FileNotFoundException(std::string file) {
        message = "\nFile not found!\n";
    }

    const char *what() const noexcept {
        return message.c_str();
    }

};

#endif //KOLOKVIJ2_FILENOTFOUNDEXCEPTION_H
