#pragma once

#include <string>
using namespace std;

class Tutorial
{
public:
	typedef struct {
			int minutes, seconds;
	}duration;

	Tutorial();
	~Tutorial();
	Tutorial(string &title, string &presenter, int minutes, int seconds, int numberLikes, const string& link);
	Tutorial(const Tutorial& other);
	Tutorial& operator=(const Tutorial& other);
	bool operator==(const Tutorial& other);
	string getTitle() const;
	string getPresenter() const;
	duration getDuration();
	int getNumberLikes();
	string getLink() const;
	void setTitle(const string &newTitle);
	void setPresenter(const string &newPresenter);
	void setDuration(int newMinutes, int newSeconds);
	void setLikes(int newNumberLikes);
	void setLink(const string& newLink);
private:
	string title, presenter, link;
	int numberLikes;
	duration d;
};