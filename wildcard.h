#ifndef WILDCARD_H
#define WILDCARD_H

class Wildcard : public Card
{
public: 
	Wildcard();
	Wildcard(int cColor) : Card(cColor);		//cardType is set to wildcard here

	virtual void setColor() =0;
	virtual void setName() =0;
	virtual void effect() =0;	//card effect, only +4 has it, typical wildcard (known as Colorcard here) doesn't have it, leave it blank

	~Wildcard();
};

#endif