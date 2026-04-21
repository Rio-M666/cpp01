#include "Zombie.hpp"

Zombie::Zombie(std::string name):name(name){
};

Zombie::~Zombie()
{
    std::cout<<this->name<<" destroyed"<<std::endl;
}
void Zombie::announce(void) const{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}