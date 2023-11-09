/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:25:54 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/09 04:16:21 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( FragTrap const & src );
	~FragTrap();

	FragTrap& operator=(FragTrap const &rhv);

	void	highFivesGuys() const;
	void	attack(std::string & target);
};

#endif
