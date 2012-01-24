#pragma once

#define NO_COPY_CONSTRUCTOR(classname) \
	/** Not-to-be-implemented copy constructor. */ \
	classname(const classname &)

#define NO_ASSIGNMENT_OPERATOR(classname) \
	/** Not-to-be-implmented assignment operator. */ \
	classname & operator=(const classname &)
