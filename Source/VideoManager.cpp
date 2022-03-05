#include "VideoManager.h"

#include "AudioManager.h"

namespace nadpher
{
	void VideoManager::draw()
	{
		m_window.clear();

		AudioManager::AudioData data = AudioManager::get_instance().get_audio_data();

		sf::VertexArray vertexArray = sf::VertexArray(sf::LineStrip, data.sampleCount);
		for (int i = 0; i < data.sampleCount; ++i)
		{
			vertexArray[i].color = sf::Color(255, 255, 255, 255);
			
			sf::Vector2u windowSize = m_window.getSize();

			float xPos = (i + 1) * (float)windowSize.x / (float)data.sampleCount;

			float mappedSample = data.samples[i] / (float)windowSize.y;
			float yPos = windowSize.y / 2.0f + mappedSample;

			m_window.getSize().x;
			vertexArray[i].position = sf::Vector2f(xPos, yPos);

		}
		m_window.draw(vertexArray);

		m_window.display();
	}

}