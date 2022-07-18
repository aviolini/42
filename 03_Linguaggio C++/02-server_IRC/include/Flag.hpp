#pragma once
#include <string>

class Flag
{
protected:
	unsigned char flag;
public:
	Flag():flag('\0'){}
	Flag(const unsigned char & flag):flag(flag){}
	Flag(const Flag & x):flag(x.getFlag()){}
	~Flag(){};
	Flag & operator=(const Flag & x)
	{
		this->flag = x.getFlag();
		return *this;
	} 

	const unsigned char & getFlag() const
	{
		return this->flag;
	}

	void setFlag(const unsigned char & flag)
	{
		this->flag |= flag;	
	}

	void clearFlag(const unsigned char & flag)
	{
		if (checkFlag(flag))
			this->flag ^= flag;		
	}

	void toggleFlag(const unsigned char & flag)
	{
		this->flag ^= flag;
	}

	bool checkFlag(const unsigned char & flag) const
	{
		if (this->flag & flag)
			return true;
		return false;
	}

	bool isReg() const
	{
		return this->checkFlag(1) && this->checkFlag(2) && this->checkFlag(4);
	}

	std::string printFlag() const
	{
		std::string resp;
		unsigned char mask = 0b10000000;
		for (int i = 0; i < 8; ++i)
		{
			if (this->flag & mask)
				resp += "1";
			else
				resp += "0";
			mask = mask >> 1;
		}
		return resp;
	}
};