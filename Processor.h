#pragma once

#include <unordered_map>
#include <typeindex>
#include "olcPixelGameEngine.h"
#include "Frame.h"

class Processor;

struct ProcessorInfo
{
	std::string name;
	std::function<Processor* ()> func;
};

using typemap = std::unordered_map<std::type_index, ProcessorInfo>;

class Processor
{
public:
	Processor(std::string nameArg)
	{
		name = nameArg;
	}

	static typemap& registry();

	template <typename T>
	static T* Create() { return new T(); }

	static void SetEngine(olc::PixelGameEngine* engine) { game = engine; }

	virtual void ProcessImage(float fElapsedTime, frame &input, frame &output) { output = input; }
	virtual void ProcessKeys(float fElapsedTime) { }
	virtual std::string GetName() { return name; }
	virtual void DrawUI(int x, int y, int stepy) { }

protected:
	static olc::PixelGameEngine* game;
private:
	std::string name;
};

olc::PixelGameEngine* Processor::game;
typemap& Processor::registry() { static typemap impl; return impl; }

template <typename T> 
struct Registrar
{
	Registrar(ProcessorInfo info)
	{
		Processor::registry()[typeid(T)] = info;
	}
};
