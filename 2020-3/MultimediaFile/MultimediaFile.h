#pragma once
#include <string>
#include <iostream>
#include <vector>

class MultimediaFile
{
public:
	MultimediaFile() : _size(0) {}
	MultimediaFile(const std::string& name, int size, const std::string& extension)
		: _name(name), _size(size), _extension(extension) {}

	std::string getName() const { return _name; }
	int getSize() const { return _size; }
	std::string getExtension() const { return _extension; }

	void setName(const std::string& name) { _name = name; }
	void setSize(int size) { _size = size; }
	void setExtension(const std::string& extension) { _extension = extension; }

	 virtual void print_debug_state() const 
	{
		std::cout << getName() << " " << getSize() << " " << getExtension() << '\n';
	}

protected:
	std::string _name;
	int _size;
	std::string _extension;
};

class Audio : virtual public MultimediaFile
{
public:
	Audio() : MultimediaFile(), _lenght(0) {}
	Audio(const std::string& name, int size, const std::string& extension, int lenght, const std::string& artist)
		: MultimediaFile(name, size, extension), _lenght(lenght), _artist(artist) {}

	int getLenght() const { return _lenght; }
	std::string getArtist() const { return _artist; }

	void setLenght(int lenght) { _lenght = lenght; }
	void setArtist(const std::string& artist) { _artist = artist; }

	void print_debug_state() const override
	{
		std::cout<< getName() << " " << getSize() << " " << getExtension() << " " << getLenght() << " " << getArtist() << '\n';
	}

	void play() const
	{
		std::string answer;
		std::cout << "Visualistion yes or no\n";
		std::cin >> answer;

		if (answer == "yes")
		{
			std::cout << " visualisation on\n";
		}
		else if (answer == "no")
		{
			std::cout << " visualisation off\n";
		}
		else
			std::cout << "invalid answer\n";
	}
private:
	int _lenght;
	std::string _artist;
};

class Video : virtual public MultimediaFile
{
public:
	Video(): MultimediaFile() {}
	Video(const std::string& name, int size, const std::string& extension, const std::string& subtitles, const std::vector<Audio> audioSources)
		: MultimediaFile(name, size, extension), _subtitles(subtitles), _audioSources(audioSources) {}

	std::string getSubtitles() const { return _subtitles; }
	std::vector<Audio> getAudioSources() const { return _audioSources; }

	void setSubtitles(const std::string& subtitles) { _subtitles = subtitles; }
	void setAudioSources(const std::vector<Audio> audioSources) { _audioSources = audioSources; }

	void print_debug_state() const override
	{
		std::cout << getName() << " " << getSize() << " " << getExtension() << " " << getSubtitles() << '\n';
		Video::getAudioSources();
	}
private:
	std::string _subtitles;
	std::vector<Audio> _audioSources;
};

class Streaming : virtual public MultimediaFile
{
public:
	Streaming() : MultimediaFile() {}
	Streaming(const std::string& name, int size, const std::string& extension, const std::string& wayToSource)
		: MultimediaFile(name, size, extension), _wayToSource(wayToSource) {}

	std::string getWayToSource() const { return _wayToSource; }

	void setWayToSource(const std::string& wayToSource) { _wayToSource = wayToSource; }

	void print_debug_state() const override
	{
		std::cout << getName() << " " << getSize() << " " << getExtension() << " " << getWayToSource() << '\n';

	}

private:
	std::string _wayToSource;
};

class MultimediaPlayer
{
private:
	std::vector<MultimediaFile*> _files;

public:
	MultimediaPlayer() {};
	std::vector<MultimediaFile*> getFiles() const { return _files; }

	void addFile(MultimediaFile* file)
	{
		_files.push_back(file);
	}
	void removeFile(MultimediaFile* file)
	{
		for (int i = 0; i < _files.size(); ++i)
		{
			if (_files[i]->getName().compare(file->getName()) == 0)
			{
				_files.erase(_files.begin() + i);
				return;
			}
		}
	}

	void print_all_files_states(int position)//when position = size
	{
		for (int i = 0; i < _files.size(); ++i)
		{
			if (position == i)
			{
				Audio* audioFile = dynamic_cast<Audio*>(_files[i]);
				if (audioFile)
					audioFile->play();
			}
		}
	}
};