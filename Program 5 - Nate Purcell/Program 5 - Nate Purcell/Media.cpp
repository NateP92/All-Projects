#include "Media.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


istream& Media::ReadData(istream& input)
{
	input >> identifier;
	input.ignore();
	getline(input, accountName);
	input >> timeInSeconds;
	return input;
}
ostream& Media::WriteData(ostream& output)
{
	output << identifier << endl;
	output << accountName << endl;
	output << timeInSeconds << endl;
	return output;
}

Video::Video()
{
	identifier = "";
	accountName = "";
	timeInSeconds = 0;
	resolution = "";
	formatDescriptor = "";
	specification = "";
}
Video::Video(string newResolution, string newFormatDescriptor, string newSpecification) 
{
	resolution = newResolution;
	formatDescriptor = newFormatDescriptor;
	specification = newSpecification;
}
string Video::getType() const
{
	return "Video";
}
istream& Video::ReadData(istream& input)
{
	input >> identifier;
	input.ignore();
	getline(input, accountName);
	input >> timeInSeconds;
	input >> resolution;
	input >> formatDescriptor;
	input.ignore();
	getline(input, specification);
	return input;
}
ostream& Video::WriteData(ostream& output)
{
	output << identifier << endl;
	output << accountName << endl;
	output << timeInSeconds << endl;
	output << resolution << endl;
	output << formatDescriptor << endl;
	output << specification << endl;
	output << "*****************************" << endl;
	return output;
}

Audio::Audio()
{
	identifier = "";
	accountName = "";
	timeInSeconds = 0;
	descriptor = "";
	specification = "";
}
Audio::Audio(string newDescriptor, string newSpecification)
{
	descriptor = newDescriptor;
	specification = newSpecification;
}
string Audio::getType() const
{
	return "Audio";
}
istream& Audio::ReadData(istream& input)
{
	input >> identifier;
	input.ignore();
	getline(input, accountName);
	input >> timeInSeconds;
	input >> descriptor;
	input.ignore();
	getline(input, specification);
	return input;
}
ostream& Audio::WriteData(ostream& output)
{
	output << identifier << endl;
	output << accountName << endl;
	output << timeInSeconds << endl;
	output << descriptor << endl;
	output << specification << endl;
	output << "*****************************" << endl;
	return output;
}

