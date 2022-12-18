#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

int main(int argc, char**) {
	sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "Too Awesome for a Title");
	sf::Event event;

	renderWindow.setFramerateLimit(60);
	sf::CircleShape pixel0;
	pixel0.setRadius(50);
	sf::Vector2f pixelPosition0(300, 100);
	pixel0.setPosition(pixelPosition0);		
	
	sf::CircleShape pixel1;
	pixel1.setRadius(50);
	sf::Vector2f pixelPosition1(500, 100);
	pixel1.setPosition(pixelPosition1);

	
	sf::CircleShape pixel2;
	pixel2.setRadius(50);
	sf::Vector2f pixelPosition2(700, 100);
	pixel2.setPosition(pixelPosition2);
	
	renderWindow.clear();
	
	renderWindow.draw(pixel0);
	renderWindow.draw(pixel1);
	renderWindow.draw(pixel2);
	renderWindow.display();

	//sf::RectangleShape rect;
	/*
	sf::CircleShape rect;
	sf::Vector2f rectanglePosition(10, 10);
	rect.setPosition(rectanglePosition);
	//rect.setSize(sf::Vector2f(100, 100));
	float radi = 100;
	rect.setRadius(radi);
	float xMove = 3;
	float yMove = 3;
	*/

	sf::Music music;
	music.openFromFile("audio/Camilo-KESI.ogg");
	music.setVolume(50);
	music.play();

		while (renderWindow.isOpen()) {
			auto curPos = music.getPlayingOffset().asSeconds();
			if (curPos > 4 && curPos < 5) {
				renderWindow.clear();
				renderWindow.draw(pixel0);
				renderWindow.display();
			}
			if (curPos > 8 && curPos < 9) {
				renderWindow.clear();
				renderWindow.draw(pixel1);
				renderWindow.display();
			}
			if (curPos > 12 && curPos < 13) {
				renderWindow.clear();
				renderWindow.draw(pixel2);
				renderWindow.display();
			}
			
			while (renderWindow.pollEvent(event)) {
				if (event.type == sf::Event::EventType::Closed)
					renderWindow.close();
				if (event.type == sf::Event::EventType::KeyPressed){
					
					auto newPos = music.getPlayingOffset() - sf::seconds(5);
					
					//render
					/*
					if (rectanglePosition.x < 0 || rectanglePosition.x > 1280 - 100) xMove *= -1;
					if (rectanglePosition.y < 0 || rectanglePosition.y > 720 - 100) yMove *= -1;

					rectanglePosition.x += xMove;
					rectanglePosition.y += yMove;
					rect.setPosition(rectanglePosition);
					*/

					renderWindow.clear();
					for (int i = 0; i < 3; i++) {
						//sf::Vector2f pixelPosition(10 + i * 10, 10);
						//pixel[0].setPosition(pixelPosition);
						//renderWindow.draw(pixel[i]);
					}
					//renderWindow.draw(pixel[0]);
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
						case (sf::Keyboard::Key::Num1):
							//Hit 1 key
							renderWindow.clear();
							renderWindow.draw(pixel0);
							renderWindow.display();
							break;
						case (sf::Keyboard::Key::Num2):
							//Hit 2 key
							renderWindow.clear();
							renderWindow.draw(pixel1);
							renderWindow.display();
							break;
						case (sf::Keyboard::Key::Num3):
							//Hit 3 key
							renderWindow.clear();
							renderWindow.draw(pixel2);
							renderWindow.display();
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