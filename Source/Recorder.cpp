#include "Recorder.h"
#include "AudioManager.h"

namespace nadpher
{
	bool Recorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
	{
		AudioManager::get_instance().update_audio_data({ samples, sampleCount });
		return true;
	}
}