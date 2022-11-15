#include <iostream>
#include <string>
#include <cstdlib>
#include "Graphs.cpp"

using namespace std;

int main()
{
    bool run = true;
    
    //char use_matrix;
    std::string row = "";
    
    int size;

    std::vector<int> edges; 
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {0};

    std::cout << "Enter size of desired matrix:\n" << std::endl;
    std::cin >> size;
    Graph graph(size);

    while(run)
    {
  
        std::cout <<"Press 1 to add an edge to the graph" << std::endl;
        std::cout <<"Press 2 remove an edge from graph" << std::endl;
        std::cout <<"Press 3 to find an edge in the graph" << std::endl;
        std::cout <<"Press 4 to find the out edges of a vertex" << std::endl;
        std::cout <<"Press 5 to find the in edges of a vertex" << std::endl; 
        std::cout <<"Press 6 to print out adjacency matrix" << std::endl; 
        std::cout <<"Press 7 to quit this program" << std::endl; 
    
        int n_1 =-1;
        int n_2 =-1;
        int n =-1;
        int weight =-1;
        int input = 0;
        std::cin >> input;
        cout << "I received this input: "<< input<< std::endl;
        switch(input)
        {
            case 1:
                // Get input
                std::cout << "Enter the first node:" << std::endl;
                std::cin >> n_1;
                std::cout << "Enter the second node:" << std::endl;
                std::cin >> n_2;
                std::cout << "Enter the weight between first and second node:" << std::endl;
                std::cin >> weight;

                // Check if valid input
                if ((n_1 > size || n_1 < 0 ) || (n_2 > size || n_2 < 0)){
                    std::cout << "Invalid nodes\n\n"<< std::endl;
                    break;
                }

                // add the edge
                if (graph.addEdge(n_1, n_2, weight)){
                    printf("Added edge from %d to %d\n\n", n_1, n_2);
                }else{
                    cout << "Failed to add edge to the graph\n"<< std::endl;
                }
                break;
                
            case 2:
                // Get input
                std::cout << "Enter the first node:" << std::endl;
                std::cin >> n_1;
                std::cout << "Enter the second node:" << std::endl;
                std::cin >> n_2;

                // Check if valid input
                if ((n_1 > size || n_1 < 0 ) || (n_2 > size || n_2 < 0)){
                    std::cout << "Invalid nodes\n\n"<< std::endl;
                    break;
                }

                // remove the edge
                if (graph.removeEdge(n_1, n_2)){
                    printf("Removed edge from %d to %d\n\n", n_1, n_2);
                }else{
                    printf("Failed to remove edge\n\n");
                }                
                break;

            case 3:
                // Get input
                std::cout << "Enter the first node:" << std::endl;
                std::cin >> n_1;
                std::cout << "Enter the second node:" << std::endl;
                std::cin >> n_2;

                // Check if valid input
                if ((n_1 > size || n_1 < 0 ) || (n_2 > size || n_2 < 0)){
                    std::cout << "Invalid nodes\n\n"<< std::endl;
                    break;
                }

                // Find the edge
                if (graph.hasEdge(n_1, n_2)){
                    printf("Edge FOUND from %d to %d\n\n", n_1, n_2);
                }else{
                    printf("Edge NOT FOUND from %d to %d\n\n", n_1, n_2);
                }
                break;

            case 4:
                // Get input
                std::cout << "Enter the node of interest:" << std::endl;
                std::cin >> n;

                // Check if valid input
                if (n > size || n < 0 ){
                    std::cout << "Invalid node\n\n";
                    break;
                }

                // Find out-edges
                edges = graph.outEdges(n);
                printf("Found nodes pointing outward towards %d\n\n", n);

                for (auto i : edges){
                    std::cout << i << std::endl;
                }
                break;

            case 5:
                // Get input
                std::cout << "Enter the node of interest:" << std::endl;
                std::cin >> n;

                // Check if valid input
                if (n > size || n < 0 ) {
                    std::cout << "Invalid node\n\n";
                    break;
                }

                // Find in-edges
                edges = graph.inEdges(n);
                printf("Found nodes pointing inward towards %d\n\n", n);
                for (auto i : edges){
                    std::cout << i << std::endl;
                }
                break;
                
            case 6:
                std::cout << "Printing Matrix\n\n";
                if (graph.isEmpty())
                {
                    std::cout << "Graph is empty\n" << endl;
                    break;
                }
                graph.printGraph(); 
                break;
            
            case 7:
                run = false;
                break;
            
            default:
                run = false;
                std::cout << "Invalid input\n\n";
                break;
        }
    }
    
    std::cout << "Thanks for using this graphing program\n\n";

    return EXIT_SUCCESS;
}
