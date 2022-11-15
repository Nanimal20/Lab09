#pragma once
#include <vector>
#include <string>
#include <iostream>

#define MATRIX_SIZE 100


class IGraph{
public:
    virtual bool addEdge(int n_1, int n_2, int val) = 0; // Add edge (i,j) to E
    virtual bool removeEdge(int n_1, int n_2) = 0; // Remove the edge (i,j) from E
    virtual bool hasEdge(int n_1, int n_2) = 0; // check if edge (i,j) is in E
    virtual std::vector<int> outEdges(int n) = 0; // returns list of ints such that (i,j) is in E
    virtual std::vector<int> inEdges(int n) = 0; // returns list of ints such that (j,i) is in E
    virtual std::string printGraph() = 0; // Prints adjacency matrix   
};


class Graph : IGraph{
public:
    Graph(int num_v);
    Graph(int num_v, int adj_matrix[MATRIX_SIZE][MATRIX_SIZE]);
    ~Graph() {};

    bool addEdge(int n_1, int n_2, int val) override;
    bool removeEdge(int n_1, int n_2) override;
    bool hasEdge(int n_1, int n_2) override;
    std::vector<int> outEdges(int n) override;
    std::vector<int> inEdges(int n) override;
    std::string printGraph() override;
    bool isEmpty();

private:
    Graph(); // Unused
    int m_matrix_size;
    int m_adj_matrix[MATRIX_SIZE][MATRIX_SIZE];

};