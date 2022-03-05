#ifndef VISUALIZER_RECORDER_H
#define VISUALIZER_RECORDER_H

#include <SFML/Audio.hpp>

namespace nadpher
{
	class Recorder : public sf::SoundRecorder
	{
	public:

	private:
		virtual bool onStart() // optional
		{
			setProcessingInterval(sf::Time(sf::milliseconds(10)));

			return true;
		}

		virtual bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
	};
}

#endif

