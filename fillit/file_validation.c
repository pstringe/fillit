/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralee <ralee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:18:03 by pstringe          #+#    #+#             */
/*   Updated: 2018/01/26 11:06:14 by ralee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static  int     is_valid_char(char c)
{
    if (c == '\n' || c == '#' || c == '.')
    {
        return (1);
    }
    return (0);
}

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
