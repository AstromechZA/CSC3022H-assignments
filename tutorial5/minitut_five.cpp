/*
 * minitut4.cpp
 *
 *  Created on: 16 Mar 2012
 *      Author: simon
 */

#include <iostream>
#include <string>
#include <set>

#include "cheapsocket.h"
#include "noisy.h"

// Adds two noisy rational numbers together, creating
// a new object
noisyrat addrats(noisyrat &lhs, noisyrat &rhs)
{
	std::cout << "addrats()" << std::endl;
	return noisyrat(
		lhs.get_n()*rhs.get_d() + rhs.get_n()*lhs.get_d(),
		lhs.get_d()*rhs.get_d());
}

// Adds the value of rhs to that of lhs and returns lhs
noisyrat & addtorat(noisyrat &lhs, noisyrat &rhs)
{
	std::cout << "addtorats()" << std::endl;
	lhs.set_n(lhs.get_n()*rhs.get_d() + rhs.get_n()*lhs.get_d()) ;
	lhs.set_d(lhs.get_d()*rhs.get_d());
	return lhs;
}


class raiisocket
{
public:
    raiisocket()
    {	
    	handle = cheapsocket::get_handle();
    }
    ~raiisocket()
    {
    	cheapsocket::release_handle(handle);  
    }

    void write(std::string content)
    {
    	cheapsocket::write_to_handle(handle, content);
    }

    std::string read()
    {
    	return cheapsocket::read_from_handle(handle);
    }

private:
    int handle;

};



int main(void)
{
	std::cout << "PART ONE:" << std::endl;
	for(int i=0; i<10;++i)
	{
		raiisocket r = raiisocket();
		r.write("Hello World!");
		std::string s = r.read();
	}

	std::cout << "PART TWO:" << std::endl;
	{
		noisyrat n1(2,3);
		noisyrat n2(4,5);
		noisyrat n3(5,6);
		n3 = addrats(n1,n2);
		std::cout << "n3=" << n3 << std::endl;
		std::cout.flush();
	}

	{
		noisyrat n1(2,3);
		noisyrat n2(4,5);
		addtorat(n1,n2);
		std::cout << "n1=" << n1 << std::endl;
		std::cout.flush();
	}
}
