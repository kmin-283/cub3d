/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:32:23 by kmin              #+#    #+#             */
/*   Updated: 2020/05/23 22:12:30 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(int error)
{
	error == 1 ? write(1, "Error : file open fail\n", 24) : 0;
	error == 2 ? write(1, "Error : Too little Arguments\n", 30) : 0;
	error == 3 ? write(1, "Error : Too many Arguments\n", 28) : 0;
	error == 4 ? write(1, "Error : Arguments name invalid\n", 32) : 0;
	error == 5 ? write(1, "Error : Save name invalid\n", 27) : 0;
	error == 6 ? write(1, "Error : Map width and height Invalid\n", 38) : 0;
	error == 7 ? write(1, "Error : Texture Invalid\n", 25) : 0;
	error == 8 ? write(1, "Error : Color Invalid\n", 23) : 0;
	error == 9 ? write(1, "Error : Map is Open\n", 21) : 0;
	error == 10 ? write(1, "Error : Invalid character in Map\n", 34) : 0;
	error == 11 ? write(1, "Error : Allocation fails in mapGrid\n", 37) : 0;
	error == 12 ? write(1, "Error : Allocation fails in MapWidth\n", 38) : 0;
	error == 13 ? write(1, "Error : Bitmap open falis\n", 27) : 0;
	error == 14 ? write(1, "Error : Sprite Allocation fails\n", 33) : 0;
	error == 15 ? write(1, "Error : Floor or Ceiling declare twice\n", 41) : 0;
	error == 16 ? write(1, "Error : Map declare twice\n", 27) : 0;
	error == 17 ? write(1, "Error : .Cub file is empty\n", 28) : 0;
	return (-1);
}
