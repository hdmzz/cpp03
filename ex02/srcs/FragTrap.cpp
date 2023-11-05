/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:25:46 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/05 10:18:56 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/******************************************************************************
 * 							Constructor destructor 
******************************************************************************/
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default construcor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamages = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap default construcor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamages = 30;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap called " << this->_name << " is destroyed" << std::endl;
	return ;
}

/******************************************************************************
 * 							Operator 
******************************************************************************/

FragTrap& FragTrap::operator=(FragTrap const &rhv)//operateur d'assignation
{
	if ( this != &rhv )
	{
		this->_name = rhv.getName();
		this->_hitPoints = rhv.getHitPoints();
		this->_energyPoints = rhv.getEnergyPoints();
		this->_attackDamages = getAttackDamage();
	}
	return ( *this );
}

/******************************************************************************
 * 							Member function 
******************************************************************************/

void	FragTrap::highFivesGuys() const
{
	if (this->_energyPoints == 0)
		std::cout << this->_name << " can't do anything cause it got no energy points left" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << this->_name << " can't do anything cause its dead" << std::endl;
	std::cout << this->_name << " High Five" << std::endl;
	return ;
}

void		FragTrap::attack(std::string & target)
{
	if ( this->_energyPoints == 0 ) {
		std::cout << "FragTrap " << this->_name << " has no energy points left" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't attack, cause he's dead" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDamages << " point of damage" << std::endl;
	this->_energyPoints -= 1;
	return ;
}
