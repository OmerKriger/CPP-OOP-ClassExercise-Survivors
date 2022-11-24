#ifndef __SURVIVOR_H
#define __SURVIVOR_H

#include "Bandana.h"
#include "Tribe.h"
static const char* StatusStr[] = { "single","married","relation" };

class Survivor
{
public:
	enum class Status { Single, Married,Relation };
	Survivor(const char* name,int age, Status status);
	Survivor(const Survivor& survivor);
	Survivor(Survivor&& survivor);
	~Survivor();
	bool setStatus(int s);
	bool setName(const char* s);
	char* getName();
	bool setAge(int sAge);
	void printSurvivor();
	bool setTribe(const Tribe* tribe);
	const Tribe& getTribe() const;
	bool removeTribe();

private:
	bool giveUpBandana();
	bool takeBandana(int len);
	char* survivorName;
	int survivorAge;
	const Tribe* survivorTribe;
	Status survivorStatus;
	Bandana* bandana;
};

#endif
