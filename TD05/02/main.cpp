#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <unordered_map>

std::string random_name(size_t size)
{
    std::string name{""};
    name.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size)
{
    std::vector<std::pair<std::string, float>> robots_fix{};
    robots_fix.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        std::string robotName{random_name(2)};
        float cost{static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

bool isRobotInList(std::unordered_map<std::string, std::vector<float>> const &result, std::string const &current_robot_name_to_check)
{
    auto it = result.find(current_robot_name_to_check);
    if (it == result.end())
        return false;
    return true;
}

std::unordered_map<std::string, std::vector<float>> ordered_robots_fix(std::vector<std::pair<std::string, float>> const &ordered_robots_fix)
{
    std::unordered_map<std::string, std::vector<float>> result;
    for (int i{0}; i < ordered_robots_fix.size(); i++)
    {
        std::string current_robot_name_to_check{ordered_robots_fix[i].first};

        if (!isRobotInList(result, current_robot_name_to_check))
        {
            std::pair<std::string, std::vector<float>> current_robot;
            current_robot.first = current_robot_name_to_check;
            for (int j{i}; j < ordered_robots_fix.size(); j++)
            {
                if (current_robot.first == ordered_robots_fix[j].first)
                    current_robot.second.push_back(ordered_robots_fix[j].second);
            }
            result.insert(current_robot);
        }
    }
    return result;
}

float sum_robot_cost(std::vector<float> const &v)
{
    return std::accumulate(v.begin(),
                           v.end(),
                           0.0f,
                           [](float a, float b)
                           { return a + b; });
}

void display_robots(std::unordered_map<std::string, std::vector<float>> const &ordered_robots_fix)
{
    for (auto const element : ordered_robots_fix)
    {
        // Affichage de tous les couts de l'instance
        //  std::cout << element.first << " : ";
        //  for (int i{0}; i < element.second.size(); i++)
        //      std::cout << element.second[i] << ", ";
        //  std::cout << std::endl;
        std::cout << element.first << " : ";
        float instance{0};
        for (int i{0}; i < element.second.size(); i++)
        {
            instance++;
        }
        std::cout << instance << " robot(s) & cout des reparations : " << sum_robot_cost(element.second) << " $";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Nombre de robots au final : " << ordered_robots_fix.size();
}

int main()
{
    size_t number_of_robots{100};
    display_robots(ordered_robots_fix(get_robots_fix(number_of_robots)));
    return 0;
}