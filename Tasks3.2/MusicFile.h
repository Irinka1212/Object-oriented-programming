#pragma once

#include "File.h"

enum MusicExtension { mp3, flac };

std::string musicExtensionToString(MusicExtension extension)
{
    switch (extension) {
        case mp3:
            return "mp3";
        case flac:
            return "flac";
    }
}

class MusicFile: public File
{
public:
    MusicFile(const std::string& name,
              int size,
              const std::string& author,
              const std::string& songName,
              int year,
              MusicExtension musicExtension);
    
    void setAuthor(const std::string& author);
    const std::string& getAuthor() const;
    
    void setSongName(const std::string& songName);
    const std::string& getSongName() const;
    
    void setYear(int year);
    int getYear() const;
    
    void setMusicExtension(MusicExtension musicExtension);
    MusicExtension getMusicExtension() const;
    
private:
    std::string author;
    std::string songName;
    int year;
    MusicExtension musicExtension;
};
