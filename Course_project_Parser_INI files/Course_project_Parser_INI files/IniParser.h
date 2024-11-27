#pragma once
#include <string>
#include <fstream>
#include <map>
#include <format>


class IniParser {
	std::string line;
	std::ifstream fin;
	std::map<std::string, std::map<std::string, std::string>> key_value;
	std::string section;
	int count_line = 0;
public:
	IniParser(std::string FileName) {
		fin.open(FileName);
		if (!fin) {
			throw std::invalid_argument(std::format("{} failed to open file!\n", FileName));
		}
		else {
			while (std::getline(fin, line)) {
				if (line.empty() || line[0] == ';') {
					count_line++;
					continue;
				}
				if (line.find("[") != std::string::npos and line.find("]") != std::string::npos) {
					count_line++;
					if (line[0] == '[') {
						section = line.substr(1, (line.find("]") - line.find("[") - 1));
					}
					else {
						throw std::runtime_error(std::format("Line {} of the file contains incorrect syntax\n", count_line));
					}
				}
				else {
					size_t equalsPos = line.find('=');
					count_line++;
					if (equalsPos != std::string::npos) {
						std::string key;
						for (int i = 0; i < line.substr(0, equalsPos).length(); i++) {
							if (line.substr(0, equalsPos)[i] == ' ') {
								continue;
							}
							else {
								key += line.substr(0, equalsPos)[i];
							}
						}
						std::string value;
						for (int i = 0; i < line.substr(equalsPos + 1).length(); i++) {
							if (line.substr(equalsPos + 1)[i] == ' ') {
								continue;
							}
							else if (line.substr(equalsPos + 1)[i] == ';') {
								break;
							}
							else {
								value += line.substr(equalsPos + 1)[i];
							}
						}
						key_value[section][key] = value;
					}
				}
			}
		}
	}

	template<typename T>
	T get_value(std::string str) {
		size_t equalsPos = str.find('.');
		std::string sections = str.substr(0, equalsPos);
		std::string key = str.substr(equalsPos + 1);
		if (key_value.count(sections)) {
			if (key_value[sections].count(key)) {
				std::string value;
				value = key_value[sections][key];
				if (value.empty()) {
					throw std::domain_error(std::format("There is no value for variable '{}' in the file\n", key));
				}
				if (typeid(T) == typeid(int)) {
					std::string dig_value;
					for (int i = 0; i < value.length(); i++) {
						if (std::isdigit(value[i])) {
							dig_value += value[i];
						}
						else {
							throw std::domain_error(std::format("{} - value does not match type 'int'\n", value));
						}
					}
					return std::stoi(dig_value);
				}
				else if (typeid(T) == typeid(double)) {
					std::string dig_value;
					if (value.find(".") == std::string::npos) {
						throw std::domain_error(std::format("{} - value does not match type 'double'\n", value));
					}
					for (int i = 0; i < value.length(); i++) {
						if (std::isdigit(value[i]) or value[i] == '.') {
							dig_value += value[i];
						}
						else {
							throw std::domain_error(std::format("{} - value does not match type 'double'\n", value));
						}
					}
					return (std::stod(dig_value));
				}
			}
			else {
				print_variable(sections);
				throw std::domain_error(std::format("There is no variable '{}' in '{}'\n", key, sections));
			}
		}
		else {
			print_section();
			throw std::domain_error(std::format("There is no '{}' in the file\n", sections));
		}
	}

	void print_variable(std::string& sctn) {
		std::cout << "Valid variables in the section:\n";
		auto it = key_value.find(sctn);
		for (auto i = it->second.begin(); i != it->second.end(); i++) {
			std::cout << "\t" << i->first << std::endl;
		}
	}

	void print_section() {
		std::cout << "Valid sections:\n";
		for (auto it = key_value.begin(); it != key_value.end(); it++) {
			std::cout << "\t" << it->first << std::endl;
		}
	}
};


