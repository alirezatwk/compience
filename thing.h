#include<string>
#include<map>

class Thing {
	public:
		Thing(std::string str, bool isNumber = true);
		Thing(char type, Thing* l, Thing* r);

		int eval(std::map<std::string, int> *variables);


    private:

        char type;
        Thing* l;
        Thing* r;
        std::string str;
};
