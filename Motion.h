#pragma once

#include "Processors.h"

class Motion : public Processor
{
public:
	Motion(olc::PixelGameEngine* gameArg) : Processor(gameArg, "Motion") { }

	static Registrar<Motion> registrar;

	void ProcessImage(float fElapsedTime, frame& input, frame& output)
	{
		for (int i = 0; i < nFrameWidth; i++)
		{
			for (int j = 0; j < nFrameHeight; j++)
			{
				output.set(i, j, fabs(input.get(i, j) - prev_input.get(i, j)));
			}
		}

		prev_input = input;
	}

	frame prev_input;
};

Registrar<Motion> Motion::registrar(ProcessorInfo{ "Motion", Processor::Create<Motion> });
