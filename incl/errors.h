/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/02/05 15:21:14 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define INPUT_ERR 1
# define MALLOC_ERR 2
# define MLX_ERR 3
# define WIN_ERR 4
# define IMG_ERR 5
# define ADDR_ERR 6
# define NAME_ERR 7
# define COL_ERR 8
# define FRAC_ERR 9
# define JULIA_ERR 10
# define FRAC_MALLOC_ERR 11
# define PXL_ERR 12
# define UI_ERR 13
# define SHIFT_ERR 14

// Bitmapping image info
# define NAME_INIT 0x80
# define WIN_INIT 0x40
# define WIN_WIN_INIT 0x20
# define WIN_MLX_INIT 0x10
# define FRAC_INIT 0x08
# define COLOUR_INIT 0x04
# define IMG_INIT 0x02
# define ADDR_INIT 0x01

// Bitmapping window activity
# define WIN_3 0x08
# define WIN_2 0x04
# define WIN_1 0x02
# define WIN_0 0x01

#endif