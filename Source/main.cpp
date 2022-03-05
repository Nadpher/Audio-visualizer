#include "VideoManager.h"
#include "Recorder.h"

#include <iostream>

int main(int argc, char** argv)
{
	try
	{
		if (!nadpher::Recorder::isAvailable())
		{
			throw std::runtime_error("No available capture devices found.");
		}

		nadpher::Recorder recorder;

		recorder.start();
		while (nadpher::VideoManager::get_instance().get_window().isOpen())
		{
			sf::Event e;
			while (nadpher::VideoManager::get_instance().get_window().pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
				{
					nadpher::VideoManager::get_instance().force_quit();
				}
			}

			nadpher::VideoManager::get_instance().draw();
		}
		recorder.stop();
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}