#include "MusicFile.h"

MusicFile::MusicFile(const std::string& name,
                     int size,
                     const std::string& author,
                     const std::string& songName,
                     int year,
                     MusicExtension musicExtension) :
File(name, size, musicExtensionToString(musicExtension)),
author(author), songName(songName), year(year), musicExtension(musicExtension)
{}

void MusicFile::setAuthor(const std::string& author)
{
    this->author = author;
}

const std::string& MusicFile::getAuthor() const
{
    return author;
}

void MusicFile::setSongName(const std::string& songName)
{
    this->songName = songName;
}

const std::string& MusicFile::getSongName() const
{
    return songName;
}

void MusicFile::setYear(int year)
{
    this->year = year;
}

int MusicFile::getYear() const
{
    return year;
}

void MusicFile::setMusicExtension(MusicExtension musicExtension)
{
    this->musicExtension = musicExtension;
    setExtension(musicExtensionToString(musicExtension));
}

MusicExtension MusicFile::getMusicExtension() const
{
    return musicExtension;
}
