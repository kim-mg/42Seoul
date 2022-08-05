#include "Replace.hpp"

void Replace::_replaceProcess(void) {
	std::ifstream ifs(_filename.c_str(), std::ifstream::in);
	if (!ifs.good()) {
		std::cout << "Error: ifstream openfile failed." << std::endl;
		return ;
	}
	std::ofstream ofs((_filename + ".replace").c_str(),
		std::ofstream::out | std::ofstream::trunc);
	if (!ofs.good()) {
		std::cout << "Error: ofstream openfile failed." << std::endl;
		return ;
	}
	while (true) {
		size_t find = 0;
		std::getline(ifs, _line);
		if (!ifs.eof() && ifs.fail())
			break ;
		while (true) {
			find = _line.find(_s1);
			if (find == std::string::npos)
				break ;
			std::string f_line = _line.substr(0, find);
			std::string r_line = _s2 + _line.substr(find + _s1.length());
			_line = f_line + r_line;
		}
		if (ifs.eof()) {
			ofs << _line;
			break ;
		}
		ofs << _line << std::endl;  
	}
	ifs.close();
	ofs.close();
}

void Replace::replaceFile(const std::string& filename, const std::string& s1,
	const std::string& s2) {
	Replace rp(filename, s1, s2);

	rp._replaceProcess();
}

Replace::Replace(const std::string& filename, const std::string& s1,
	const std::string& s2)
	: _line(), _filename(filename), _s1(s1), _s2(s2) {
}

Replace::~Replace(void) {
}