/*
 * cheapsocket.h
 *
 *  Created on: 16 Mar 2012
 *      Author: simon
 */

#ifndef CHEAPSOCKET_H_
#define CHEAPSOCKET_H_

#include <iostream>
#include <string>
#include <set>

namespace cheapsocket 
{

	int handle_init[5] = { 53, 29, 12, 5, 37 };
	std::set<int> available_handles(handle_init, handle_init+5);
	std::set<int> leased_handles;

	int get_handle(void)
	{
		if(available_handles.empty())
		{
			std::cout << "NO MORE HANDLES! " << std::endl;
			throw std::exception();
		}

		int handle = *available_handles.begin();
		leased_handles.insert(handle);
		available_handles.erase(handle);
		std::cout << "Leasing handle " << handle << std::endl;
		return handle;
	}
	void write_to_handle(int handle, std::string s)
	{
		if(leased_handles.count(handle) == 0)
		{
			std::cout << "Write to invalid handle " << handle << std::endl;
			throw std::exception();
		}
		std::cout << "Wrote: " << s << " on handle " << handle << std::endl;
	}

	std::string read_from_handle(int handle)
	{
		if(leased_handles.count(handle) == 0)
		{
			std::cout << "Read from invalid handle " << handle << std::endl;
			throw std::exception();
		}

		std::cout << "Read data" << " on handle " << handle << std::endl; return "data";
	}

	void release_handle(int handle)
	{
		if(leased_handles.count(handle) == 0)
			return;

		leased_handles.erase(handle);
		available_handles.insert(handle);

		std::cout << "Re-obtained handle " << handle << std::endl;
	}

}

#endif /* CHEAPSOCKET_H_ */
