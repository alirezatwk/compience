#include "thing.h"


Thing::Thing(std::string str, bool isNumber) {
    if (isNumber)
        this->type = 'N';
    else
        this->type = 'V';
    this->str = str;
    this->l = NULL;
    this->r = NULL;
}

Thing::Thing(char type, Thing *l, Thing *r) {
    this->type = type;
    this->l = l;
    this->r = r;
}

int Thing::eval(std::map<std::string, int> *variables) {

    if (type == 'V') {
        return variables[this->str];
    }

    if (type == 'N') {
        return std::atoi(this->str.c_str());
    }

    if (type == '+') {
        return this->l->eval() + this->r->eval();
    }

    if (type == '-') {
        return this->l->eval() - this->r->eval();
    }

    if (type == '*') {
        return this->l->eval() * this->r->eval();
    }

    if (type == '/') {
        return this->l->eval() / this->r->eval();
    }

    if (type == '=') {
        variables[this->l->str] = this->r->eval();
        return this->r->eval();
    }

    return 0;
}
