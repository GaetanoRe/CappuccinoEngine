#include <algorithm>
#include <cctype>

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <memory>


#include <string>
#include <regex>
#include "../include/settings.h"

Settings::Settings(const std::string& filename) {
	allSettings = loadSettingsFromFile(filename);
}

Settings::~Settings() = default; 

std::string Settings::getString(const std::string& section, const std::string& key) const {
	if (allSettings.count(section) && allSettings.at(section).count(key)) {
		return allSettings.at(section).at(key);
	}
	
	return "";
}

std::map<std::string, std::string> Settings::getStrings(const std::string& section) const{
	if (allSettings.count(section)) {
		return allSettings.at(section);
	}
}

int Settings::getInt(const std::string& section, const std::string& key) const {
	std::string valueStr;
	if (allSettings.count(section) && allSettings.at(section).count(key)) {
		valueStr = allSettings.at(section).at(key);
	}
	else {
		std::cerr << "Setting " << key << " not found in section " << section << "." << std::endl;
	}

	try {
		return std::stoi(valueStr);
	}
	catch(const std::invalid_argument& e){
		std::cerr << "Invalid integer format for key " << key << " in section " << section << " Error: "<< e.what() << std::endl;
		return 0;
	}
	catch(const std::out_of_range& e){
		std::cerr << "Integer out of range for key " << key << " in section " << section << " Error: " << e.what() << std::endl;

	}
}

float Settings::getFloat(const std::string& section, const std::string& key) const {
	std::string valueStr;
	if (allSettings.count(section) && allSettings.at(section).count(key)) {
		valueStr = allSettings.at(section).at(key);
	}
	else {
		std::cerr << "Setting " << key << " not found in section " << section << "." << std::endl;
	}

	try {
		return std::stof(valueStr);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid float format for key " << key << " in section " << section << " Error: " << e.what() << std::endl;
		return 0;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Float out of range for key " << key << " in section " << section << " Error: " << e.what() << std::endl;

	}
}

bool Settings::getBool(const std::string& section, const std::string& key) const {
	std::string valueStr;
	if (allSettings.count(section) && allSettings.at(section).count(key)) {
		valueStr = allSettings.at(section).at(key);
	}
	else {
		std::cerr << "Setting " << key << " not found in section " << section << "." << std::endl;
	}

	std::transform(valueStr.begin(), valueStr.end(), valueStr.begin(), ::tolower);
	if (valueStr == "true" || valueStr == "1" || valueStr == "yes" || valueStr == "on") {
		return true;
	}
	else if (valueStr == "false" || valueStr == "0" || valueStr == "no" || valueStr == "off") {
		return false;
	}
	else {
		std::cerr << "Invalid boolean format for key '" << key << "' in section '" << section << "': '" << valueStr << "'. Returning default: false" << std::endl;
		return false; // Default value on error
	}
}

bool Settings::sectionExists(const std::string& section) const {
	if (allSettings.count(section)) {
		return true;
	}
	else {
		return false;
	}
}

std::map <std::string, std::map<std::string, std::string>> Settings::loadSettingsFromFile(const std::string& filename) {
	std::map<std::string, std::map<std::string, std::string>> allSettings;
	std::ifstream file(filename);

	if (file.is_open()) {
		std::string line;
		std::string currentSection;
		while (std::getline(file, line)) {
			if (line.empty() || line[0] == '#') continue;

			std::regex sectionRegex(R"(\[(.*)\])");
			std::smatch match;

			if (std::regex_match(line, match, sectionRegex)) {
				currentSection = match[1];
			}
			else {
				std::istringstream iss(line);
				std::string key;
				char seperator;
				std::string value;

				if (std::getline(iss, key, '=') && std::getline(iss, value)) {
					if (!currentSection.empty()) {
						allSettings[currentSection][key] = value;
						std::cout << "Setting Category " << currentSection << " with key " << key << " properly stored the information " << allSettings[currentSection][key] << ". " << std::endl;
					}
					else {
						std::cerr << "Setting " << key << " outside of any section" << std::endl;
					}
				}
				else {
					std::cerr << "Invalid line format " << line << std::endl;
				}
			}
		}
		file.close();
	}
	else {
		std::cerr << "Unable to locate or open file " << filename << std::endl;
	}

	return allSettings;
}