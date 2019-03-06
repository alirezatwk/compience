#include<string>


class Thing {
	public:
		char type;
		Thing* l;
		Thing* r;

		std::string str;

		Thing(std::string str);
		Thing(char type, Thing* l, Thing* r);

		int eval();
};
