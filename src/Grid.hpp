//
// Created by Derk van den Bergh and Ramon Jaspers on 4/20/2018.
//

#ifndef MATRIX_GRID_HPP
#define MATRIX_GRID_HPP

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
        int target;
        int weight;

        neighbor(int arg_target, int arg_weight)
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
    void update_weight(int node);
};


#endif //MATRIX_GRID_HPP
