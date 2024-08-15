#include "Animation.h"
#include <iostream>
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;	
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation() {
	
}
void Animation::Update(int row, float deltaTime)
{
	currentImage.y = row; // 0
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime; 
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	std::cout << uvRect.left << std::endl;
	uvRect.top = currentImage.y * uvRect.height;
}	