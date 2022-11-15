#include <iostream>
#include <string>
#include <cstdlib>
#include "Graphs.h"

Graph::Graph(int num_v) : m_matrix_size(num_v){
    for (int i=0; i<num_v; i++){
        for (int j=0; j<num_v; j++){
            m_adj_matrix[i][j] = 0; // Nothing shares edge with anything
        }
    }
}

Graph::Graph(int num_v, int adj_matrix[MATRIX_SIZE][MATRIX_SIZE]) : m_matrix_size(num_v){
    for (int i=0; i<num_v; i++){
        for (int j=0; j<num_v; j++){
            m_adj_matrix[i][j] = adj_matrix[i][j];
        }
    }
}

bool Graph::addEdge(int n_1, int n_2, int val){
    if(hasEdge(n_1, n_2) || n_1 == n_2){
        return false;
    }else{
        m_adj_matrix[n_1][n_2] = val;
        return true;
    }
}

bool Graph::removeEdge(int n_1, int n_2){
    if(!hasEdge(n_1, n_2)){
        return false;
    }else{
        m_adj_matrix[n_1][n_2] = 0;
        return true;
    }
}

bool Graph::hasEdge(int n_1, int n_2) {
    return (m_adj_matrix[n_1][n_2] != 0);
}

std::vector<int> Graph::outEdges(int n) {
    std::vector<int> results;
    for (int i=0; i<m_matrix_size; i++)
         if(hasEdge(n, i))
            results.push_back(i);
    return results;
}

std::vector<int> Graph::inEdges(int n) {
    std::vector<int> results;
    for (int i=0; i<m_matrix_size; i++)
         if(hasEdge(i, n))
            results.push_back(i);
    return results;
}

std::string Graph::printGraph() {
    std::string str = "  0 1 2 3 4 5 6 7 8 9\n";

    for (int i=0; i<m_matrix_size; i++){
        str += std::to_string(i);
        str += " ";
        for (int j=0; j<m_matrix_size; j++){
            str += std::to_string(m_adj_matrix[i][j]);
            str += " ";
        }
        str += "\n";
    }
    std::cout << str;
    return str;
}

bool Graph::isEmpty() {
    for (int i=0; i<m_matrix_size; i++){
        for (int j=0; j<m_matrix_size; j++){
            if (m_adj_matrix[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}






