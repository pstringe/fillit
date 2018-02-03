/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:18:03 by pstringe          #+#    #+#             */
/*   Updated: 2018/02/03 11:29:05 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * these validation functions pass over the entire buffer being read in, looking back it would probably be a 
 * lot less code, to vaidate indivaidul pieces as they are read in and assign them to structs
 */

/*
 * checks for invalid chars
 */
static  int     is_valid_char(char c)
{
    if (c == '\n' || c == '#' || c == '.')
    {
        return (1);
    }
    return (0);
}

/*
 * there is a maximum size for a file being there can  only be 26 tets in the input. This checks that
 */
static  int is_valid_filesize(char *unvalidated_tetromino_set)
{
    int counter;
    int filesize;

    counter = -1;
    while(unvalidated_tetromino_set[++counter])
    {
        filesize = counter + 1;
    }
    filesize++;
    if(filesize % 21 == 0 && filesize <= (26 * 21))
    {
        return (1);
    }
    return (0);
}

/*
 * goes over every char in the file, and returns false as soon as there is an invalid char
 */
static int  is_valid_charset(char *unvalidated_tetromino_set)
{
    int i;

    i = -1;
    while(unvalidated_tetromino_set[++i])
    {
        if (!is_valid_char(*(unvalidated_tetromino_set + i)))
        {
            return(0);
        }
    }
    return(1);
}

/*
 * checks if the tet groups are properly shaped, of course, it could be the case that \n occur in stange order, * this would be caught in tetromino validation.
 */
static int  is_valid_number_of_newlines(char *unvalidated_tetromino_set)
{
    int i;
    int file_size;
    int number_of_newlines;

    file_size = ft_strlen(unvalidated_tetromino_set);
    number_of_newlines = 0;
    i = -1;
    while(unvalidated_tetromino_set[++i])
    {
        if (unvalidated_tetromino_set[i] == '\n')
        {
            number_of_newlines++;
        }
    }
    if((number_of_newlines + 1) % 5 == 0 && (number_of_newlines + 1) / (file_size + 1 / 21) == 5)
    {
        return (0);
    }
    return (1);
}

/*
 *	calls the above functions to perform all the file validation checks
 */
char    *validate_tetromino_set(char *unvalidated_tetromino_set)
{
    if(!unvalidated_tetromino_set)
    {
        error(-1);
        return(NULL);
    }
    if(!(is_valid_filesize(unvalidated_tetromino_set)))
    {
        error(-2);
        return(NULL);
    }
    if(!is_valid_charset(unvalidated_tetromino_set))
    {
        error(-3);
        return(NULL);
    }
    if(!is_valid_number_of_newlines(unvalidated_tetromino_set))
    {
        error(-4);
        return(NULL);
    }
    return(unvalidated_tetromino_set);
}
