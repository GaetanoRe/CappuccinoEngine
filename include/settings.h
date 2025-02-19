#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <regex>
#include<algorithm>
#include<cctype>
#pragma once

class Settings {
public:
	Settings(const std::string& filename);
	~Settings();

	std::string getString(const std::string& section, const std::string& key) const;
	std::map <std::string, std::string> getStrings(const std::string& section) const;
	int getInt(const std::string& section, const std::string& key) const;
	float getFloat(const std::string& section, const std::string& key) const;
	bool getBool(const std::string& section, const std::string& key) const;
	bool sectionExists(const std::string& section) const;


private:
	std::map <std::string, std::map<std::string, std::string>> allSettings;

private:
	std::map<std::string, std::map<std::string, std::string>> loadSettingsFromFile(const std::string& filename);
};