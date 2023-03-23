#pragma once
#include <iostream>
#include <fstream>
#include <String>
namespace l1 {

	class Txt 
	{
	public:
		Txt(){};
		Txt(const Txt& txt);
		Txt& operator=(const Txt& txt);
		Txt(Txt&& txt);
		Txt& operator=(Txt&& txt);
		Txt(const char* file);

		size_t size() const { return Size; };

		void set_size(size_t insize) { this->Size = insize; }

		~Txt();

	private:
		size_t Size = 0;
		std::string* ArrFromFile = nullptr;
	};










}