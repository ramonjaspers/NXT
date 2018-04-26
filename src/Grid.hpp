//
// Created by Ramon Jaspers on 4/25/2018.
//

#ifndef V1GP_GRID_HPP
#define V1GP_GRID_HPP


#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <limits> // for numeric_limits

#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>
#include <unistd.h>


typedef int vertex_t;
typedef double weight_t;

class Grid {
private:
    char direction;
    int counter;
    int currentPosition;
    int nextPosition;
    int nextAction;
    int nextInstruction;
    bool objectDetectedBool;
    int position;


    struct neighbor {
        vertex_t target;
        weight_t weight;

        neighbor(vertex_t arg_target, weight_t arg_weight)
                : target(arg_target), weight(arg_weight) {}
    };

    typedef std::vector<std::vector<neighbor> > adjacency_list_t;
    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    std::vector<int> bestPath;
    std::vector<int> instruction_list;
    std::vector<int> matrix;
    adjacency_list_t adjacency_list;

public:
    Grid();
    ~Grid();

    char status;
    std::vector<int> pathHistory;

    void DijkstraComputePaths(vertex_t source);
    void generate_matrix();
    std::vector<int> new_path(int start);
    std::list<vertex_t> DijkstraGetShortestPathTo(vertex_t vertex);
    std::vector<int> calculateNextPosition(int current, int next);
    int turnDirection();
    void calculateNextAction();
    int actionExecute();
    void objectDetected();
    void initMatrix(int start);
    void updateWeight(vertex_t node);
    void updateStatus(int current, int next);
};



#endif //V1GP_GRID_HPP
