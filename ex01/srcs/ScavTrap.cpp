/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:24:13 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/05 10:06:56 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/*******************************************************************************
 * 								Constructor Destructor
*******************************************************************************/

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamages = 20;
	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap Name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamages = 20;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap()
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap called " << this->getName() << " is destroyed" << std::endl;
	return ;
}

/*******************************************************************************
 * 								operator overload
*******************************************************************************/

ScavTrap&	ScavTrap::operator=( ScavTrap const &rhv )
{
	if (this != &rhv)
	{
		ClapTrap::operator=(rhv);
	}
	return ( *this );
}

/*******************************************************************************
 * 								Member function
*******************************************************************************/

void		ScavTrap::guardGate( void ) const
{
	std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode" << std::endl;
	return ;
}

void		ScavTrap::attack(std::string & target)
{
	if ( this->_energyPoints == 0 ) {
		std::cout << "ScavTrap " << this->_name << " has no energy points left" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack, cause he's dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDamages << " point of damage" << std::endl;
	this->_energyPoints -= 1;
	return ;
}
