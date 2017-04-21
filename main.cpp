#include "boost/program_options.hpp"
#include <iostream>
#include <string>
#include<vector>

using namespace std;
namespace po = boost::program_options;

// The sample adds or subtracts integers specified by command line
int main(int argc, char** argv)
{
    try
    {
        /** Define and parse the program options
         */
        po::options_description desc("Options");
        desc.add_options()
                ("help,h", "Print help")
                ("add,a", "Add numbers")
                ("sub,s", "Subtract numbers")
                ("numbers,n",po::value<vector<string>>(),"Subtract numbers");

        po::positional_options_description positional;
        positional.add("numbers", 2);

        po::variables_map vm;
        try
        {
            po::store(po::command_line_parser(
                    argc, argv).options(desc).positional(positional).run(), vm);


            if ( vm.count("help")  )
            {
                std::cout << "Boost Command Line Parser Sample App" << std::endl
                          << desc << std::endl;
                return 0;
            }

            // If addition or subtraction operation is not specified or if both are specified.
            if ((vm.count("add") &&vm.count("sub"))||(!vm.count("add") &&!vm.count("sub")))
            {
                std::cout << "Please specify either add or subtract option and two numbers" << std::endl
                          << desc << std::endl;
                return 0;
            }

            po::notify(vm);
        }
        catch(po::error& e)
        {
            std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
            std::cerr << desc << std::endl;
            return -1;
        }

        // Get two numbers as strings
        vector<string> numbers = vm["numbers"].as< vector<string> >();

        cout<<"Numbers: ";
        for(auto n:numbers) {
            cout<< n<<" ";
        }
        cout<<endl;

        // Convert ints to integers
        int number1=stoi(numbers[0]);
        int number2=stoi(numbers[1]);

        // Add or subtract them and print them as instructed by the command line arguments
        if(vm.count("add"))
            cout<<"Sum: "<<number1+number2<<endl;
        else
            cout<<"Difference: "<<number2-number1<<endl;

    }
    catch(exception& e)
    {
        cout << "Error in arguments"<<endl;
        return -1;

    }

    return 0;

}