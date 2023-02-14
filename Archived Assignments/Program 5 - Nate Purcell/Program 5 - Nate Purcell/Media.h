#pragma once
#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Media
{
public:
	virtual ~Media() { }
	void setIdentifier(string id) { identifier = id; }
	void setAccountName(string name) { accountName = name; }
	void setTime(int s) { timeInSeconds = s; }
	string getIdentifier() { return identifier; }
	string getAccountName() { return accountName; }
	int getTimeInSeconds() { return timeInSeconds; }
	virtual string getType() const = 0;
	virtual istream& ReadData(istream& input);
	virtual ostream& WriteData(ostream& output);
protected:
	string identifier;
	string accountName;
	int timeInSeconds;
};

class Video: public Media
{
private:
	string resolution;
	string formatDescriptor;
	string specification;
public:
	Video();
	Video(string newResolution, string newFormatDescriptor, string newSpecification);
	string getResolution() { return resolution; }
	string getFormatDescriptor() { return formatDescriptor; }
	string getSpecification() { return specification; }
	string getType() const override;
	istream& ReadData(istream& input);
	ostream& WriteData(ostream& output);
};

class Audio: public Media
{
private:
	string descriptor;
	string specification;
public:
	Audio();
	Audio(string newDescriptor, string newSpecification);
	string getDescriptor() { return descriptor; }
	string getSpecification() { return specification;  }
	string getType() const override;
	istream& ReadData(istream& input);
	ostream& WriteData(ostream& output);
};
#endif
