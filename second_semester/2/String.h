#ifndef LABORATORIES_STRING_H
#define LABORATORIES_STRING_H


#include <ostream>

class String {
private:
    char *str;
    unsigned int size;
public:
    String();

    explicit String(char *);

    String(const String &);

    String &operator=(const String &);

    ~String();

    String &operator+(const String &str);

    String &operator+=(const String &str);

    char operator[](unsigned int);

    bool operator<(const String &str);

    bool operator>(const String &str);

    bool operator==(const String &str);

    friend std::ostream &operator<<(std::ostream &os, String &str);

    friend std::istream &operator>>(std::istream &is, String &str);

    int find(char symbol);

    unsigned int length() const;

    char at(int idx);

    char *c_str();
};

void run_2();

#endif //LABORATORIES_STRING_H
