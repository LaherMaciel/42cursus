/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sung-jin-woo_attacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:21:06 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/07 04:13:35 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*«««««««««««««««««««««««««««««««««««»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»\
	random = 1 -> single slash to the rigth: damage 2;
	move 1 block in the direction (or look if he's already
	close to the player) of the player then attack.
	attack delay 0.3s
	Can creat a bigger combo!

	000000000		0000000000
	000000000		0000000000
	0B0000000	->	00BI000000
	000000000		0000000000
	000000000		0000000000

########################################################################

	random = 2 -> single slash to the rigth: damage 1;
	attack on that block.
	attack delay 0.2s
	Can creat a bigger combo!

	000000000		0000000000		0000000000
	000000000		0000000000		0000000000
	0B0000000	->	0BI0000000	->	0B00000000
	000000000		0000000000		0000000000
	000000000		0000000000		0000000000

########################################################################

	random = 3 -> 2 consecutive slashes: damage 3;
	move 1 block in the direction of the player and attack
	A combination of the attack 1, and attack 2.
	attack 1 delay 0.2s
	attack 2 delay 0.1s
	Can creat a bigger combo!

	000000000		000000000		000000000		000000000
	000000000		000000000		000000000		000000000
	0B0000000	->	00BI00000	->	00BI00000	->	00B000000
	000000000		000000000		000000000		000000000
	000000000		000000000		000000000		000000000

	or

	000000000		000000000		000000000		000000000
	000000000		000000000		000000000		000000000
	0B0000000	->	0BI000000	->	00BI00000	->	00B000000
	000000000		000000000		000000000		000000000
	000000000		000000000		000000000		000000000

########################################################################

	random = 4 -> cross slash: damage 2;
	jump (move) 2 blocks in the direction of the player then attack
	the attack deal damge to the block rigth in front of the boss
	and the next one.
	attack delay 0.3s

	000000000		000000000		000000000
	000000000		000000000		000000000
	0B0000000	->	000BII000	->	000B00000
	000000000		000000000		000000000
	000000000		000000000		000000000

########################################################################

	random = 5 -> charged slash: damage 4;
	move 1 block in the direction of the player then attack
	attack deal damage to all the blocks close to the boss, in
	the direction of that attack.
	attack delay 0.4s

	000000000		000000000		000000000
	000000000		00II00000		000000000
	0B0000000	->	00BI00000	->	00B000000
	000000000		00II00000		000000000
	000000000		000000000		000000000

########################################################################

	random = 6 -> stab: damage 5;
	jump 3 blocks in the direction of the player and attack
	attack delay 0.5s

	000000000		000000000		000000000
	000000000		000000000		000000000
	0B0000000	->	00000BI00	->	00000B000
	000000000		000000000		000000000
	000000000		000000000		000000000

########################################################################

	random = 7 -> teleport attack: damage +5 and -0.2s next follow up attack delay;
	attack delay 0.2s to 1s;
	teleport to rigth beside the player and attack
	can appear above, below, in front or behind the player.

\________________________________________________________________________*/

int	boss_attacks_decisons(t_win *win, t_extras *extra, int random_attack)
{
	if (random_attack == 1 && (extra->boss_x - win->player_x < 5
			|| extra->boss_y - win->player_y < 5))
	{
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 2;
		extra->enemy_attack_delay = 0.3;
		extra->enemy_attack_number_of_blocks_moved = 1;
		/*
		extra->boss_slash = 1;
		combo_attacks(win, extra, random_attack); #random range 0-25.
		*/
	}
	else if (random_attack == 2 && (extra->boss_x - win->player_x < 4
			|| extra->boss_y - win->player_y < 4))
	{
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 1;
		extra->enemy_attack_delay = 0.2;
		extra->enemy_attack_number_of_blocks_moved = 0;
		/*
		extra->boss_slash = 0;
		combo_attacks(win, extra, random_attack); #random range 0-25.
		*/
	}
	else if (random_attack == 3 && (extra->boss_x - win->player_x < 6
			|| extra->boss_y - win->player_y < 6))
	{
		extra->enemy_attack = random_attack;
		if (extra->boss_slash == 0)
		{
			extra->enemy_attack_damage = 2;
			extra->enemy_attack_damage2 = 1;
			extra->enemy_attack_delay = 0.2;
			extra->enemy_attack_delay2 = 0.1;
			extra->enemy_attack_number_of_blocks_moved = 1;
			extra->enemy_attack_number_of_blocks_moved2 = 0;	
		}
		else
		{
			extra->enemy_attack_damage = 1;
			extra->enemy_attack_damage2 = 2;
			extra->enemy_attack_delay = 0.2;
			extra->enemy_attack_delay2 = 0.2;
			extra->enemy_attack_number_of_blocks_moved = 1;
			extra->enemy_attack_number_of_blocks_moved2 = 1;
		}
		/*
		combo_attacks(win, extra, random_attack); #random range 0-45.
		*/
	}
	else if (random_attack == 4 && (extra->boss_x - win->player_x < 7
			|| extra->boss_y - win->player_y < 7))
	{
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 2;
		extra->enemy_attack_delay = 0.3;
		extra->enemy_attack_number_of_blocks_moved = 2;
		/*
		*/
	}
	else if (random_attack == 5 && (extra->boss_x - win->player_x < 5
			|| extra->boss_y - win->player_y < 5))
	{
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 4;
		extra->enemy_attack_delay = 0.4;
		extra->enemy_attack_number_of_blocks_moved = 1;
		/*
		*/ 
	}
	else if (random_attack == 6 && (extra->boss_x - win->player_x < 8
			|| extra->boss_y - win->player_y < 8))
	{
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 5;
		extra->enemy_attack_delay = 0.5;
		extra->enemy_attack_number_of_blocks_moved = 4;
		/*
		*/ 
	}
	else if (random_attack == 7 && (extra->boss_x - win->player_x < 15
			|| extra->boss_y - win->player_y < 15))
	{
		if (extra->teleport == 1)
		{
			extra->enemy_attack = random_attack;
			//attack;
			extra->teleport = 0;
		}
		else
			extra->teleport++;
		/*
		*/
	}
	else
		return (1);
	return (0);
}

void	combo_attacks(t_win *win, t_extras *extra, int random_attack)
{
	if (random_attack == 1 && (extra->boss_x - win->player_x < 5
			|| extra->boss_y - win->player_y < 5) && (extra->boss_slash != 1))
	{
		/*random = 1 -> single slash to the rigth: damage 1;
		Can creat a bigger combo!
		extra->boss_slash = 1;
		attack delay 0.2s.
		*/
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 1;
		extra->enemy_attack_delay = 0.2;
		extra->enemy_attack_number_of_blocks_moved = 1;
		//combo_attacks(win, extra, random_attack); #random range 0-35.
	}
	if (random_attack == 2 && (extra->boss_x - win->player_x < 4
			|| extra->boss_y - win->player_y < 4) && (extra->boss_slash != 0))
	{
		/*random =  2 -> single slash to the left: damage 2;
		attack on that block.
		attack delay 0.3s.
		Can creat a bigger combo!
		extra->boss_slash = 0;
		*/
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 2;
		extra->enemy_attack_delay = 0.3;
		extra->enemy_attack_number_of_blocks_moved = 0;
		//combo_attacks(win, extra, random_attack); #random range 0-35.
	}
	if (random_attack == 3 && (extra->boss_x - win->player_x < 6
			|| extra->boss_y - win->player_y < 6))
	{
		/*random = 3 -> 2 consecutive slashes: damage 2;
		move 1 block in the direction of the player and attack
		A combination of the attack 1, and attack 2.
		attack delay 0.1s.
		Can creat a bigger combo!
		*/
		extra->enemy_attack = random_attack;
		if (extra->boss_slash == 0)
		{
			extra->enemy_attack_damage = 2;
			extra->enemy_attack_damage2 = 1;
			extra->enemy_attack_delay = 0.2;
			extra->enemy_attack_delay2 = 0.1;
			extra->enemy_attack_number_of_blocks_moved = 1;
			extra->enemy_attack_number_of_blocks_moved2 = 0;	
		}
		else
		{
			extra->enemy_attack_damage = 1;
			extra->enemy_attack_damage2 = 2;
			extra->enemy_attack_delay = 0.2;
			extra->enemy_attack_delay2 = 0.2;
			extra->enemy_attack_number_of_blocks_moved = 1;
			extra->enemy_attack_number_of_blocks_moved2 = 1;
		}
		//combo_attacks(win, extra, random_attack); #random range 0-60.
	}
	if (random_attack == 4 && (extra->boss_x - win->player_x < 7
			|| extra->boss_y - win->player_y < 7))
	{
		/*random = 4 -> cross slash: damage 1;
		jump (move) 2 blocks in the direction of the player then attack
		the attack deal damge to the block rigth in front of the boss
		and the next one.
		attack delay 0.2s
		*/
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 1;
		extra->enemy_attack_delay = 0.2;
		extra->enemy_attack_number_of_blocks_moved = 2;
	}
	if (random_attack == 5 && (extra->boss_x - win->player_x < 5
			|| extra->boss_y - win->player_y < 5))
	{
		/*random = 5 -> charged slash: damage 3;
		move 1 block in the direction of the player then attack
		attack deal damage to all the blocks close to the boss, in
		the direction of that attack.
		attack delay 0.3s
		*/
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 3;
		extra->enemy_attack_delay = 0.3;
		extra->enemy_attack_number_of_blocks_moved = 1;
	}
	if (random_attack == 6 && (extra->boss_x - win->player_x < 8
			|| extra->boss_y - win->player_y < 8))
	{
		/*random = 6 -> stab: damage 4;
		jump 3 blocks in the direction of the player and attack
		attack delay 0.4s.
		*/
		extra->enemy_attack = random_attack;
		extra->enemy_attack_damage = 4;
		extra->enemy_attack_delay = 0.4;
		extra->enemy_attack_number_of_blocks_moved = 3;
	}
}

void	rigth_slash(t_win *win, t_extras *extra)
{
	extra->enemy_attack_damage = 2;
	extra->enemy_attack_delay = 0.2;
	extra->enemy_attack_number_of_blocks_moved = 1;
	if (extra->enemy_attack_direction == 0)
	else if (extra->enemy_attack_direction == 1)
	else if (extra->enemy_attack_direction == 2)
	else if (extra->enemy_attack_direction == 3)
}

void	left_slash(t_win *win, t_extras *extra)
{
	if (extra->enemy_attack_direction == 0)
	else if (extra->enemy_attack_direction == 1)
	else if (extra->enemy_attack_direction == 2)
	else if (extra->enemy_attack_direction == 3)
}
