#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>


class BitCoinExchange {
	private:
		std::ifstream				ref_file;
		std::ifstream				input_file;
		std::map<time_t, double>	ref_map;
		void	openFile(std::string name); //tries to open file
		bool	isValidDate(std::string date); // checks date validity
		time_t	stringToKey(std::string date);
		bool	isValidValue(std::string value); // checks value validity
		void	fileToMap(std::string input_file);
	public:
		BitCoinExchange();
		BitCoinExchange(BitCoinExchange const &other);
		BitCoinExchange &operator=(BitCoinExchange const &other);
		void	isValidFileName(std::string name); // checks name validity
		void	inputToOutput(std::string input_file);

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
};
