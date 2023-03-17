#pragma once
#include <string>

enum State { low = 1, medium = 3, high = 5 };

class Vehicle
{
public:
	Vehicle(const std::string& brand, const std::string& model, int year, const std::string& problem, State state)
		: _brand(brand), _model(model), _year(year), _problem(problem), _state(state) {}

	std::string getBrand() const { return _brand; }
	std::string getModel() const { return _model; }
	int getYear() const { return _year; }
	std::string getProblem() const { return _problem; }
	State getState() const { return _state; }

	void setBrand(std::string brand) { _brand = brand; }
	void setModel(std::string model) { _model = model; }
	void setYear(int year) { _year = year; }
	void setProblem(std::string problem) { _problem = problem; }
	void setState(State state) { _state = state; }

protected:
	std::string _brand;
	std::string _model;
	int _year;
	std::string _problem;
	State _state;
};