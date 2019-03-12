#include<iostream>
#include<vector>
#include<string>

#include "thing.h"

const int maxOpp = 5;

std::string priorities[maxOpp] = {"+", "-", "/", "*", "="};
bool error = false;

std::map<std::string, int> variables;

Thing *parse(const std::vector <std::string> *elements, int l, int r) {
    if (l >= r) {
        error = true;
        return NULL;
    }

    for (int i = 0; i < maxOpp; i++)
        for (int mid = l; mid < r; mid++)
            if ((*elements)[mid] == priorities[i])
                return new Thing(
                        priorities[i][0],
                        parse(elements, l, mid),
                        parse(elements, mid + 1, r)
                );

    if (r - l != 1) {
        error = true;
        return NULL;
    }

    std::string str = (*elements)[l];
    bool is_number = true;
    for (std::string::iterator it = str.begin() + (str[0] == '-' ? 1 : 0); it != str.end(); ++it)
        if (not isdigit(*it))
            is_number = false;

    if (is_number) {
        return new Thing(str)
    } else {
        return new Thing(str, false);
        error = true;
        return NULL;
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    input.push_back(' ');

    while(input != "Quit") {
        std::vector <std::string> elements;

        std::string temp;
        for (std::string::iterator it = input.begin(); it != input.end(); ++it) {
            if (not isspace(*it)) {
                temp.push_back(*it);
            } else {
                if (temp != "")
                    elements.push_back(temp);
                temp = "";
            }
        }

        Thing *t = parse(&elements, 0, elements.size());

        if (error) {
            std::cout << "ERROR" << std::endl;
            return -1;
        }

        std::cout << t->eval() << std::endl;

        std::getline(std::cin, input);
        input.push_back(' ');
    }
}