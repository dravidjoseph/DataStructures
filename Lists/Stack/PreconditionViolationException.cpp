/******************************************************************
* @file : PreconditionViolationException.cpp
* @author : Dravid Joseph
* @date : 9/28/15
* @brief : Implementation for PreconditionViolationException class.
*******************************************************************/

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* msg):std::runtime_error(msg){
	
}