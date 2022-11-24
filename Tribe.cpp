#include <iostream>
using namespace std;
#include "Survivor.h"
#include "Tribe.h"
#define NOT_FOUND -1

#pragma warning (disable: 4996)

Tribe::Tribe(const char* name, int size, const char* color)
{
	TribeName[0] = '\0';
	SurvivorArr = nullptr;
	strcpy(this->color,color);
	setSurvivorLeft(0);
	setMaxAmount(size);
	setName(name);
	createSurvivorArr();
}
Tribe::Tribe(const Tribe& tribe)
{
	SurvivorArr = nullptr;
	setName(tribe.TribeName);
	setSurvivorLeft(tribe.SurvivorLeft);
	setMaxAmount(tribe.amountMax);
	createSurvivorArr();
	for (int i = 0; i < SurvivorLeft; i++)
	{
		this->SurvivorArr[i] = new Survivor(*tribe.SurvivorArr[i]);
	}
}
Tribe::Tribe(Tribe&& tribe)
{
	SurvivorArr = nullptr;
	strcpy(TribeName,tribe.TribeName);
	setSurvivorLeft(tribe.SurvivorLeft);
	setMaxAmount(tribe.amountMax);
	SurvivorArr = tribe.SurvivorArr;
	tribe.SurvivorArr = nullptr;
}
Tribe::~Tribe()
{
	deleteSurvivors();
}

void Tribe::createSurvivorArr()
{
	if (SurvivorArr != nullptr)
	{
		cout << "Create Survivor Array is unable, there is array already\n";
	}
	else
		SurvivorArr = new Survivor * [amountMax];
}
bool Tribe::setName(const char* s)
{
	if (strlen(s) < 20)
	{
		if (TribeName[0] == '\0')
			cout << "Name has been set\n";
		else
			cout << "Name has been changed\n";
		strcpy(TribeName, s);
		return true;
	}
	else
	{
		cout << "Name has not changed/set !\n";
		return false;
	}
}
bool Tribe::setMaxAmount(int k)
{
	if (k < 0)
		return false;
	else
	{
		amountMax = k;
		return true;
	}
}
int Tribe::getMaxAmount()
{
	return amountMax;
}
int Tribe::getSurvivorLeft()
{
	return SurvivorLeft;
}
bool Tribe::setSurvivorLeft(int k)
{
	if (k < 0)
		return false;
	else
	{
		SurvivorLeft = k;
		return true;
	}
}
void Tribe::printTribe()
{
	cout << "Printing Tribe details: " << endl;
	cout << "Tribe Name is " << TribeName << endl;
	cout << "Tribe max members is " << amountMax << endl;
	cout << "Tribe members left is " << SurvivorLeft << endl;
	cout << "Tribe members: \n";
	for (int i = 0; i < SurvivorLeft; i++)
	{
		cout << "Survivor number #" << i + 1 << endl;
		SurvivorArr[i]->printSurvivor();
		cout << endl;
	}
}
bool Tribe::removeSurvivor(const char* SurvivorName)
{
	int index = searchSurvivor(SurvivorName);
	if (index == NOT_FOUND)
		return false;
	else
	{
		delete SurvivorArr[index];
		for (int i = index; i < SurvivorLeft-1; i++)
		{
			SurvivorArr[index] = SurvivorArr[index + 1];
		}
		SurvivorLeft--;
		return true;
	}
}
int Tribe::searchSurvivor(const char* SurvivorName)
{
	for (int i = 0; i < SurvivorLeft; i++)
	{
		if (strcmp(SurvivorArr[i]->getName(), SurvivorName) == 0)
			return i;
	}
	return NOT_FOUND;
}
void Tribe::deleteSurvivors()
{
	int size = getSurvivorLeft();
	for (int i = 0; i < size; i++)
		delete SurvivorArr[i];
	delete[]SurvivorArr;
}
bool Tribe::addSurvivor(Survivor* survivor)
{
	if (this->SurvivorLeft >= this->amountMax)
		return false;
	else if (survivor == nullptr)
		return false;
	else
	{
		this->SurvivorArr[SurvivorLeft] = survivor;
		this->SurvivorLeft++;
		survivor->setTribe(this);
		return true;
	}
}
