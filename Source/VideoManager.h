#ifndef VISUALIZER_VIDEO_MANAGER_H
#define VISUALIZER_VIDEO_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace nadpher
{
	class VideoManager
	{
	public:
		static VideoManager& get_instance()
		{
			static VideoManager* instance = new VideoManager();
			return *instance;
		}

		sf::RenderWindow& get_window() { return m_window; }

		void force_quit() { m_window.close(); };
		
		void draw();

	private:
		sf::RenderWindow m_window;

		VideoManager() : m_window(sf::VideoMode(800, 600), "Visualizer") { }
	};
}

#endif

