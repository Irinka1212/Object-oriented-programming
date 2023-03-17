#pragma once

#include <vector>
#include "Content.h"

class ContentStorage
{
public:
    ContentStorage();
    ContentStorage(const ContentStorage& other);
    ContentStorage& operator=(const ContentStorage& other);
    ~ContentStorage();
        
    void add(const Content& element);
    
    Content* get(size_t index) const;
    Content* get(const std::string& name) const;
    const std::vector<Content *>& getAll() const;
    
    size_t size() const;
    
private:
    std::vector<Content *> elements;
    
    void copy(const ContentStorage& other);
    void release();
};
