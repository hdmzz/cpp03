/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:52:11 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/31 13:56:44 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
public:
	ClapTrap( void );//construcor classique
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const& src );//constructor de copy
	~ClapTrap();//destructor

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	//getters utils
	std::string	getName( void ) const;
	int			getHitPoints( void ) const;
	int			getEnergyPoints( void ) const;
	int			getAttackDamage( void ) const;

	// operator = surcharge
	ClapTrap&	operator=(ClapTrap const &rhv);
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamages;
};

#endif
