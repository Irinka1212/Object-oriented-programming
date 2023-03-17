#pragma once

class MyString
{
public:
	MyString(const char* str);
	MyString(const MyString& other);
	~MyString();
	MyString& operator=(const MyString& other);

	size_t size() const;
	void print() const;
	void append(char c);

	const char* get() const;

	bool operator==(const MyString& other);
	bool operator!=(const MyString& other);
	bool operator>(const MyString& other);
	bool operator<(const MyString& other);

private:
	char* _str;
	size_t _size;

	void copy(const MyString& other);
	// Return -1 if smaller, 0 if equal, 1 if bigger
	int compare(const MyString& other) const;
};
