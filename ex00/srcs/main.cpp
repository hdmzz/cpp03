/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:13:11 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/31 13:58:19 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

int	main(void) {
	std::string trapName0 = "CT000";
	std::string trapName1 = "CT-42";

	ClapTrap	trap0(trapName0);
	ClapTrap	trap1(trapName1);

	trap0.beRepaired(0);
	for (int i = 0; i < 9; i++) {
		trap0.attack(trapName1);
		trap1.takeDamage(trap0.getAttackDamage());
	}
	trap0.attack(trapName1);
	trap1.takeDamage(5);
	trap1.beRepaired(4);
	trap1.attack(trapName0);
	trap0.takeDamage(5);
	trap0.beRepaired(5000);
	trap1.beRepaired(5000);
	trap1.attack(trapName1);
	trap1.takeDamage(5000);
	trap1.beRepaired(5000);
	trap1.takeDamage(1);
	return (0);
}
