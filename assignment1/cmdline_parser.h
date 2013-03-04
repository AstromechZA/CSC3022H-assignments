/*
 * cmdline_parser.h
 *
 *  Created on: 22 Feb 2012
 *      Author: simon
 */

#ifndef CMDLINE_PARSER_H_
#define CMDLINE_PARSER_H_

#include <iostream>
#include <string>

#include <boost/program_options.hpp>

//---------------------------------------------------------------------------//
class cmdline_parser
{
public:
    //-----------------------------------------------------------------------//
	// Constructor
	cmdline_parser(void);

	// Member function that parses command line options
	bool process_cmdline(int argc, char * argv[]);
	// Getter for the db filename cmdline option
	std::string get_database_filename(void) const;
	// Member indicating whether cmdline help should be printed
	bool should_print_help(void) const;
	// Output help to the specified output stream
	void print_help(std::ostream & out) const;

private:
    //-----------------------------------------------------------------------//
	// Member variables
	boost::program_options::variables_map vm;
	boost::program_options::options_description od;
};

#endif /* CMDLINE_PARSER_H_ */
