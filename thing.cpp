#include "thing.h"


Thing::Thing(std::string str) {
	this->type = 'N';
	this->str = str;
	this->l = NULL;
	this->r = NULL;
}

Thing::Thing(char type, Thing*l, Thing *r) {
	this->type = type;
	this->l = l;
	this->r = r;
}

int Thing::eval() {
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

	return 0;
}
