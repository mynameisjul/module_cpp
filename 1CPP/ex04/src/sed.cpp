#include "sed.hpp"

bool Sed::open_files(const std::string &file_name)
{
	std::string replace_file_name = file_name + ".replace";

	_infile.open(file_name.c_str());
	if (!_infile)
		return (_outfile.close(), false);
	
	_outfile.open(replace_file_name.c_str());
	if (!_outfile)
		return (false);
	
	return (true);
}

bool Sed::sed(const std::string &file_name)
{
	std::string line;
	bool		first_loop(true);

	if (open_files(file_name) == false) return (false);
	while (getline(_infile, line))
	{
		if (first_loop == false)
			_outfile << std::endl;
		if (first_loop == true)
			first_loop = false;
		if (!_search.empty())
			{
			size_t pos(0);
			pos = line.find(_search);
			while (pos != std::string::npos) {				
				line.erase(pos, _search_len);
				line.insert(pos, _replace);
				pos = line.find(_search, pos + _replace_len);
			}
		}
		_outfile << line;
	}
	return (true);
}

Sed::Sed() : _infile(NULL), _outfile(NULL), _search(NULL), _replace(NULL), _search_len(0) {}

Sed::Sed(std::string search, std::string replace, size_t search_len, size_t replace_len) :  _infile(0), _outfile(0), _search(search), _replace(replace), _search_len(search_len), _replace_len(replace_len) {
}

Sed::~Sed() 
{
	if (_infile)
		_infile.close();
	if (_outfile)
		_outfile.close();
}