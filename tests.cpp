#include <gtest/gtest.h>
#include "Graphs.cpp"
#include <iostream>

using namespace std;

TEST(Graph, Constructor){    
    Graph g(10);
    ASSERT_TRUE(1);
}

TEST(Graph, Constructor_2){
    Graph g(100);
    ASSERT_TRUE(1);
}


TEST(Graph, AddEdge){
   Graph graph(10);
   ASSERT_FALSE(graph.hasEdge(1, 2)); 
   graph.addEdge(1, 2, 1);
   ASSERT_TRUE(graph.hasEdge(1, 2)); 
}

TEST(Graph, AddEdge_ALOT){
   Graph graph(10);
   graph.addEdge(1, 2, 1);
   graph.addEdge(1, 3, 1);
   graph.addEdge(2, 4, 1);
   graph.addEdge(2, 5, 1);
   graph.addEdge(7, 6, 1);
   graph.addEdge(1, 7, 1);
   ASSERT_TRUE(graph.hasEdge(1, 2)); 
   ASSERT_TRUE(graph.hasEdge(1, 3)); 
   ASSERT_TRUE(graph.hasEdge(2, 4)); 
   ASSERT_TRUE(graph.hasEdge(2, 5)); 
   ASSERT_TRUE(graph.hasEdge(7, 6)); 
   ASSERT_TRUE(graph.hasEdge(1, 7)); 
}

TEST(Graph, RemoveEdge){
    Graph graph(10);
    graph.addEdge(1, 2, 1);
    ASSERT_TRUE(graph.hasEdge(1, 2)); 
    graph.removeEdge(1, 2);
    ASSERT_FALSE(graph.hasEdge(1, 2));
    ASSERT_FALSE(graph.removeEdge(1, 2)); // negative test case
}

TEST(Graph, RemoveEdge_ALOT){
   Graph graph(10);
   graph.addEdge(1, 2, 1);
   graph.addEdge(1, 3, 1);
   graph.addEdge(2, 4, 1);
   graph.addEdge(2, 5, 1);
   graph.addEdge(7, 6, 1);
   graph.addEdge(1, 7, 1);
   ASSERT_TRUE(graph.hasEdge(1, 2)); 
   ASSERT_TRUE(graph.hasEdge(1, 3)); 
   ASSERT_TRUE(graph.hasEdge(2, 4)); 
   ASSERT_TRUE(graph.hasEdge(2, 5)); 
   ASSERT_TRUE(graph.hasEdge(7, 6)); 
   ASSERT_TRUE(graph.hasEdge(1, 7)); 
   graph.removeEdge(1, 2);
   ASSERT_FALSE(graph.hasEdge(1, 2)); 
   graph.removeEdge(1, 3);
   ASSERT_FALSE(graph.hasEdge(1, 3)); 
   graph.removeEdge(2, 4);
   ASSERT_FALSE(graph.hasEdge(2, 4)); 
   graph.removeEdge(2, 5);
   ASSERT_FALSE(graph.hasEdge(2, 5)); 
   graph.removeEdge(7, 6);
   ASSERT_FALSE(graph.hasEdge(7, 6)); 
   graph.removeEdge(1, 7);
   ASSERT_FALSE(graph.hasEdge(1, 7)); 
}

TEST(Graph, OutEdge){
    Graph graph(10);
    std::vector<int> ret = {2};
    graph.addEdge(1, 2, 1);
    ASSERT_EQ(ret, graph.outEdges(1));
}

TEST(Graph, OutEdge_ALOT){
    Graph graph(10);
    std::vector<int> ret = {2, 3, 4, 5, 6, 7};
    for (auto i : ret){
        graph.addEdge(1, i, 1);
    }
    ASSERT_EQ(ret, graph.outEdges(1));
}

TEST(Graph, InEdge){
    Graph graph(10);
    std::vector<int> ret = {2};
    graph.addEdge(2, 1, 1);
    ASSERT_EQ(ret, graph.inEdges(1));
}

TEST(Graph, InEdge_ALOT){
    Graph graph(10);
    std::vector<int> ret = {2, 3, 4, 5, 6, 7};
    for (auto i : ret){
        graph.addEdge(i, 1, 1);
    }
    ASSERT_EQ(ret, graph.inEdges(1));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
