#include "Media.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


istream& Media::ReadData(istream& input)
{
	input >> identifier;
	getline(input, accountName);
	input >> timeInSeconds;
	return input;
}
ostream& Media::WriteData(ostream& output)
{
	output << "ID is " << identifier << endl;
	output << "Account name is " << accountName << endl;
	output << "Time is " << timeInSeconds << endl;
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
	getline(input, accountName);
	input >> timeInSeconds;
	getline(input,resolution);
	getline(input, formatDescriptor);
	getline(input,specification);
	return input;
}

ostream& Video::WriteData(ostream& output)
{
	WriteData(output);
	output << "Resolution is " << resolution;
	output << "Format descriptor is " << formatDescriptor;
	output << "Specification is " << specification;
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
	ReadData(input);
	input >> descriptor;
	input >> specification;
	return input;
}
ostream& Audio::WriteData(ostream& output)
{
	WriteData(output);
	output << descriptor;
	output << specification;
	return output;
}