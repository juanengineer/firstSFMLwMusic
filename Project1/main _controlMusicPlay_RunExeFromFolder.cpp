#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

int main(int argc, char**) {
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Too Awesome for a Title");
	sf::Event event;

	sf::Music music;
	
	music.openFromFile("audio/Camilo-KESI.ogg");
	music.setVolume(50);
	music.play();

		while (renderWindow.isOpen()) {
			while (renderWindow.pollEvent(event)) {
				if (event.type == sf::Event::EventType::Closed)
					renderWindow.close();
				if (event.type == sf::Event::EventType::KeyPressed){
					auto newPos = music.getPlayingOffset() - sf::seconds(5);

					switch (event.key.code) {
						case (sf::Keyboard::Key::Up):
							//Up to control volume
							music.setVolume(music.getVolume() + 10);
							break;

						case (sf::Keyboard::Key::Down):
							//Down to control volume
							music.setVolume(music.getVolume() - 10);
							break;

						case (sf::Keyboard::Key::Left):
							//Left to control tracking position
							newPos = music.getPlayingOffset() - sf::seconds(5);
							if (newPos.asSeconds() <= 0.0f) newPos = sf::seconds(0);
							music.setPlayingOffset(newPos);
							break;

						case (sf::Keyboard::Key::Right):
							//Right to control tracking position
							newPos = music.getPlayingOffset() + sf::seconds(5);
							music.setPlayingOffset(newPos);
							break;
					}

					std::cout << "Current volume is: " << music.getVolume() << " position is: " << music.getPlayingOffset().asSeconds() <<std::endl;
				}
		
			}

			renderWindow.clear();
			renderWindow.display();
		}
}

/*
if (event.type == sf::Event::EventType::KeyPressed) {
	//Up and down to control volume
	if (event.key.code == sf::Keyboard::Key::Down)

}
*/

/*
switch (event.key.code) {
	case sf::Keyboard::Key::Up
		//Up to control volume
		music.setVolume(music.getVolume() + 10);
		break;
	case sf::Keyboard::Key::Down
		//Down to control volume
		music.setVolume(music.getVolume()-10);
		break;
	case sf::Keyboard::Key::Left
		//Left to control tracking position
		auto newPos = music.getPlayingOffset() - sf::seconds(5);
		if (newPos.asSeconds() <= 0.0f) newPos = sf::seconds(0);
		music.setPlayingOffset(newPos);
		break;
	case sf::Keyboard::Key::Right
		//Right to control tracking position
		auto newPos = music.getPlayingOffset() + sf::seconds(5);
		music.setPlayingOffset(newPos);
		break;
	default:
	//code block
}

std::cout << "Current volume is: " << music.getVolume() << " position is: "<<endl;
*/