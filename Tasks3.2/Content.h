#pragma once

#include <string>
#include "Date.h"

/// Base class to represent files and folders
class Content
{
protected:
    std::string name;
    Date dateOfCreation;

public:
    Content(){}
    Content(const std::string& name) : name(name){}
    
    virtual void setName(const std::string& name) { this->name = name; }
    virtual const std::string& getName() const { return name; }
    
    virtual void setDate(const Date& date) { this->dateOfCreation = date; }
    virtual const Date& getDate() const { return dateOfCreation; }
};
