#include <iostream>
using namespace std;
#include "Survivor.h"
#pragma warning (disable: 4996)

bool Survivor::setName(const char* str)
{
	if (str == nullptr)
		return false;
	if (survivorName != nullptr)
		delete[]survivorName;
	survivorName = new char[strlen(str) + 1];
	strcpy(survivorName, str);
	return true;

}

Survivor::Survivor(const char* name, int age, Status status)
{
	survivorName = nullptr;
	bandana = nullptr;
	survivorTribe = nullptr;
	setName(name);
	setAge(age);
	setStatus((int)status);
}
Survivor::Survivor(const Survivor& survivor)
{
	survivorName = _strdup(survivor.survivorName);
	this->bandana = survivor.bandana;
	this->survivorTribe = survivor.survivorTribe;
	this->survivorAge = survivor.survivorAge;
	this->survivorStatus = survivor.survivorStatus;
}
Survivor::Survivor(Survivor&& survivor)
{
	this->survivorTribe = survivor.survivorTribe;
	survivor.survivorTribe = nullptr;
	this->survivorName = survivor.survivorName;
	this->bandana = survivor.bandana;
	survivor.bandana = nullptr;
	survivor.survivorName = nullptr;
	this->survivorAge = survivor.survivorAge;
	this->survivorStatus = survivor.survivorStatus;
}
Survivor::~Survivor()
{
	giveUpBandana();
	delete[]survivorName;
}

bool Survivor::giveUpBandana() 
{
	delete bandana;
	if (bandana == nullptr)
		return true;
	else
		return false;
}

bool Survivor::takeBandana(int len = 10)
{
	if (bandana != nullptr)
		giveUpBandana();
	bandana = new Bandana(this->getTribe().getTribeColor(),len);
	if (bandana != nullptr)
		return true;
	else
		return false;
}

bool Survivor::setAge(int sAge)
{
	if (survivorAge < 0)
	{
		cout << "age cannot be negative\n";
		return false;
	}
	else
	{
		survivorAge = sAge;
		cout << "age changed\n";
		return true;
	}
}

bool Survivor::setStatus(int s)
{
	if (s < 0 || sizeof(StatusStr)/sizeof(StatusStr[0]) <= s)
	{
		cout << "This status is illegal\n";
		return false;
	}
	else
	{
		survivorStatus = (Survivor::Status)s;
		cout << "Status changed\n";
		return true;
	}
}

void Survivor::printSurvivor()
{
	cout << "Survivor name is " << survivorName << endl;
	cout << "Survivor age is " << survivorAge << endl;
	cout << "Survivor Status is " << StatusStr[(int)survivorStatus] << endl;
	cout << endl;
}

char* Survivor::getName()
{
	return survivorName;
}

bool Survivor::setTribe(const Tribe* tribe)
{
	if (survivorTribe != tribe)
	{	
		this->giveUpBandana();
		survivorTribe = tribe;
		this->takeBandana();

	}
	return true;
}

const Tribe& Survivor::getTribe() const
{
	return *survivorTribe;
}

bool Survivor::removeTribe()
{
	if (survivorTribe == nullptr)
		return false;
	survivorTribe = nullptr;
	return true;
}



