#include "ContentStorage.h"

ContentStorage::ContentStorage()
{}

ContentStorage::ContentStorage(const ContentStorage& other)
{
    copy(other);
}

ContentStorage& ContentStorage::operator=(const ContentStorage& other)
{
    if (this != &other)
    {
        release();
        copy(other);
    }
    
    return *this;
}

ContentStorage::~ContentStorage()
{
    release();
}

size_t ContentStorage::size() const
{
    return elements.size();
}

void ContentStorage::add(const Content& element)
{
    Content* newElement = new Content(element);
    elements.emplace_back(newElement);
}

Content* ContentStorage::get(const std::string& name) const
{
    for (size_t i = 0; i < elements.size(); ++i)
    {
        Content* element = elements[i];
        if (element && name.compare(element->getName()))
            return element;
    }
    
    return nullptr;
}

Content* ContentStorage::get(size_t index) const
{
    return (index >= 0 && index < elements.size()) ? elements[index] : nullptr;
}

const std::vector<Content *>& ContentStorage::getAll() const
{
    return elements;
}

void ContentStorage::copy(const ContentStorage& other)
{
    for (size_t i = 0; i < other.size(); ++i)
    {
        add(*other.get(i));
    }
}

void ContentStorage::release()
{
    for (size_t i = 0; i < elements.size(); ++i)
    {
        delete elements[i];
    }
}
