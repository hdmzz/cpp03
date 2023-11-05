/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:13:11 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/05 09:46:54 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>

int	main(void) {
	std::string trapName0 = "CT000";
	std::string trapName1 = "CT-42";
	std::string scavTrapName0 = "SCT078";
	std::string scavTrapName1 = "SCT-45";

	ClapTrap	trap0(trapName0);
	ClapTrap	trap1(trapName1);
	ClapTrap	cpyClap(trap1);

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

	std::cout << "Copy Clap" << std::endl;

	cpyClap.takeDamage(10);
	cpyClap.attack(trapName0);

	std::cout << "Copy Clap become assignement Clap" << std::endl;
	cpyClap = trap0;

	std::cout << "cpyclap talking : my name is " << cpyClap.getName() << std::endl;

	std::cout << "Same thing with ScavTrap + special ScavTrap" << std::endl;

	ScavTrap	scav0(scavTrapName0);
	ScavTrap	scav1(scavTrapName1);

	for (int i = 0; i < 5; i++) {
		scav1.guardGate();
		scav0.attack(scavTrapName1);
		scav1.takeDamage(scav0.getAttackDamage());
	}
	scav1.beRepaired(5000);
	scav1.takeDamage(2000);
	scav0.guardGate();

	std::cout << "Same thing with FragTrap + special FragTrap" << std::endl;


	FragTrap	frag1 = FragTrap("Frag 1");
	FragTrap	frag2 = FragTrap("Frag 2");

	for (int i = 0; i < 5; i++) {
		frag1.highFivesGuys();
		frag1.attack("Frag 2");
		frag2.takeDamage(frag1.getAttackDamage());
	}
	frag1.beRepaired(5000);
	frag1.takeDamage(2000);
	frag2.highFivesGuys();

	return (0);
}
