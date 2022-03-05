#ifndef VISUALIZER_AUDIO_MANAGER_H
#define VISUALIZER_AUDIO_MANAGER_H

#include <SFML/Audio.hpp>

namespace nadpher
{
	class AudioManager
	{
	public:
		struct AudioData
		{
			const sf::Int16* samples;
			std::size_t sampleCount;
		};

		static AudioManager& get_instance() 
		{
			static AudioManager* instance = new AudioManager();
			return *instance;
		}

		const AudioData& get_audio_data() { return m_audioData; };
		void update_audio_data(AudioData data) { m_audioData = data; }

	private:
		AudioManager() { }

		AudioData m_audioData = {};
	};
}

#endif
