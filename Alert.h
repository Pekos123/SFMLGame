#pragma once
#include <iostream>
#include <string>

class Alert
{
private:
    enum AlertType { Default, Error, Warning };

    static Alert* CreateAlert(const char* file, int line, AlertType type, const std::string& msg)
    {
        switch (type)
        {
        case Default:
            std::cerr << "Alert: ";
            break;
        case Error:
            std::cerr << "\033[31mERROR: ";
            break;
        case Warning:
            std::cerr << "\033[33mWarning: ";
            break;
        }
        std::cerr << "\033[0m";
        std::cerr << file << " | " << line << " : " << msg;
        return new Alert();
    }

public:
    static Alert* ERROR(const std::string& msg)
    {
        return Alert::CreateAlert(__FILE__, __LINE__, Error, msg);
    }
    static Alert* WARNING(const std::string& msg)
    {
        return Alert::CreateAlert(__FILE__, __LINE__, Warning, msg);
    }
    static Alert* DEFAULT(const std::string& msg)
    {
        return Alert::CreateAlert(__FILE__, __LINE__, Default, msg);
    }
};