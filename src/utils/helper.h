#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

class Helper {
	public:
		static std::string readFileContents(const char* fileName);
};
#endif
