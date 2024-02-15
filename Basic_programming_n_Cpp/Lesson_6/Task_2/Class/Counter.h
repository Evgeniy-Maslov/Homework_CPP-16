#pragma once

class Counter
{
	int count;
public:
	Counter();
	Counter(int);
	void action_Counter();
private:
	void calculation_Counter(int&, std::string);
};