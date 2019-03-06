#include<iostream>
#include<vector>
#include<string>


int main(){
	std::string input;
	std::getline(std::cin, input);
	input.push_back(' ');

	std::vector<std::string> elements;

	std::string temp;
	for(std::string::iterator it = input.begin(); it != input.end(); ++it) {
		if (not isspace(*it)) {
			temp.push_back(*it);
		} else {
			if (temp != "")
				elements.push_back(temp);
			temp = "";
		}
	}


	int result = 0;
	bool wait_for_number = true;
	for ( std::vector<std::string>::iterator it = elements.begin(); it != elements.end(); ++it ) {
		if ((*it) == "+"){
			if (wait_for_number) {
				std::cout << "ERROR" << std::endl;
				return -1;
			} else {
				wait_for_number = true;
				continue;
			}
		}

		bool is_number = true;
		for ( std::string::iterator cit = it->begin() + ((*it)[0] == '-' ? 1 : 0); cit != it->end(); ++cit)
			if (not isdigit(*cit))
				is_number = false;

		if (is_number && wait_for_number) {
			result += std::atoi(it->c_str());
			wait_for_number = false;
		} else {
			std::cout << "ERROR" << std::endl;
			return -1;
		}
	}

	std::cout << result << std::endl;
}
