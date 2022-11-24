#include <iostream>
using namespace std;
#include "Survivor.h"
#include "Tribe.h"
void fillTribeInSurvivors(Tribe* tribe);
char* setName();
void getTribeName(char* tName);
int setAge();
Survivor::Status setStatus();
char* getColorForTribe(const char* tName);
void cleanBuffer();
Survivor* makeSurvivor();
void freeTribe(Tribe* tribe);
int main()
{ 
	int size;
	cout << "How many Survivor in every Tribe ?\n";
	cin >> size;
	(void)getchar();
	char tName1[20], tName2[20];
	getTribeName(tName1);
	char* colorTribe1 = getColorForTribe(tName1);
	getTribeName(tName2);
	char* colorTribe2 = getColorForTribe(tName2);
	Tribe Tribe1(tName1, size, colorTribe1), Tribe2(tName2, size, colorTribe2);
	fillTribeInSurvivors(&Tribe1);
	fillTribeInSurvivors(&Tribe2);
	
	cout << "\n\n !! Tribes filled !! \n\n";

	Tribe1.printTribe();
	Tribe2.printTribe();
	freeTribe(&Tribe1);
	freeTribe(&Tribe2);
}

void fillTribeInSurvivors(Tribe* tribe)
{
	int size = (tribe->getMaxAmount());
	for (int i = 0; i < size ; i++)
	{
		int answer;
		cout << "Do you want to finish add survivor ? 1 for yes, any key for no\n answer: ";
		cin >> answer;
		if (answer == 1)
			break;
		Survivor* pSurvivor = makeSurvivor();
		if (pSurvivor == nullptr)
		{
			i--;
			continue;
			cout << "Failed to create Survivor, trying again";
		}
		tribe->addSurvivor(pSurvivor);
	}
}

Survivor* makeSurvivor()
{
	int age = setAge();
	char* name = setName();
	Survivor::Status status = setStatus();
	Survivor* pSurvivor = new Survivor(name,age,status);
	return pSurvivor;
}

void getTribeName(char* tName)
{
	cout << "Enter name for tribe" << endl;
	cin.getline(tName, 20);
	cout << "Name for tribe is " << tName << endl;
}

char* getColorForTribe(const char* tName)
{
	char* color = nullptr;
	cout << "Enter color for tribe (max 20 chars)"<< tName << ": ";
	cin.getline(color, 20);
	cout << "The color of tribe " << tName << " is " << color << endl;
	return color;
}

int setAge()
{
	int age;
	do
	{
		cout << "enter age of survivor (netural number)" << endl;
		cin >> age;
		(void)getchar();
	} while (age<0);
	return age;
}

char* setName()
{
	char name[256];
	cout << "enter name of survivor (Max 255 chars)" << endl;
	cin.getline(name, 256);
	return _strdup(name);
}

Survivor::Status setStatus()
{
	int s;
	do
	{
		cout << "enter status of survivor" << endl << "0 - for single\n1 - for married \n2 - for relation\n";
		cin >> s;
		(void)getchar();
	} while (s < 0 || sizeof(StatusStr) / sizeof(StatusStr[0]) <= s);
	return (Survivor::Status)s;
}

void printTribe(Survivor** pTribe, int lSize)
{
	for (int i=0; i < lSize; i++)
	{
		cout << "Member 1: \n";
		pTribe[i]->printSurvivor();
	}
}

void freeTribe(Tribe* pTribe)
{
		pTribe->deleteSurvivors();
}

void cleanBuffer()
{
	char c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}
