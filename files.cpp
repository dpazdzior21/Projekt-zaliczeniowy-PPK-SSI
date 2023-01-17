#include "files.h"

bool read_args(int argc, char* argv[], std::string& roads_path, std::string& target_path, std::string& output_path)
{
    if (argc == 1)
    {
        std::cout << "\nArgumenty:\n"
                  << "-d <sciezka do pliku z drogami>\n"
                  << "-t <sciezka do pliku z trasami do wyznaczenia>\n"
                  << "-o <sciezka do pliku wynikowego z wyznaczonymi trasami>\n\n"
                  << "Wcisnij enter, aby kontynuowac. ";
        getchar();
        return false;
    }

    for (int i = 1; i < argc; i += 2)
    {
        switch (argv[i][1])
        {
        case 'd':
            roads_path = argv[i + 1];
            break;
        case 't':
            target_path = argv[i + 1];
            break;
        case 'o':
            output_path = argv[i + 1];
            break;
        }
    }
    return true;
}

bool save_result(std::string& output_path, std::string& result)
{
    std::ofstream output_file;
    output_file.open(output_path);
    if (!output_file.is_open())
    {
        std::cout << "\nNie udalo sie otworzyc pliku wyjsciowego.\n"
                  << "Program zostanie zakonczony. \n";
        return false;
    }
    output_file << result;
    output_file.close();
    return true;
}

bool read_files(std::string& roads_path, std::string& target_path, std::vector<City*>* cities, std::vector<Path*>* paths)
{
    std::ifstream file;
    file.open(roads_path);
    if (!file.is_open())
    {
        std::cout << "\nNie udalo sie otworzyc pliku z drogami.\n"
                  << "Program zostanie zakonczony. \n";
        return false;
    }

    std::string line;
    while (!file.eof())
    {
        std::string from;
        std::string to;
        int length;
        file >> from >> to >> length;
        if (from == "" || to == "" || length == 0)
        {
            break;
        }
        City* from_city = get_or_add(cities, from);
        City* to_city = get_or_add(cities, to);
        Road* road = new Road();
        road->from = from_city;
        road->to = to_city;
        road->length = length;
        from_city->roads.push_back(road);
    }
    file.close();

    file.open(target_path);
    if (!file.is_open())
    {
        std::cout << "\nNie udalo sie otworzyc pliku z trasami do wyznaczenia.\n"
                  << "Program zostanie zakonczony.\n";
        return false;
    }

    while (!file.eof())
    {
        std::string from;
        std::string to;
        file >> from >> to;
        if (from == "" || to == "")
        {
            break;
        }
        City* from_city = get_or_add(cities, from);
        City* to_city = get_or_add(cities, to);
        Path* path = new Path();
        path->from = from_city;
        path->to = to_city;
        path->roads = new std::vector<Road*>();
        paths->push_back(path);
    }
    file.close();

    if (paths->empty())
    {
        std::cout << "\nNie ma zadnych tras do wyznaczenia.\n"
                  << "Program zostanie zakonczony.\n";
        return false;
    }

    return true;
}

void clean_memory(std::vector<City*>* cities, std::vector<Path*>* paths)
{
    for (City* city : *cities)
    {
        for (Road* road : city->roads)
        {
            delete road;
        }
        delete city;
    }
    for (Path* path : *paths) {
        delete path->roads;
        delete path;
    }
    delete cities;
    delete paths;
}