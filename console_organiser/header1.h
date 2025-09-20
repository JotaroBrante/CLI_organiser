#pragma once
#include <vector>
#include <string>
bool fileExistsRobust(const std::string& filename) { //��������� ������������� �����
    std::ifstream file(filename);
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

class Task { // ����� ����������� ������
private:
    std::string description;
    std::string deadline;
    std::string stage_of_execusion;
public:
    // ����������� ������ - �������������� ��� ����
    Task()
    {
        this->description = "";
        this->deadline = "";
        this->stage_of_execusion = "";
    }
    void set_description(std::string description)
    {
        this->description = description;
    }
    void set_deadline(std::string deadline)
    {
        this->deadline = deadline;
    }

    void set_stage_of_execusion(std::string stage_of_execusion)
    {
        this->stage_of_execusion = stage_of_execusion;
    }
    std::string get_description()
    {
        return description;
    }
    std::string get_deadline()
    {
        return deadline;
    }
    std::string get_stage_of_execusion()
    {
        return stage_of_execusion;
    }
};


// ����� FileManager ��������� ������� �����������
// �������� �� ��������, ���������� � ������ � ������� �����
class FileManager {
private:
    static int fileCounter; // ����������� ������� ��� ��������� ���������� ���� ������
    Task task;
    std::string filename;


public:
    // ���������� ���������� ��� ����� �� ������ ��������
    
     std::string generateFilename()
    {
        return "tasks_" + std::to_string(++fileCounter) + ".txt";
    }



    

    // ������� ����� ���� � ���������� ������, ��������� ��������, �������, ������ ����������
     bool createFile(std::string description, std::string deadline, std::string stage)
    {
        filename = generateFilename();
        std::ofstream file(filename, std::ios::app);
        if (!file.is_open())
        {
            throw std::runtime_error("File " + filename + " creating error\n");
        }
        std::cout << "File has been created: " << filename << std::endl;
        task.set_deadline(deadline);
        task.set_description(description);
        task.set_stage_of_execusion(stage);
        file << "Description: " << task.get_description() << std::endl;
        file << "Deadline: " << task.get_deadline() << std::endl;
        file << "Stage of execusion: " << task.get_stage_of_execusion() << std::endl;
        return true;
    }
     void displayFileContents(const std::string& filename) {
         std::ifstream file(filename);

         if (!file.is_open()) {
             std::cout << "������: File opening error" << filename << "'" << std::endl;
             return;
         }

         std::cout << "\n=== FILE CONTAINING: " << filename << " ===" << std::endl;

         std::string line;
         int lineNumber = 1;

         while (std::getline(file, line)) {
             std::cout << lineNumber << ": " << line << std::endl;
             lineNumber++;
         }

         file.close();
         std::cout << "=== END OF FILE ===" << std::endl;
     }
     
     
    

};

int FileManager::fileCounter = 0;