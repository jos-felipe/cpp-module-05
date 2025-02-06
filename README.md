# C++ Module 05: Exception Handling in a Bureaucratic World

This module teaches exception handling in C++98 through an engaging simulation of a bureaucratic system. By implementing a hierarchy of forms, bureaucrats, and interns, you'll learn how to handle errors gracefully and maintain program stability when things go wrong.

## Learning Objectives

The primary focus of this module is mastering exception handling in C++. You will learn:
- How to use try/catch blocks to manage runtime errors
- Creating and implementing custom exception classes
- Working with exception hierarchies in inherited classes
- Maintaining program stability when exceptions occur
- Using polymorphism with abstract classes

## Project Structure

The project simulates a bureaucratic system with several interconnected classes:

1. **Bureaucrat**: Officials with grades from 1 (highest) to 150 (lowest)
   - Handles invalid grade errors through exceptions
   - Signs and executes forms based on grade level

2. **AForm** (Abstract Base Class): Template for all forms
   - Defines common form behaviors and attributes
   - Implements permission and execution logic
   - Serves as the foundation for specific form types

3. **Concrete Forms**:
   - `ShrubberyCreationForm`: Creates ASCII tree art (Sign: 145, Execute: 137)
   - `RobotomyRequestForm`: Robotomizes targets (Sign: 72, Execute: 45)
   - `PresidentialPardonForm`: Grants pardons (Sign: 25, Execute: 5)

4. **Intern**: Form creation system
   - Demonstrates error handling in factory pattern implementation
   - Shows dynamic object creation with error management

## Exception System

The project implements a comprehensive exception handling system:

```cpp
// Custom exception class example
class GradeTooHighException : public std::exception {
    public:
    virtual const char* what() const throw() {
        return "Grade too high! Must be between 1 and 150";
    }
};

// Usage example
try {
    Bureaucrat director("Director", 0);  // Invalid grade
} catch (const Bureaucrat::GradeTooHighException& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

## Building and Testing

```bash
# Compile the project
make

# Run memory checks
make leaks

# Clean up
make fclean

# Rebuild
make re
```

## Usage Example

```cpp
try {
    // Create a bureaucratic workflow
    Bureaucrat supervisor("Supervisor", 45);
    Intern intern;
    
    // Create and process a form
    AForm* form = intern.makeForm("robotomy request", "Bender");
    supervisor.signForm(*form);
    supervisor.executeForm(*form);
    delete form;
    
} catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

## Class Requirements

All classes must implement the Orthodox Canonical Form:
- Default constructor
- Copy constructor
- Assignment operator
- Destructor

This ensures proper resource management and behavior copying.

## Testing Strategy

The project includes tests for:
- Invalid grade handling
- Form signing and execution permissions
- Unknown form type requests
- Error conditions in all operations

## Contributing

This project is part of the 42 School curriculum. While primarily for learning purposes, suggestions for improving the exception handling system are welcome.

## License

This project is part of the 42 School curriculum and follows its academic honor code.