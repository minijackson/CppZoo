#include "Zoo.h"

Zoo::Zoo(std::string fileName){
	if (!texture_.loadFromFile(fileName)){
		throw std::runtime_error("file not found");
	}
	background_.setTexture(texture_);
	background_.setOrigin(0.f,0.f);	
}

void Zoo::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(background_, states);
	for(const Animal& animal : animalList_){
		target.draw(animal, states);
	}
}

void Zoo::operator<<(Animal& animal){
	animalList_.push_back(animal);
}

