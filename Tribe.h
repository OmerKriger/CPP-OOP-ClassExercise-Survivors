#ifndef __TRIBE_H
#define __TRIBE_H
#include "Survivor.h"

class Survivor;
class Tribe
{
public:
	Tribe(const char* name, int size, const char* color);
	Tribe(const Tribe& tribe);
	Tribe(Tribe&& tribe);
	~Tribe();
	void createSurvivorArr();
	bool setSurvivorLeft(int k);
	bool setName(const char* s);
	bool setMaxAmount(int k);
	int getMaxAmount();
	bool addSurvivor(Survivor* survivor);
	bool removeSurvivor(const char* SurvivorName);
	void printTribe();
	int getSurvivorLeft();
	void deleteSurvivors();
	const char* getTribeColor() const { return color; }
private:
	char TribeName[20];
	int amountMax;
	char color[20];
	Survivor** SurvivorArr;
	int SurvivorLeft;
	int searchSurvivor(const char* SurvivorName);
};

#endif