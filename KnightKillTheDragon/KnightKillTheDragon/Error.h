#pragma once
#ifndef __ERROR_H__
#define __ERROR_H__
#include <stdexcept>
class Error :public std::logic_error {
public:
	Error(std::string error_msg) :logic_error(error_msg) {};
};
#endif // !__ERROR_H__
