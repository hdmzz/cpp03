/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:59:59 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/05 10:05:00 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*******************************************************************************
 * 							Constructor / Destructor
*******************************************************************************/

ClapTrap::ClapTrap( void ) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamages(0)
{
	std::cout << "Regular constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hitPoints(10), _energyPoints(10), _attackDamages(0)
{
	std::cout << "Name constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const &src )
{
	std::cout << "Copy constructor called" << std::endl;
	( *this ) = src;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap called " << this->_name << " destroyed" << std::endl;
	return ;
}

/*******************************************************************************
 * 							public member functoion
*******************************************************************************/

void	ClapTrap::attack( const std::string& target )
{
	if ( this->_energyPoints == 0 ) {
		std::cout << "ClapTrap " << this->_name << " has no energy points left" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack, cause he's dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDamages << " point of damage" << std::endl;
	this->_energyPoints -= 1;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if ( this->_energyPoints == 0 ) {
		std::cout << "ClapTrap " << this->_name << " has no energy points left" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " of damage" << std::endl;
	this->_hitPoints -= amount;
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if ( this->_energyPoints == 0 ) {
		std::cout << "ClapTrap " << this->_name << " has no energy points left" << std::endl;
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
