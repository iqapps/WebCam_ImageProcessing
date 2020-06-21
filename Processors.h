#pragma once

#include <unordered_map>
#include <typeindex>
#include "olcPixelGameEngine.h"
#include "Frame.h"

class Processor;

struct ProcessorInfo
{
	std::string name;
	std::function<void(std::vector<Processor*>*, olc::PixelGameEngine*)> func;
};

using typemap = std::unordered_map<std::type_index, ProcessorInfo>;

class Processor
{
public:
	Processor(olc::PixelGameEngine* gameArg, std::string nameArg)
	{
		game = gameArg;
		name = nameArg;
	}

	static typemap& registry();

	template <typename T>
	static void Create(std::vector<Processor*> *v, olc::PixelGameEngine* game)
	{
		v->push_back(new T(game));
	}

	virtual void ProcessImage(float fElapsedTime, frame &input, frame &output)
	{
		output = input;
	}

	virtual void ProcessKeys(float fElapsedTime) { }

	virtual std::string GetName()
	{
		return name;
	}

	virtual void DrawUI(int x, int y, int stepy) { }

protected:
	olc::PixelGameEngine* game;
private:
	std::string name;
};

typemap& Processor::registry() { static typemap impl; return impl; }

template <typename T> 
struct Registrar
{
	Registrar(ProcessorInfo info)
	{
		Processor::registry()[typeid(T)] = info;
	}
};
