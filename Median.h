#pragma once

#include "Processors.h"

class Median : public Processor
{
public:
	Median(olc::PixelGameEngine* gameArg) : Processor(gameArg, "Median") { }

	static Registrar<Median> registrar;

	void ProcessImage(float fElapsedTime, frame& input, frame& output)
	{
		for (int i = 0; i < nFrameWidth; i++)
		{
			for (int j = 0; j < nFrameHeight; j++)
			{
				std::vector<float> v;

				for (int n = -2; n < +3; n++)
				{
					for (int m = -2; m < +3; m++)
					{
						v.push_back(input.get(i + n, j + m));
					}
				}

				std::sort(v.begin(), v.end(), std::greater<float>());
				output.set(i, j, v[12]);
			}
		}
	}
};

Registrar<Median> Median::registrar(ProcessorInfo{ "Median", Processor::Create<Median> });
