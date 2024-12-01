#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


/**
 * you can reuse a lot of it for both parts,
 * just having like this show solution to each individual problem
*/
int part1(char** argv){
    //opens file
    std::ifstream fileInput;

    fileInput.open(argv[1]);

    //OH, YEAH VECTOR WITH BOTH MAGNITUDE AND DIRECTION
    std::vector<std::int32_t> list1;
    std::vector<std::int32_t> list2;

    //Oh, yeah it's the final countdown
    int finalCountDown = 0;

    //actual calculates the final distance
    if (fileInput.is_open()) {
        //splits and converts them to integers
        std::string line;
        while (std::getline(fileInput, line)) {
            std::cout << line << std::endl;
            int stringSplit = line.find(' ');
            list1.push_back( std::stoi(line.substr(0,stringSplit)) );
            list2.push_back( std::stoi(line.substr(stringSplit)) );
        }
        //closes file *we didn't need it anyway*
        fileInput.close();

        //sorts vectors (https://www.youtube.com/watch?v=vLSLwIaCpv8)
        std::stable_sort(list1.begin(),list1.end());
        std::stable_sort(list2.begin(),list2.end());

        for (int i=0;i<list1.size(); i++){
            finalCountDown += abs(list1.at(i) - list2.at(i));
        }
        std::cout << "Part1: " << finalCountDown << std::endl;
    }
    else{
        std::cout << "oh uh spaghetti has been dropped into the file" << std::endl;
    }
    return 0;
}

/**
 * you can reuse a lot of it for both parts,
 * just having like this show solution to each individual problem
*/
int part2(char** argv){
    //opens file
    std::ifstream fileInput;

    fileInput.open(argv[1]);

    //OH, YEAH VECTOR WITH BOTH MAGNITUDE AND DIRECTION
    std::vector<std::int32_t> list1;
    std::vector<std::int32_t> list2;

    //Oh, yeah it's the final countdown
    int finalCountDown = 0;

    if (fileInput.is_open()) {
        //splits and converts them to integers
        std::string line;
        while (std::getline(fileInput, line)) {

            //So it doesn't spam stdout if you have both selected
            if (argv[2] == "2") {
                std::cout << line << std::endl;
            }

            int stringSplit = line.find(' ');
            list1.push_back( std::stoi(line.substr(0,stringSplit)) );
            list2.push_back( std::stoi(line.substr(stringSplit)) );
        }
        //closes file *we didn't need it anyway*
        fileInput.close();

        //counts the number of occurrences in right column and multiples by current number
        for (int countable : list1){
            finalCountDown += std::count(list2.begin(),list2.end(),countable) * countable;
        }
        std::cout << "Part2: " << finalCountDown << std::endl;
    }
    else{
        std::cout << "oh uh spaghetti has been dropped into the file" << std::endl;
    }
    return 0;
}

//Main function decides which part of program is needed by using the passed args
int main(int argc, char **argv) {
    if (argv[2] == "1"){
        part1(argv);
    }
    else if (argv[2] == "2"){
        part2(argv);
    }
    else{
        part1(argv);
        part2(argv);
    }
    return 0;
}
