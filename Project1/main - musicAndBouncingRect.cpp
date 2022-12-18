#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

int main(int argc, char**) {
	sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "Too Awesome for a Title");
	sf::Event event;

	renderWindow.setFramerateLimit(60);
	sf::RectangleShape rect;
	sf::Vector2f rectanglePosition(600, 350);
	rect.setPosition(rectanglePosition);
	rect.setSize(sf::Vector2f(100, 100));
	float xMove = 3;
	float yMove = 3;


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
					
					//render
					if (rectanglePosition.x < 0 || rectanglePosition.x > 1280 - 100) xMove *= -1;
					if (rectanglePosition.y < 0 || rectanglePosition.y > 720 - 100) yMove *= -1;

					rectanglePosition.x += xMove;
					rectanglePosition.y += yMove;
					rect.setPosition(rectanglePosition);
					renderWindow.clear();
					renderWindow.draw(rect);
					renderWindow.display();
			
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

			//render
			/*
			renderWindow.clear();
			window.draw(rect);
			renderWindow.display();
			*/
		}
		return 0;
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