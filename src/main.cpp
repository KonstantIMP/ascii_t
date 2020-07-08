#include "../include/defines.hpp"

#include <iostream>

#ifndef __linux

#include <conio.h>

#else

#include <termios.h>
#include <unistd.h>

int _getch() {
    int ch; termios oldt, newt;

    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;

    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

    return ch;
}

#endif

int main() {
    std::cout << " ______     ______     ______     __     __        ______         \tVersion : " << STR_VERSION << "\n";
    std::cout << "/\\  __ \\   /\\  ___\\   /\\  ___\\   /\\ \\   /\\ \\      /\\__  _\\        \n";
    std::cout << "\\ \\  __ \\  \\ \\___  \\  \\ \\ \\____  \\ \\ \\  \\ \\ \\     \\/_/\\ \\/   __   \tDeveloper : KonstantIMP (Mikhedov Konstantin)\n";
    std::cout << " \\ \\_\\ \\_\\  \\/\\_____\\  \\ \\_____\\  \\ \\_\\  \\ \\_\\       \\ \\_\\  /\\_\\  \tFeedback email : mihedovkos@gmail.com\n";
    std::cout << "  \\/_/\\/_/   \\/_____/   \\/_____/   \\/_/   \\/_/        \\/_/  \\/_/  \n\n";

    std::cout << "To exit programm press Enter\n\n";

    char sym = 0;

    while(1) {
        std::cout << "Enter ASCII symbol : ";
        sym = _getch();
        if(sym == 13) break;
        if(sym != '\n') {
            std::cout << sym << '\n';
            std::cout << "\t \'" << sym << "\' is " << static_cast<int>(sym) << " (0x" << std::hex << static_cast<int>(sym) << std::dec << ") in ASCII," << std::endl;
            std::cout << "\t   and \'" << sym << "\' is " << static_cast<int>(static_cast<unsigned char>(sym)) << " (0x" << std::hex << static_cast<int>(static_cast<unsigned char>(sym)) << std::dec << ") in usigned ASCII" << std::endl << std::endl;
        }
        else break;
    }

    std::cout << "\n\nGood bye!\n";

    return 0;
}
