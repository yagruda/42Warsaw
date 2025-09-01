/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:20:05 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/01 12:20:06 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define E_ARG "Wrong number of arguments or environ variables are empty.\n"
# define E_PIPE "Pipe error occurred.\n"
# define E_FORK "Fork could not create a child process.\n"
# define E_OPENO "Can't open the outfile.\n"
# define E_OPENI "Can't open the infile.\n"
# define E_EXECVE "Execve failed.\n"
# define E_CMD "Command not found.\n"
# define E_ENVP "Error occurred while duplicating environ variable PATH.\n"
# define E_ENVPATH "Can't find environ variable PATH.\n"

#endif