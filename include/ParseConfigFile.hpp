#ifndef PARSE_CONFIG_FILE
#define PARSE_CONFIG_FILE
#include <string>

/*!
	\brief Абстрактный базовый класс
	\author 
	\version 1.0
	\date Январь 2023 года
	\warning Данный класс создан в формате тестового задания и реализации иерархии классов паттерна Strategy

	Абстрактный базовый класс, объявляет интерфейс, общий для всех алгоритмов обработки конфигурационных файлов
*/

class ParseConfigFile
{
 public:    
 virtual ~ParseConfigFile() {}
 virtual bool parseConfigFile( const std::string & file ) = 0;
 virtual bool changeConfigFile( const std::string & path_element, std::string & value ) = 0;
 virtual bool saveConfigFile( const std::string & file ) = 0;
 virtual void showDataConfigFile() = 0;
};

#endif // PARSE_CONFIG_FILE