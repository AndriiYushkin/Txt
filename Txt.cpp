#include "Txt.h"

l1::Txt::Txt(const Txt& txt)
{
	this->Size = txt.size();

	this->ArrFromFile = new std::string[Size];

	for (size_t i = 0; i < Size; i++)
	{
		this->ArrFromFile[i] = txt.ArrFromFile[i];
	}
};

l1::Txt& l1::Txt::operator=(const Txt& txt)
{
	if (this->ArrFromFile)
	{
		delete[] this->ArrFromFile;
	}

	this->Size = txt.size();

	this->ArrFromFile = new std::string[Size];

	for (size_t i = 0; i < Size; i++)
	{
		this->ArrFromFile[i] = txt.ArrFromFile[i];

	}
	return *this;
};

l1::Txt::Txt(Txt&& txt)
{
	this->Size = txt.size();
	this->ArrFromFile = txt.ArrFromFile;

	txt.ArrFromFile = nullptr;
	txt.set_size(0);
};

l1::Txt& l1::Txt::operator=(Txt&& txt)
{
	std::string* TempAdress = this->ArrFromFile;

	this->Size = txt.size();
	this->ArrFromFile = txt.ArrFromFile;

	txt.ArrFromFile = TempAdress;
	txt.set_size(0);

	return *this;
};

l1::Txt::Txt(const char* file)
{
	std::ifstream F(file, std::ios::in);
	if (!F)
	{
		return;
	}

	int count = 1;
	std::string temp;
	while (!F.eof())
	{
		getline(F, temp);	
		count++;
	}

	Size = count;

	ArrFromFile = new std::string[Size];

	F.clear();
	F.seekg(0, F.beg);

	int i = 0;
	while (!F.eof())
	{
		getline(F, ArrFromFile[i]);
		i++;
	}

	F.close();
};

l1::Txt::~Txt()
{
	if (this->ArrFromFile)
	{
		delete[] this->ArrFromFile;
	}
};