/*猫狗队列*/

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cassert>
#include <string>

using namespace std;

class Pet{
private:
	string type;
public:
	Pet(string t) :type(t){}
	string getPetType()
	{
		return type;
	}
};

class Cat : public Pet{
public:
	Cat() :Pet("Cat"){}
};

class Dog : public Pet{
public:
	Dog() :Pet("Dog"){}
};

class PetElem{
private:
	Pet pet;
	int timeCount;

public:
	PetElem(Pet pet, int t) :pet(pet), timeCount(t)
	{}

	Pet getPet()
	{
		return pet;
	}

	int getTimeCount()
	{
		return timeCount;
	}

	string getPetType()
	{
		return pet.getPetType();
	}
};

class PetQueue{
private:
	queue<PetElem> dogQ;
	queue<PetElem> catQ;
	int timeCount;

public:
	PetQueue() :timeCount(0){}

	void add(Pet pet)
	{
		if (pet.getPetType() == "Dog")
			dogQ.push(PetElem(pet, this->timeCount++));
		else if (pet.getPetType() == "Cat")
			catQ.push(PetElem(pet, this->timeCount++));
		else
			return;
	}

	Dog popDog()
	{
		assert(!dogQ.empty());
		
		/*基类对象不可转换为子类对象*/
		Dog dog /*= static_cast<Dog>(dogQ.front().getPet())*/;
		dogQ.pop();
		return dog;
		
	}

	Cat popCat()
	{
		assert(!catQ.empty());

		Cat cat /*= (Cat)(catQ.front().getPet())*/;
		catQ.pop();
		return cat;
	}
	Pet popAny()
	{
		assert(this->dogQ.empty() && this->catQ.empty());

		if (!dogQ.empty() && !catQ.empty()){
			if (dogQ.front().getTimeCount() < catQ.front().getTimeCount())
			{
				return popDog();
			}//if
			else{
				return popCat();
			}//else
		}//elif
		else if (!dogQ.empty())
			return popDog();
		else 
			return popCat();		
	}

	bool isEmpty()
	{
		return dogQ.empty() && catQ.empty();
	}

	bool isDogQEmpty()
	{
		return dogQ.empty();
	}

	bool isCatQEmpty()
	{
		return catQ.empty();
	}
};
