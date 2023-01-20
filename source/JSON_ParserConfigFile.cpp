#include <JSON_ParserConfigFile.hpp>

/*!
Открывает и обрабатывает конфигурационный файл формата .json 
\param[in] file путь/название конфигурационного файла
\return результат успешности выполнения
*/
bool JSON_ParserConfigFile::parseConfigFile( const std::string & file )
{
    try{
        std::ifstream f(file);
        if(f.is_open()){
            _data = ordered_json::parse(f);
            f.close();
        }
        else{
            f.close();
            throw std::runtime_error(std::string("Failed open file - ") + file);
        }
    }
    catch(std::exception const& e){
        std::cout << e.what() << std::endl; 
        return false;
    }
    return true;
}

/*!
Изменяет данные указанного параметра конфигурационного файл формата .json 
\param[in] path_element название изменяемого параметра
\param[in] value новое значение изменяемого параметра
\return результат успешности выполнения
*/
bool JSON_ParserConfigFile::changeConfigFile( const std::string & path_element, std::string & value )
{
    try{
        if (_data.contains(path_element)) {
            if(_data[path_element].is_null())
                _data[path_element] = nullptr;
            else if(_data[path_element].is_boolean()){
                if(value == "true")
                    _data[path_element] = true;
                else if(value == "false")
                    _data[path_element] = false;
                else
                    throw std::runtime_error(std::string("Failed params (not true/false) - ") + value);
            }
            else if(_data[path_element].is_number())
                _data[path_element] = std::stoi(value);
            else if(_data[path_element].is_object()){
                 value.erase(remove(value.begin(), value.end(), '\\'), value.end()); 
                 ordered_json j = ordered_json::parse(value);
                 if(j.is_object())
                    _data[path_element] = j;
                 else
                    throw std::runtime_error(std::string("Failed params (not object) - ") + value);
            }
            else if(_data[path_element].is_array()){
                 ordered_json j = ordered_json::parse(value);
                 if(j.is_array())
                    _data[path_element] = j;
                 else
                    throw std::runtime_error(std::string("Failed params (not array) - ") + value);
                }
            else if(_data[path_element].is_string())
                _data[path_element] = value;
            }
        }
        catch(std::exception const& e){
            std::cout << e.what() << std::endl; 
            return false;
        }
    return true;
}

/*!
Сохраняет данные в конфигурационный файл формата .json 
\param[in] file путь/название конфигурационного файла
\return результат успешности выполнения
*/
bool JSON_ParserConfigFile::saveConfigFile( const std::string & file )
{
    try{
        std::ofstream o(file);
        if(o.is_open()){
             o << std::setw(4) << _data << std::endl;   
             o.close();
            }
        else{
             o.close();
             throw std::runtime_error(std::string("Failed open file - ") + file);   
            }
    }
    catch(std::exception const& e){
        std::cout << e.what() << std::endl; 
        return false;
    }
    return true;
}

/*!
Отображает данные конфигурационного файл формата .json
*/

void JSON_ParserConfigFile::showDataConfigFile()
{
    if(_data != NULL)
        std::cout << _data.dump(4) << std::endl;
    else
        std::cout << "Not data config file" << std::endl;
}