#pragma once

#include "Processor.h"

class Median : public Processor
{
public:
	Median(olc::PixelGameEngine* gameArg) : Processor(gameArg, "Median") { }

	static Registrar<Median> registrar;

	void ProcessImage(float fElapsedTime, frame& input, frame& output)
	{
		float v[25];
		int n = sizeof(v) / sizeof(v[0]);

		for (int i = 0; i < nFrameWidth; i++)
		{
			for (int j = 0; j < nFrameHeight; j++)
			{
				int ii = 0;
				for (int n = -2; n < +3; n++)
				{
					for (int m = -2; m < +3; m++)
					{
						v[ii++] = input.get(i + n, j + m);
					}
				}

				std::sort(v, v+n);
				output.set(i, j, v[12]);
			}
		}
	}
};

Registrar<Median> Median::registrar(ProcessorInfo{ "Median", Processor::Create<Median> });
