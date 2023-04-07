#include "helper.h"

std::string Helper::readFileContents(const char* fileName) {
	std::string result;
	std::ifstream fileStream(fileName, std::ios::in);
	if(fileStream.is_open()){
		std::stringstream sstr;
		sstr << fileStream.rdbuf();
		result = sstr.str();
		fileStream.close();
	}else{
		std::cerr << "Impossible to open " << fileName << "." << std::endl;
		throw(errno);
	}
	return result;
}
