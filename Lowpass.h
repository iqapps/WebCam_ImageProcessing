#pragma once

#include "Processors.h"

class Lowpass : public Processor
{
public:
	Lowpass(olc::PixelGameEngine* gameArg) : Processor(gameArg, "Lowpass") { }

	static Registrar<Lowpass> registrar;

	void ProcessKeys(float fElapsedTime)
	{
		// Respond to user input
		if (game->GetKey(olc::Key::DOWN).bHeld) fLowPassRC -= 0.1f * fElapsedTime;
		if (game->GetKey(olc::Key::UP).bHeld) fLowPassRC += 0.1f * fElapsedTime;
		if (fLowPassRC > 1.0f) fLowPassRC = 1.0f;
		if (fLowPassRC < 0.0f) fLowPassRC = 0.0f;
	}

	void ProcessImage(float fElapsedTime, frame& input, frame& output)
	{
		// Pass each pixel through a temporal RC filter
		for (int i = 0; i < nFrameWidth; i++)
		{
			for (int j = 0; j < nFrameHeight; j++)
			{
				float dPixel = input.get(i, j) - output.get(i, j);
				dPixel *= fLowPassRC;
				output.set(i, j, dPixel + output.get(i, j));
			}
		}
	}

	void DrawUI(int x, int y, int stepy)
	{
		game->DrawString(x, y, "Change RC constant with arrow UP and DOWN");
		game->DrawString(x, y + stepy, "Current value = " + std::to_string(fLowPassRC));
	}

private:
	float fLowPassRC = 0.1f;
};

Registrar<Lowpass> Lowpass::registrar(ProcessorInfo{ "Lowpass", Processor::Create<Lowpass> });