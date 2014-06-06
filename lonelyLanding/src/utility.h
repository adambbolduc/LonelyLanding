/*
 * utility.h
 *
 *  Created on: 2014-05-13
 *  \author: Adam B.-Bolduc
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <GLFW/glfw3.h>
#include <string>
#include <vector>

namespace util
{

void error_callback(int error,const char* description);
std::string LoadSource(const char* filename);


std::string slash_to_space(std::string s);
std::string doubleSlash(std::string s);
std::vector<std::string> splitStringIntoToken(std::string line);






};







#endif /* UTILITY_ */
