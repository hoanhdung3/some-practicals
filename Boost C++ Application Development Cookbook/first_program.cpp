// p.22
#include<iostream>
#include<boost/program_options.hpp>
#include<boost/program_options/errors.hpp>

namespace opt = boost::program_options; // alias

int main(int argc, char *argv[]){
    opt::options_description desc("All options");
    // 'a' and 'o' are short option name for apples and oranges
    // 'name' option is not marked with 'required()', so user may not support it
    desc.add_options()
        ("apples,a", opt::value<int>()->default_value(10), "apples that u have")
        ("oranges,o", opt::value<int>(), "oranges that u have")
        ("name", opt::value<std::string>(), "your name")
        ("help", "produce help message");
    
    opt::variables_map vm;
    // Parsing command line options and storing value to 'vm'
    opt::store(opt::parse_command_line(argc, argv, desc), vm);
    // We can also parse environment variables using 'parse_environment' method
    opt::notify(vm);

    if(vm.count("help")){
        std::cout<<desc<<"\n";
        return 1;
    }

    // Adding missing options from "apples_oranges.cfg" config file.
    // You can also provide an istreamable object as a first param for 'parse_config_file'
    // 'char' template parameter will be passed to underlying std::basic_istream object

    try{
        opt::store(
            opt::parse_config_file<char>("apples_oranges.cfg", desc),vm
        );
    } catch(const opt::reading_file& e){
        std::cout<<"Failed to open file 'apples_oranges.cfg': "<<e.what();
    }
    opt::notify(vm);
    if(vm.count("name")){
        std::cout<<"Hi, "<<vm["name"].as<std::string>()<<"!\n";
    }
    std::cout<<"Fruits count: "<<vm["apples"].as<int>() + vm["oranges"].as<int>()<<std::endl;
    return 0;
}

// Constructing an options describing variable and giving
// it a textual description "All options" to it.


// When we are adding options, first parameter is a name
// to be used in command line. Second parameter is a type
// of that option, wrapped in value<> class.
 // Third parameter must be a short description of that option



// Variable to store our command line arguments


// Parsing and storing arguments

