#  Консольный редактор конфигурационного файла
    Считывает и распознаёт содержимое конфигурационного файла (в текущей реализации формат .json), 
    позволяет редактировать стандартные типы параметров.
    Спроектированно с применением паттерна Strategy. 
   
   **Сборка производилась средствами:**
   <li> Ubuntu 18.04.6 LTS
   <li> gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
   <li> boost BOOST_LIB_VERSION "1_81"
   <li> cmake version 3.10.2
   <li> lib pars json - [JSON for Modern C++ version 3.11.2](https://github.com/nlohmann/json)

   **Шаги сборки**

    cd *dir project*
    mkdir tmp
    cd tmp
    cmake ..
    make

   **Примеры использования**

       запуск
        ./parse-config-file config.json
        
        ...
        
        Want to change the setting (key c):
        
        c ... enter

        Enter the path of the element and value:

        примеры ввода при изменении разных типов данных .json:

        cтрока
              codec H.265
        
        число
             bitrate 2049

        логический
             bool_examples false
             
        null
             null_examples null

        объект
              audio {\"enabled\":true,\"codec\":\"G711A\",\"inputVolume\":11}

        массив
              resolution [1281,1025]