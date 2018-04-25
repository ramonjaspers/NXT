//
// Created by Derk van den Bergh and Ramon Jaspers on 4/20/2018.
//


#include "Grid.hpp"


typedef int vertex_t;
typedef double weight_t;
const weight_t max_weight = std::numeric_limits<double>::infinity();


/**
 * Instantiate Grid Object
 */
Grid::Grid() {
    /*
     * Predefined status starting at 0, orientation default
     */
    this->status = 's';
    this->counter = 0;
};


/**
 *  TODO:Node adjustment
 * @param adj_index
 */
/*
void Grid::update_node(unsigned int adj_index) {
    //TODO: FIX AANROEP FUCNTION REPLACE W
    unsigned int l =  this->adjacency_list[adj_index].size();
    for(unsigned int x= 0; x < l; x++){

    }
    //this->adjacency_list[adj_index].update();
}
*/


/**
 *
 * @param source generates the fastest route from the given input source
 */
void Grid::DijkstraComputePaths(vertex_t source) {
    int n = this->adjacency_list.size();
    this->min_distance.clear();
    this->min_distance.resize(n, max_weight);

    this->min_distance[source] = 0;
    this->previous.clear();
    this->previous.resize(n, -1);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(this->min_distance[source], source));

    while (!vertex_queue.empty()) {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());

        // Visit each edge exiting u
        const std::vector<neighbor> &neighbors = this->adjacency_list[u];
        for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
             neighbor_iter != neighbors.end();
             neighbor_iter++) {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
            if (distance_through_u < this->min_distance[v]) {
                vertex_queue.erase(std::make_pair(this->min_distance[v], v));

                this->min_distance[v] = distance_through_u;
                this->previous[v] = u;
                vertex_queue.insert(std::make_pair(this->min_distance[v], v));

            }
        }
    }
}

/**
 *
 * @param [in] vertex; contains values created by dijkstra algorithm
 * @return [out] vertex; returns the created vector of the dijkstra algorithm
 */
std::list<vertex_t> Grid::DijkstraGetShortestPathTo(vertex_t vertex) {
    std::list<vertex_t> path;
    for (; vertex != -1; vertex = this->previous[vertex])
        path.push_front(vertex);
    return path;
}

/**
 *  Generates possible positions based on current matrix positions (positions 0 to 24)
 */
void Grid::generate_matrix() {
    // 5x5 matrix generated
    adjacency_list_t adjacency_list(25);

    adjacency_list[0].push_back(neighbor(1, 1));
    adjacency_list[1].push_back(neighbor(0, 1));
    adjacency_list[5].push_back(neighbor(0, 1));
    adjacency_list[2].push_back(neighbor(1, 1));
    adjacency_list[6].push_back(neighbor(1, 1));
    adjacency_list[1].push_back(neighbor(2, 1));
    adjacency_list[3].push_back(neighbor(2, 1));
    adjacency_list[7].push_back(neighbor(2, 1));
    adjacency_list[2].push_back(neighbor(3, 1));
    adjacency_list[4].push_back(neighbor(3, 1));
    adjacency_list[8].push_back(neighbor(3, 1));
    adjacency_list[3].push_back(neighbor(4, 1));
    adjacency_list[9].push_back(neighbor(4, 1));
    adjacency_list[0].push_back(neighbor(5, 1));
    adjacency_list[6].push_back(neighbor(5, 1));
    adjacency_list[10].push_back(neighbor(5, 1));
    adjacency_list[1].push_back(neighbor(6, 1));
    adjacency_list[5].push_back(neighbor(6, 1));
    adjacency_list[7].push_back(neighbor(6, 1));
    adjacency_list[11].push_back(neighbor(6, 1));
    adjacency_list[2].push_back(neighbor(7, 1));
    adjacency_list[6].push_back(neighbor(7, 1));
    adjacency_list[8].push_back(neighbor(7, 1));
    adjacency_list[12].push_back(neighbor(7, 1));
    adjacency_list[3].push_back(neighbor(8, 1));
    adjacency_list[7].push_back(neighbor(8, 1));
    adjacency_list[9].push_back(neighbor(8, 1));
    adjacency_list[13].push_back(neighbor(8, 1));
    adjacency_list[4].push_back(neighbor(9, 1));
    adjacency_list[8].push_back(neighbor(9, 1));
    adjacency_list[14].push_back(neighbor(9, 1));
    adjacency_list[5].push_back(neighbor(10, 1));
    adjacency_list[11].push_back(neighbor(10, 1));
    adjacency_list[15].push_back(neighbor(10, 1));
    adjacency_list[6].push_back(neighbor(11, 1));
    adjacency_list[10].push_back(neighbor(11, 1));
    adjacency_list[12].push_back(neighbor(11, 1));
    adjacency_list[16].push_back(neighbor(11, 1));
    adjacency_list[7].push_back(neighbor(12, 1));
    adjacency_list[11].push_back(neighbor(12, 1));
    adjacency_list[13].push_back(neighbor(12, 1));
    adjacency_list[17].push_back(neighbor(12, 1));
    adjacency_list[8].push_back(neighbor(13, 1));
    adjacency_list[12].push_back(neighbor(13, 1));
    adjacency_list[14].push_back(neighbor(13, 1));
    adjacency_list[18].push_back(neighbor(13, 1));
    adjacency_list[9].push_back(neighbor(14, 1));
    adjacency_list[13].push_back(neighbor(14, 1));
    adjacency_list[19].push_back(neighbor(14, 1));
    adjacency_list[10].push_back(neighbor(15, 1));
    adjacency_list[16].push_back(neighbor(15, 1));
    adjacency_list[20].push_back(neighbor(15, 1));
    adjacency_list[11].push_back(neighbor(16, 1));
    adjacency_list[15].push_back(neighbor(16, 1));
    adjacency_list[17].push_back(neighbor(16, 1));
    adjacency_list[21].push_back(neighbor(16, 1));
    adjacency_list[12].push_back(neighbor(17, 1));
    adjacency_list[16].push_back(neighbor(17, 1));
    adjacency_list[18].push_back(neighbor(17, 1));
    adjacency_list[22].push_back(neighbor(17, 1));
    adjacency_list[13].push_back(neighbor(18, 1));
    adjacency_list[17].push_back(neighbor(18, 1));
    adjacency_list[19].push_back(neighbor(18, 1));
    adjacency_list[23].push_back(neighbor(18, 1));
    adjacency_list[14].push_back(neighbor(19, 1));
    adjacency_list[18].push_back(neighbor(19, 1));
    adjacency_list[15].push_back(neighbor(20, 1));
    adjacency_list[21].push_back(neighbor(20, 1));
    adjacency_list[16].push_back(neighbor(21, 1));
    adjacency_list[20].push_back(neighbor(21, 1));
    adjacency_list[22].push_back(neighbor(21, 1));
    adjacency_list[17].push_back(neighbor(22, 1));
    adjacency_list[21].push_back(neighbor(22, 1));
    adjacency_list[23].push_back(neighbor(22, 1));
    adjacency_list[18].push_back(neighbor(23, 1));
    adjacency_list[22].push_back(neighbor(23, 1));
    adjacency_list[24].push_back(neighbor(23, 1));
    adjacency_list[19].push_back(neighbor(24, 1));
    adjacency_list[23].push_back(neighbor(24, 1));
    adjacency_list[24].push_back(neighbor(19, 1));

    this->adjacency_list = adjacency_list;

}

/**
 *
 * @return [out] returns the fastest path in a readable vector int
 */
std::vector<int> Grid::new_path(int start) {
    this->generate_matrix();
    this->DijkstraComputePaths(start);
    std::list<vertex_t> path = this->DijkstraGetShortestPathTo(24);
    std::copy(path.begin(), path.end(), std::back_inserter(this->bestPath));

    return this->bestPath;
}

/**
 *
 * @param direction [in] character; generates the current action based on his current position and facing direction.
 */
int Grid::turnDirection() {
    std::cout << "De directie is: " << this->direction << std::endl;
    std::cout << "De huidige status is: " << this->status << std::endl;
    std::cout << "De gewenste status is: " << this->direction << std::endl;

    // Kijk welke kant de robot op moet draaien als de directie "zuid" is.
    if (this->direction  == 's') {
        if (this->status == 'n') {
            this->status = 's';
            return 2;
        } else if (this->status == 'e') {
            this->status = 's';
            return 1;
        } else if (this->status == 's') {
            this->status = 's';
            return 4;
        } else if (this->status == 'w') {
            this->status = 's';
            return 3;
        } else {
            return 5;
        }
    }
    // Kijk welke kant de robot op moet draaien als de directie "noord" is.
    if (this->direction   == 'n') {
        if (this->status == 'n') {
            this->status = 'n';
            return 4;
        } else if (this->status == 'e') {
            this->status = 'n';
            return 3;
        } else if (this->status == 's') {
            this->status = 'n';
            return 2;
        } else if (this->status == 'w') {
            this->status = 'n';
            return 1;
        } else {
            return 5;
        }

    }
    // Kijk welke kant de robot op moet draaien als de directie "oost" is.
    if (this->direction   == 'e') {
        if (this->status == 'n') {
            this->status = 'e';
            return 1;
        } else if (this->status == 'e') {
            this->status = 'e';
            return 4;
        } else if (this->status == 's') {
            this->status = 'e';
            return 3;
        } else if (this->status == 'w') {
            this->status = 'e';
            return 2;
        } else {
            return 5;
        }

    }
    // Kijk welke kant de robot op moet draaien als de directie "west" is.
    if (this->direction   == 'w') {
        if (this->status == 'n') {
            this->status = 'w';
            return 3;
        } else if (this->status == 'e') {
            this->status = 'w';
            return 2;
        } else if (this->status == 's') {
            this->status = 'w';
            return 1;
        } else if (this->status == 'w') {
            this->status = 'w';
            return 4;
        } else {
            return 5;
        }
    }
    std::cout << "De definitieve status is: " << this->status << std::endl << std::endl;
}

/**
 * Function holds currren facing direction.
 * @param current [in] integer of Current matrix position
 * @param next [in] integer of next position goal
 * @return [out] integer of next calculated position
 */
std::vector<int> Grid::calculateNextPosition(int current, int next) {

    if (current == (next - 5)) {
        this->direction =   's';
    } else if (current == (next + 5)) {
        this->direction =   'n';

    } else if (current == (next + 1)) {
        this->direction =   'e';

    } else if (current == (next - 1)) {
        this->direction =   'w';

    } else {
        std::cout << "Error" << std::endl;
    }
    std::cout << "directie in functie: " << this->direction << std::endl << std::endl;
    int instruction = this->turnDirection();

    std::cout << "Gegeven instructie: " << instruction << std::endl << std::endl;
    return {next, instruction};
}
/**
 * generates next action integer. e.g.: 1 -> 6
 */

void Grid::initMatrix(int start) {
    this->matrix = this->new_path(start);
}
void Grid::calculateNextAction() {
    if(!this->objectDetectedBool) {
        initMatrix(0);
    } else {
        this->initMatrix(position);
        std::cout << "Generating new instruction list due to detection object" << std::endl;
    }
    for (unsigned int i = 0; i < this->matrix.size(); i++) {
        this->currentPosition = this->matrix[i];
        this->nextPosition = this->matrix[i + 1];
        if (this->currentPosition != 24) {
            std::cout << "Volgende positie: " << this->nextPosition << ", huidige positie: " << this->currentPosition << std::endl << std::endl;
            std::vector<int> data_list = calculateNextPosition(this->currentPosition, this->nextPosition);
            this->nextAction = data_list[0];
            this->nextInstruction = data_list[1];
            // ga nextPosition
            this->pathHistory.push_back(this->nextAction);
            this->instruction_list.push_back(this->nextInstruction);
            std::cout << "Rijden naar positie " << this->nextAction << '\n';
        } else {
            std::cout << "Einde bereikt!" << std::endl;
            this->instruction_list.push_back(6);
            for(unsigned int i = 0; i < this->instruction_list.size(); i++) {
                std::cout << "Instructie degree " << i+1 << ": " << instruction_list[i] << std::endl;
            }
            break;
        }
    }
}

int Grid::actionExecute() {
    int index = this->counter;
    if(this->counter < instruction_list.size()) {
        this->counter++;
        return this->instruction_list[index];
    } else {
    return 5;
    }

}

void Grid::update_weight(int node) {
    for(unsigned int i = 0; i < this->adjacency_list.size(); i++) {
        if(adjacency_list[i].data()->target == node)
            adjacency_list[i].data()->weight = 99999;
    }
}

void Grid::objectDetected() {
    // reverse
    this->update_weight(matrix[counter]+1);
    this->position = matrix[counter];
    this->calculateNextAction();
}


Grid::~Grid() {}



