#ifndef __BANDANA_H
#define __BANDANA_H

class Bandana
{
public:
	Bandana() = delete;
	Bandana(const char* color, int len);
	const char* getColor() const { return color; }
	int getLen() const { return length;  }
private:

	bool setColor(const char* color);
	bool setLen(int len);
	char color[20];
	int length;
};

#endif