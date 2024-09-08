/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:30:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/08 20:36:09 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
    std::string _name; //it own name; also has ClapTraps' name: name_clap_name
public:
    DiamondTrap(); //in both consturctors: _energy from ScavTrap, _health and _attack from FragTrap
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap&    operator=(const DiamondTrap& other);
    void            attack(const std::string &target); //takes attack from ScavTrap
    void            whoAmI(); //shows both this names: own and Clap name
};

