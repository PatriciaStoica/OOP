#include "Repository.h"
#include "Tutorial.h"
#include "DynamicArray.h"

#include <iostream>
#include <string>
#include <exception>

Repository::Repository()
{
	DynamicArray<Tutorial> da;
	this->repo = da;
}

void Repository::add(Tutorial tutorial)
{
	for (int i = 0; i < this->repo.size(); i++)
	{
		Tutorial t = this->repo[i];
		if (t.getPresenter() == tutorial.getPresenter())
			throw exception("Tutorial already in repository");
	}
	this->repo.addDynamicArray(tutorial);
}

void Repository::remove(Tutorial tutorial)
{
	int position = -1;
	for(int i=0; i<this->repo.size(); i++)
		if (this->repo[i].getTitle() == tutorial.getTitle())
		{
			position = i;
			return;
		}
	if (position == -1)
		throw exception("Tutorial not in repository! ");
	else
		this->repo.removeDynamicArray(position);
}

Tutorial Repository::findTutorial(int index)
{
	return this->repo[index];
}

void Repository::update(string Title, int newNumberLikes)
{
	int ok = 0;
	for(int i=0; i<this->repo.size(); i++)
		if (this->repo[i].getTitle() == Title)
		{
			this->repo[i].setLikes(newNumberLikes);
			ok = 1;
			break;
		}
	if (ok == 0)
		throw exception("Tutorial not in repository");

}

int Repository::size()
{
	return this->repo.size();
}

DynamicArray<Tutorial> Repository::getAll()
{
	return this->repo;
}
