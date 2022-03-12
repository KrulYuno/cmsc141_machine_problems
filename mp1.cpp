// source: https://github.com/KrulYuno/cmsc141_machine_problems/blob/master/mp1.cpp

/*
    Test Cases: Amount of times creating new two sets.
    Operators: insert, remove, subset, union, intersection, difference, power set

*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <iterator> // i use this for iterating sets ¯\_(ツ)_/¯
#include <bits/stdc++.h> // oh i need this for std::istringstream

class InputFileHandler{
private:
    std::vector<std::string> _list;
    std::string _filename;

public:
    InputFileHandler(std::string filename = ""){
        if ( !filename.empty() )
            this->_filename = filename;
    }

    void set_filename(std::string filename){
        this->_filename = filename;
    }

    void start_reading(){
        std::ifstream File(this->_filename);
        std::string str;
        
        while(std::getline(File, str)){
            this->_list.push_back(str);
        }
        File.close();
    }

    std::vector<std::string> get_list(){
        return this->_list;
    }
    
    void _print(){
        for(int i=0; i<this->_list.size(); i++) 
            std::cout << this->_list[i] << std::endl;
    }

    std::string _get_line(int line){
        return this->_list.at(line-1);   // we don't start at line 0, we start at line 1
    }
    
};

template <class SetType>
class Set{
private:
    std::set<SetType> _set_list;

public:
    void _print(){
        for(auto i = this->_set_list.begin(); i != this->_set_list.end(); i++)
            std::cout << *i << std::endl;
    }

    std::set<SetType> _get_list(){
        return this->_set_list;
    }

    void insert(SetType value){
        this->_set_list.insert(value);
    }

    void remove(SetType value){
        this->_set_list.erase(value);
    }

    void subset(){

    }

    void s_union(){


    }

    void intersection(){

    }

    void difference(){


    }

    void power_set(){


    }
};

class Interface{
/*

    This class should be handling how we navigate through the sets. By creating, modifying,
    removing items from a set. An API perhaps?

    Flow:
        0) Initialize the sets like test cases
        1) Get the set type
        2) We fill in the two sets with X amount of data
        3) we get the X number of operations and do X operation
        4) Repeat 1
    

    In reading the file, the lines may change depending on the size of the test cases and operations.
    But there are constant lines in a file, like:
        - # of test cases   : always found at line 1
        - set type          : found at line 2
        - set data input    : found at line 3 and 4
        - # of operations   : found at line 5
    Then as for the operations input, we can do something like this:
        - operations input  : found at line 6 until line `6 + ( x - 1 )`
                              x stands for # of operations
    
    The next line would be the next test case with a new type of set

*/
private:
    std::string _filename;
    InputFileHandler File;

    int _type;
    int _test_cases;
    int _case_id;           // we use this to keep track of which case we are at

public:
    Interface(std::string file){
        /*
            We set the filename and read its contents then get its test cases.
        */
        this->_filename = file;
        this->File.set_filename(file);
        this->File.start_reading();
        this->_test_cases = std::stoi(File._get_line(1));
        this->_case_id = 0;

        this->step_1();
    }

    void step_1(){
        /*

            We get the set type for each test cases, and we also need to check if
            we have reached the maximum test cases so that we end our program.

            Example: if there are 4 test cases, we would step from 0 -> 1 -> 2 -> 3
            then we stop

        */

       if (this->_case_id < this->_test_cases){
            if (File._get_line(2).length() == 1)
                this->_type = std::stoi(File._get_line(2));
            else {
                std::istringstream sub_str(File._get_line(2));
                std::vector<std::string> v_str;

                std::string temp;
                while (sub_str >> temp)
                    v_str.push_back(temp); // this should now have values like [5, 1]

                this->_type = std::stoi(v_str.at(0)); // copy the set type
            }

            /*

                Before we proceed to step_2(), we must create the sets, but this is the hard
                part as there are 6 types of sets.
                So what we do is simply create 6 functions and proceed there.

            */

           switch (this->_type){
                case 1:
                    this->s_int();                
                    break;
                
                case 2:
                    this->s_double();                
                    break;
                
                case 3:
                    this->s_char();                
                    break;
                
                case 4:
                    this->s_string();                
                    break;
                
                case 5:
                    this->s_set();                
                    break;
                
                case 6:
                    this->s_object();                
                    break;
                
                default:
                    std::cout << "An error has occured... I don't know what that is" << std::endl;
                    break;
            }

        }

        
    }
    
    void s_int(){
        Set<int> s1;
        Set<int> s2;


    }

    void s_double(){

    }

    void s_char(){

    }

    void s_string(){

    }

    void s_set(){

    }

    void s_object(){

    }






    template<class SetType>
    void step_2(Set<SetType> *set1, Set<SetType> *set2){
        /*

            We do operations on this step, should be simple but this step requires set type.
            We only need a pointer so that we don't need to create a new data, i think.
            And to use this function, we pass it this way: step_2(&s1, &s2);

        */
    }
    
};

int main(){
    Interface Han("mp1_test.in");

    return 0;
}