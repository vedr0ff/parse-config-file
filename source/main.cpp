#include <iostream>
#include <limits>
#include <boost/scoped_ptr.hpp>
#include <ParserConfigFile.hpp>
#include <JSON_ParserConfigFile.hpp>

int main(int argc, char** argv) {
    if (argc>1)
    {
     boost::scoped_ptr<ParserConfigFile> p {new ParserConfigFile( new JSON_ParserConfigFile)};
     if (p->parseConfigFile(std::string(argv[1]))){
        p->showDataConfigFile();
     }
     else{
        exit(EXIT_FAILURE);
     }
     
     char ch; 
     std::cout << "Want to change the setting (key c): ";
     std::cin>>ch;
     while (ch == 'c'){
         std::cout << "Enter the path of the element and value: ";
         std::string path_element, value;
         std::cin >> path_element >> value;
         
         if(p->changeConfigFile(path_element, value))
            p->showDataConfigFile();
         else
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         
         std::cout << "Change the setting (key c) / quit and save (esc/q): ";
         std::cin>>ch;
     } 
    
     p->saveConfigFile(std::string(argv[1]));
    }
}