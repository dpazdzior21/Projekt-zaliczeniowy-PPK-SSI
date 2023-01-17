#include "pathfinding.h"

City* get_or_add(std::vector<City*>* cities, std::string name)
{

    for (auto city : *cities)
    {
        if (city->name == name)
        {
            return city;
        }
    }
    City* city = new City();
    city->name = name;
    cities->push_back(city);
    return cities->at(cities->size() - 1);
}

void build_path(std::vector<City*>* cities, Path* path)
{
    City* current = path->to;
    while (current != path->from)
    {
        path->roads->push_back(current->previous);
        current = current->previous->from;
    }
    reverse(path->roads->begin(), path->roads->end());
}

std::string get_path(Path* path)
{
    std::string result = "";
    result += "trasa: " + path->from->name + " --> " + path->to->name + "(" + std::to_string(path->to->total_length) + " km):\n";
    for (Road* road : *path->roads)
    {
        result += road->from->name + " --> " + road->to->name + " " + std::to_string(road->length) + "\n";
    }
    return result;
}

bool dijkstra(Path* path)
{
    std::vector<City*> visited;
    std::vector<City*> data;
    path->from->total_length = 0;
    data.push_back(path->from);
    std::priority_queue<City*, std::vector<City*>, customComparator> queue(data.begin(), data.end());
    City* current = nullptr;

    while (queue.size() > 0)
    {
        current = queue.top();
        queue.pop();

        for (Road* road : current->roads)
        {
            City* to = road->to;
            if (find(visited.begin(), visited.end(), to) != visited.end())
            {
                continue;
            }
            if (current->total_length + road->length < to->total_length)
            {
                to->total_length = current->total_length + road->length;
                to->previous = road;
                if (find(data.begin(), data.end(), to) == data.end())
                {
                    queue.push(to);
                }
            }
        }

        visited.push_back(current);
        if (current == path->to)
        {
            return true;
        }
    }

    return false;
}

void reset_total_lengths(std::vector<City*>* cities)
{
    for (City* city : *cities)
    {
        city->total_length = INT_MAX;
    }
}

std::string find_paths(std::vector<City*>* cities, std::vector<Path*>* paths)
{
    std::string result = "";
    for (Path* path : *paths)
    {
        reset_total_lengths(cities);
        bool success = dijkstra(path);
        if (!success)
        {
            result += "trasa: " + path->from->name + " --> " + path->to->name + "\n";
            result += "TRASA NIEMOZLINA DO WYZNACZENIA\n";
            continue;
        }
        build_path(cities, path);
        result += get_path(path);
    }
    return result;
}