#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>
#include <time.h>


class BitCoinExchange {
	private:
		std::ifstream				ref_file;
		std::map<std::string, double>	ref_map;
		void	isValidFileName(std::string name); // checks name validity
		void	openRefFile(); //tries to open file
		bool	isValidDate(std::string date); // checks date validity
		int		isValidValue(std::string value, bool isRate); // checks value validity
		void	fileToMap();
	public:
		BitCoinExchange();
		BitCoinExchange(BitCoinExchange const &other);
		BitCoinExchange &operator=(BitCoinExchange const &other);
		~BitCoinExchange();

		void	inputToOutput(std::ifstream &input_file);

		class CouldNotOpenFile : public std::exception {
			virtual const char *what() const throw() {
				return "Could not open file";
			}
		};

		class InvalidFileName : public std::exception {
			virtual const char *what() const throw() {
				return "Invalid file name";
			}
		};

		// DEBUG HELPERS
		void printMap();
};
