/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:59:59 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/09 03:26:21 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>


/*******************************************************************************
 * 							Constructor / Destructor
*******************************************************************************/

ClapTrap::ClapTrap( void ) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamages(0)
{
	std::cout << "ClapTrap Regular constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hitPoints(10), _energyPoints(10), _attackDamages(0)
{
	std::cout << "ClapTrap Name constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const &src )
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	( *this ) = src;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	return ;
}

/*******************************************************************************
 * 							public member functoion
*******************************************************************************/

void	ClapTrap::attack( const std::string & target )
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack: it is destroyed." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack: its battery is depleted." << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " and hits for " << this->_attackDamages << " damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " can't take anymore damage: it is already beyond repair!" << std::endl;
		return;
	}
	if ((int)this->_hitPoints - (int)amount <= 0)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage and is destroyed!" << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name
			<< " takes " << amount << " damage!" << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't repair itself: it is too severely damaged."  << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't repair itself: its battery is depleted and needs recharging." << std::endl;
		return ;
	}
	if (amount == 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name
			<< " wastes energy trying to repair itself when it is already in tip top shape." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " heals of " << amount << " points" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

/*******************************************************************************
 * 							Operator overload
*******************************************************************************/

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhv)
{
	if ( this != &rhv )
	{
		this->_name = rhv.getName();
		this->_attackDamages = rhv.getAttackDamage();
		this->_energyPoints = rhv.getEnergyPoints();
		this->_hitPoints = rhv.getHitPoints();
	}
	return ( *this );
}

/*******************************************************************************
						Getters
*******************************************************************************/

std::string	ClapTrap::getName( void ) const
{
	return ( this->_name );
}

int			ClapTrap::getHitPoints( void ) const
{
	return ( this->_hitPoints );
}

int			ClapTrap::getEnergyPoints( void ) const
{
	return ( this->_energyPoints );
}

int		ClapTrap::getAttackDamage( void ) const
{
	return ( this->_attackDamages );
}
