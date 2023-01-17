#include "structs.h"
#include "files.h"
#include "pathfinding.h"

int main(int argc, char* argv[])
{
    std::string roads_path;
    std::string target_path;
    std::string output_path;

    if (!read_args(argc, argv, roads_path, target_path, output_path))
    {
        return 1;
    }

    std::vector<City*>* cities = new std::vector<City*>();
    std::vector<Path*>* paths = new std::vector<Path*>();

    if (!read_files(roads_path, target_path, cities, paths))
    {
        clean_memory(cities, paths);
        return 1;
    }

    std::string result = find_paths(cities, paths);

    save_result(output_path, result);
    clean_memory(cities, paths);

    return 0;
}
