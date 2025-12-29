/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:39:06 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 16:39:59 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It must open the file <filename> and copy its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You must create and turn in your
own tests to ensure that your program works as expected.
*/

#include <iostream>
#include <fstream>
#include <string>

void copyfile_in_file(std::ifstream *infile , std::ofstream *outfile ,char *S1, char *S2)
{
    std::string line;
    std::string STR1 = (std::string)S1;
    std::string STR2 = (std::string)S2;
    while( getline(*infile , line))
    {   
        size_t pos = 0;
        size_t found = line.find(S1,pos);
        while(found != std::string::npos)
        {
            line.erase(found,STR1.length());
            line.insert(found,S2);
            pos = found;
        found = line.find(S1,pos);

        }
        *outfile << line << std ::endl;
        
    }
}

int main(int ac , char **av)
{
    if(ac != 4)
        return(0);

    std::ifstream infile(av[1]);
    if(!infile)
    {
        std::cout << "errorr in infile"<< std::endl;
        return(0);
    }
    
    std::string outputFilename = (std::string)av[1] + ".replace";
    std::ofstream outfile(outputFilename.c_str());
    if(!outfile)
    {
        std::cout << "error in outfile"<< std::endl; 
        return(0);
    }

    copyfile_in_file(&infile ,&outfile,av[2],av[3]);
	
}