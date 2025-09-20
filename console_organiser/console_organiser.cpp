// console_organiser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <filesystem>
#include "header1.h"
using std::cin;
using std::cout;
using std::endl;





int main()
{
    std::cout << "It's CLI organiser app.\nTo create a new file, enter the command: CREATE\nTo continue writing to an existing file, type the command : EDIT\nThen the entry INPUT NAME OF THE FILE YOU NEED: will appear. You must enter the file name.\nTo end work with programm you must input STOP" << std::endl;
    std::string command; // Переменная для хранения команды пользователя
    getline(cin, command);
    while (command != "STOP")
    {
        FileManager manager;
        if (command == "CREATE")
        {
            
            std::string description, deadline, stage_of_execusion;
            std::cout << "Description: "; //считывание описания задачи
            getline(cin, description);
            std::cout << "Deadline: "; //считывание даты дедлайна
            getline(cin, deadline);
            std::cout << "Stage_of_execusion: "; 
            getline(cin, stage_of_execusion); //считывание стадии выполнения
            manager.createFile(description, deadline, stage_of_execusion); 
            std::cout << std::endl << std::endl << "NEW COMMAND: ";
        }
        getline(cin, command);
        if (command == "READ")
        {
            std::cout << "INPUT NAME OF THE FILE YOU NEED :";
            std::string filename;
            cin >> filename;
            if (!fileExistsRobust(filename)) {
                std::cout << "File " << filename << " doesn't exist!" << std::endl;
                std::cout << "Try again. Command: ";
                std::cin >> command;
            }
            else {
                manager.displayFileContents(filename);
            }
        }
        getline(cin, command);
    }
    return 0;

}

