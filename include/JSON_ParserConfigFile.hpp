#ifndef JSON_PARSER_CONFIG_FILE
#define JSON_PARSER_CONFIG_FILE

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <nlohmann/json.hpp>
#include <ParseConfigFile.hpp>

using ordered_json = nlohmann::ordered_json;
using namespace nlohmann::literals;

/*!
	\brief Подкласс
	\author 
	\version 1.0
	\date Январь 2023 года
	\warning Данный класс создан в формате тестового задания и реализации иерархии классов паттерна Strategy

	Подкласс, который отнаследован от ParseConfigFile
       реализует алгоритмы обработки конфигурационных файлов .json формата 
*/

class JSON_ParserConfigFile : public ParseConfigFile
{
 public:
        bool parseConfigFile( const std::string & file );
        bool changeConfigFile( const std::string & path_element, std::string & value );
        bool saveConfigFile( const std::string & file );
        void showDataConfigFile();
 private:
        ordered_json _data;
};

#endif // JSON_PARSER_CONFIG_FILE