/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuthber <scuthber@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:18:38 by scuthber          #+#    #+#             */
/*   Updated: 2025/07/21 14:18:40 by scuthber         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/* Linux/X11 key codes */
# define X11_KEY_ESC 0xFF1B
# define X11_KEY_W 0x0077
# define X11_KEY_A 0x0061
# define X11_KEY_S 0x0073
# define X11_KEY_D 0x0064
# define X11_KEY_UP 0xFF52
# define X11_KEY_DOWN 0xFF54
# define X11_KEY_LEFT 0xFF51
# define X11_KEY_RIGHT 0xFF53
# define X11_KEY_M 0x006D

/* macOS key codes */
# define MAC_KEY_ESC 53
# define MAC_KEY_W 13
# define MAC_KEY_A 0
# define MAC_KEY_S 1
# define MAC_KEY_D 2
# define MAC_KEY_UP 126
# define MAC_KEY_DOWN 125
# define MAC_KEY_LEFT 123
# define MAC_KEY_RIGHT 124
# define MAC_KEY_M 46

/* Use these for cross-platform compatibility */
# ifdef __APPLE__
#  define KEY_ESC MAC_KEY_ESC
#  define KEY_W MAC_KEY_W
#  define KEY_A MAC_KEY_A
#  define KEY_S MAC_KEY_S
#  define KEY_D MAC_KEY_D
#  define KEY_UP MAC_KEY_UP
#  define KEY_DOWN MAC_KEY_DOWN
#  define KEY_LEFT MAC_KEY_LEFT
#  define KEY_RIGHT MAC_KEY_RIGHT
#  define KEY_M MAC_KEY_M
# else
#  define KEY_ESC X11_KEY_ESC
#  define KEY_W X11_KEY_W
#  define KEY_A X11_KEY_A
#  define KEY_S X11_KEY_S
#  define KEY_D X11_KEY_D
#  define KEY_UP X11_KEY_UP
#  define KEY_DOWN X11_KEY_DOWN
#  define KEY_LEFT X11_KEY_LEFT
#  define KEY_RIGHT X11_KEY_RIGHT
#  define KEY_M X11_KEY_M
# endif

#endif
