/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:48:47 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/26 17:34:40 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
	
		const std::string _name;
		bool _is_signed; // TBD: init to false at construction
		const unsigned int _grade_sign;
		const unsigned int _grade_execute;
	public:
		Form();
		Form(const std::string name, unsigned int grade_sign, unsigned int grade_execute);
		~Form();
		
		const std::string getName() const;
		bool getSignStatus() const;
	 	unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;
		

		// TBD: it changes the form’s status to signed if the bureaucrat’s grade is high enough
		// (greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
		// If the grade is too low, throw a Form::GradeTooLowException.
		void beSigned(Bureaucrat);

		// TBD: Then, add a signForm() member function in the Bureaucrat class. This function must
		// call Form::beSigned() to attempt to sign the form. If the form is signed successfully, it
		// will print something like:
		// <bureaucrat> signed <form>
		// Otherwise, it will print something like:
		// <bureaucrat> couldn’t sign <form> because <reason>.
		// Implement and submit some tests to ensure everything works as expected.
};

std::ostream& operator<<(std::ostream& os, const Form& Form);



#endif