#include <iostream>

class Logger {
private:
    inline static int counter = 0;

    const int id;

public:
    Logger(): id(++counter) {
        std::cout << "Logger(): " << id << "\n";
    }

    Logger(const Logger& other): id(++counter) {
        std::cout << "Logger(const Logger&): " << id << " " << "\n";
    }

    Logger& operator = (const Logger& other) {
        std::cout << "Logger& operator = (const Logger&) " << id << " " << "\n";
        return *this;
    }

    ~Logger() {
        --counter;
        std::cout << "~Logger() " << id << "\n";
    }
    Logger(Logger&& other): id(++counter) {
        std::cout << "Logger(Logger&&  other): " << id << " " << "\n";
    }

    Logger& operator = (Logger&& other) {
        std::cout << " =&&: " << id << " "  << "\n";
        return *this;
    }
};
void f(const Logger& x) {
    std::cout << "void f(const Logger&)\n";
}
void f(Logger&& x) {
    std::cout << "void f temp\n";
}

int main() {
    /*f(Logger());
    std::cout << "Hello!\n";
    Logger x;
    f(x);
    std::cout << "Bye\n";
    */
    Logger x1;
    Logger x2;
    x2 = x1;
    x2 = std::move(x1);
   /* Logger x2 = x1;
    Logger x3 = Logger();     vsyo eto konstruktor
    Logger x4 = std::move(x1);
    */
}