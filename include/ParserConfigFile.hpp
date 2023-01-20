#ifndef PARSER_CONFIG_FILE
#define PARSER_CONFIG_FILE

#include <string>
#include <ParseConfigFile.hpp>

/*!
	\brief Класс переадресации
	\author 
	\version 1.0
	\date Январь 2023 года
	\warning Данный класс создан в формате тестового задания

	Класс, предназначен для переадресации пользовательских запросов конкретному алгоритму обработки конфигурационного файла
*/

class ParserConfigFile 
{
    public:
            ParserConfigFile( ParseConfigFile* pars): p(pars) {}
            ~ParserConfigFile() { delete p; }
            bool parseConfigFile( const std::string & file ) 
                {
                   return p->parseConfigFile(file);
                }

            bool changeConfigFile( const std::string & path_element, std::string & value )
                {
                    return p->changeConfigFile(path_element, value);
                }

            bool saveConfigFile( const std::string & file )
                {
                    return p->saveConfigFile(file);
                }

            void showDataConfigFile()
                {
                    p->showDataConfigFile();
                }

    private:
            ParseConfigFile* p;
};

#endif // PARSER_CONFIG_FILE