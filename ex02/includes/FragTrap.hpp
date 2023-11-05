/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:25:54 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/05 10:07:50 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

//Fragtrap herite de claptrap
class FragTrap : public ClapTrap //public suffira
{
public:
	FragTrap( std::string name );//construcor name
	FragTrap( FragTrap const & src );//copy
	~FragTrap();

	FragTrap& operator=(FragTrap const &rhv);

	void	highFivesGuys() const;
	void	attack(std::string & target);
	
private:
	FragTrap();
};

#endif
