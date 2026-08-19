// #include <iostream>
// #include <cstdlib>

// using namespace std;


// // =====================================================
// // ASSIGNMENT 1 MENU
// // =====================================================

// void assignment1()
// {
//     int choice;

//     while(true)
//     {
//         cout << "\n====================================\n";
//         cout << "           ASSIGNMENT 1\n";
//         cout << "====================================\n";

//         cout << "1. Simple GEMM\n";
//         cout << "2. Blocking GEMM\n";
//         cout << "3. CSR Graph\n";
//         cout << "4. Back to Main Menu\n";
//         cout << "0. Exit\n";

//         cout << "Enter choice: ";
//         cin >> choice;


//         switch(choice)
//         {
//             // -----------------------------------------
//             // Simple GEMM
//             // -----------------------------------------

//             case 1:

//                 cout << "\nCompiling Simple GEMM...\n";

//                 system(
//                     "g++ -std=c++17 -O2 "
//                     "assignment_1/Simple_GEMM/driver/driver.cpp "
//                     "assignment_1/Simple_GEMM/src/gemm.cpp "
//                     "-o assignment_1/Simple_GEMM/gemm_simple"
//                 );

//                 cout << "\nRunning Simple GEMM...\n\n";

//                 system(
//                     "cd assignment_1/Simple_GEMM && "
//                     "./gemm_simple"
//                 );

//                 break;


//             // -----------------------------------------
//             // Blocking GEMM
//             // -----------------------------------------

//             case 2:

//                 cout << "\nCompiling Blocking GEMM...\n";

//                 system(
//                     "g++ -std=c++17 -O2 "
//                     "assignment_1/Blocking_GEMM/driver/driver.cpp "
//                     "assignment_1/Blocking_GEMM/src/gemm.cpp "
//                     "-o assignment_1/Blocking_GEMM/gemm_blocking"
//                 );

//                 cout << "\nRunning Blocking GEMM...\n\n";

//                 system(
//                     "cd assignment_1/Blocking_GEMM && "
//                     "./gemm_blocking"
//                 );

//                 break;


//             // -----------------------------------------
//             // CSR Graph
//             // -----------------------------------------

//             case 3:

//                 cout << "\nCompiling CSR Graph...\n";

//                 system(
//                     "g++ -std=c++17 -O2 "
//                     "assignment_1/CSR_Graph/driver/driver.cpp "
//                     "assignment_1/CSR_Graph/src/csr.cpp "
//                     "-o assignment_1/CSR_Graph/csr_graph"
//                 );

//                 cout << "\nRunning CSR Graph...\n\n";

//                 system(
//                     "cd assignment_1/CSR_Graph && "
//                     "./csr_graph"
//                 );

//                 break;


//             // -----------------------------------------
//             // Back
//             // -----------------------------------------

//             case 4:

//                 return;


//             // -----------------------------------------
//             // Exit
//             // -----------------------------------------

//             case 0:

//                 exit(0);


//             default:

//                 cout << "\nInvalid choice.\n";
//         }
//     }
// }


// // =====================================================
// // ASSIGNMENT 2 MENU
// // =====================================================

// void assignment2()
// {
//     int choice;

//     while(true)
//     {
//         cout << "\n====================================\n";
//         cout << "           ASSIGNMENT 2\n";
//         cout << "====================================\n";

//         cout << "1. Bellman-Ford\n";
//         cout << "2. Floyd-Warshall\n";
//         cout << "3. Back to Main Menu\n";
//         cout << "0. Exit\n";

//         cout << "Enter choice: ";
//         cin >> choice;


//         switch(choice)
//         {
//             // -----------------------------------------
//             // Bellman-Ford
//             // -----------------------------------------

//             case 1:

//                 cout << "\nCompiling Bellman-Ford...\n";

//                 system(
//                     "g++ -std=c++17 -O2 "
//                     "-Iassignment_1/CSR_Graph/src "
//                     "assignment_2/bellman_ford/driver/driver.cpp "
//                     "assignment_2/bellman_ford/src/bellman_ford.cpp "
//                     "assignment_1/CSR_Graph/src/csr.cpp "
//                     "-o assignment_2/bellman_ford/bellman_ford"
//                 );

//                 cout << "\nRunning Bellman-Ford...\n\n";

//                 system(
//                     "cd assignment_2/bellman_ford && "
//                     "./bellman_ford"
//                 );

//                 break;


//             // -----------------------------------------
//             // Floyd-Warshall
//             // -----------------------------------------

//             case 2:

//                 cout << "\nCompiling Floyd-Warshall...\n";

//                 system(
//                     "g++ -std=c++17 -O2 "
//                     "assignment_2/floyd_warshall/driver/driver.cpp "
//                     "assignment_2/floyd_warshall/src/floyd_warshall.cpp "
//                     "-o assignment_2/floyd_warshall/floyd_warshall"
//                 );

//                 cout << "\nRunning Floyd-Warshall...\n\n";

//                 system(
//                     "cd assignment_2/floyd_warshall && "
//                     "./floyd_warshall"
//                 );

//                 break;


//             // -----------------------------------------
//             // Back
//             // -----------------------------------------

//             case 3:

//                 return;


//             // -----------------------------------------
//             // Exit
//             // -----------------------------------------

//             case 0:

//                 exit(0);


//             default:

//                 cout << "\nInvalid choice.\n";
//         }
//     }
// }


// // =====================================================
// // MAIN MENU
// // =====================================================

// int main()
// {
//     int assignment;

//     while(true)
//     {
//         cout << "\n\n";
//         cout << "====================================\n";
//         cout << "         ASSIGNMENT WRAPPER\n";
//         cout << "====================================\n";

//         cout << "1. Assignment 1\n";
//         cout << "2. Assignment 2\n";
//         cout << "0. Exit\n";

//         cout << "Enter choice: ";
//         cin >> assignment;


//         switch(assignment)
//         {
//             // -----------------------------------------
//             // Assignment 1
//             // -----------------------------------------

//             case 1:

//                 assignment1();

//                 break;


//             // -----------------------------------------
//             // Assignment 2
//             // -----------------------------------------

//             case 2:

//                 assignment2();

//                 break;


//             // -----------------------------------------
//             // Exit
//             // -----------------------------------------

//             case 0:

//                 cout << "\nExiting program...\n";
//                 return 0;


//             default:

//                 cout << "\nInvalid assignment choice.\n";
//         }
//     }

//     return 0;
// }





#include <iostream>
#include <cstdlib>

using namespace std;


// =====================================================
// ASSIGNMENT 1 MENU
// =====================================================

void assignment1()
{
    int choice;

    while(true)
    {
        cout << "\n====================================\n";
        cout << "           ASSIGNMENT 1\n";
        cout << "====================================\n";

        cout << "1. Simple GEMM\n";
        cout << "2. Blocking GEMM\n";
        cout << "3. CSR Graph\n";
        cout << "4. Back to Main Menu\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;


        switch(choice)
        {
            // -----------------------------------------
            // Simple GEMM
            // -----------------------------------------

            case 1:

                cout << "\nCompiling Simple GEMM...\n";

                system(
                    "g++ -std=c++17 -O2 "
                    "assignment_1/Simple_GEMM/driver/driver.cpp "
                    "assignment_1/Simple_GEMM/src/gemm.cpp "
                    "-o assignment_1/Simple_GEMM/gemm_simple"
                );

                cout << "\nRunning Simple GEMM...\n\n";

                system(
                    "cd assignment_1/Simple_GEMM && "
                    "./gemm_simple"
                );

                break;


            // -----------------------------------------
            // Blocking GEMM
            // -----------------------------------------

            case 2:

                cout << "\nCompiling Blocking GEMM...\n";

                system(
                    "g++ -std=c++17 -O2 "
                    "assignment_1/Blocking_GEMM/driver/driver.cpp "
                    "assignment_1/Blocking_GEMM/src/gemm.cpp "
                    "-o assignment_1/Blocking_GEMM/gemm_blocking"
                );

                cout << "\nRunning Blocking GEMM...\n\n";

                system(
                    "cd assignment_1/Blocking_GEMM && "
                    "./gemm_blocking"
                );

                break;


            // -----------------------------------------
            // CSR Graph
            // -----------------------------------------

            case 3:

                cout << "\nCompiling CSR Graph...\n";

                system(
                    "g++ -std=c++17 -O2 "
                    "assignment_1/CSR_Graph/driver/driver.cpp "
                    "assignment_1/CSR_Graph/src/csr.cpp "
                    "-o assignment_1/CSR_Graph/csr_graph"
                );

                cout << "\nRunning CSR Graph...\n\n";

                system(
                    "cd assignment_1/CSR_Graph && "
                    "./csr_graph"
                );

                break;


            // -----------------------------------------
            // Back
            // -----------------------------------------

            case 4:
                return;


            // -----------------------------------------
            // Exit
            // -----------------------------------------

            case 0:
                exit(0);


            default:
                cout << "\nInvalid choice.\n";
        }
    }
}



// =====================================================
// ASSIGNMENT 2 MENU
// =====================================================

void assignment2()
{
    int choice;

    while(true)
    {
        cout << "\n====================================\n";
        cout << "           ASSIGNMENT 2\n";
        cout << "====================================\n";

        cout << "1. Bellman-Ford\n";
        cout << "2. Floyd-Warshall\n";
        cout << "3. Back to Main Menu\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;


        switch(choice)
        {
            // -----------------------------------------
            // Bellman-Ford
            // -----------------------------------------

            case 1:

                cout << "\nCompiling Bellman-Ford...\n";

                system(
                    "g++ -std=c++17 -O2 "
                    "-Iassignment_1/CSR_Graph/src "
                    "assignment_2/bellman_ford/driver/driver.cpp "
                    "assignment_2/bellman_ford/src/bellman_ford.cpp "
                    "assignment_1/CSR_Graph/src/csr.cpp "
                    "-o assignment_2/bellman_ford/bellman_ford"
                );

                cout << "\nRunning Bellman-Ford...\n\n";

                system(
                    "cd assignment_2/bellman_ford && "
                    "./bellman_ford"
                );

                break;


            // -----------------------------------------
            // Floyd-Warshall
            // -----------------------------------------

            case 2:

                cout << "\nCompiling Floyd-Warshall...\n";

                system(
                    "g++ -std=c++17 -O2 "
                    "assignment_2/floyd_warshall/driver/driver.cpp "
                    "assignment_2/floyd_warshall/src/floyd_warshall.cpp "
                    "-o assignment_2/floyd_warshall/floyd_warshall"
                );

                cout << "\nRunning Floyd-Warshall...\n\n";

                system(
                    "cd assignment_2/floyd_warshall && "
                    "./floyd_warshall"
                );

                break;


            // -----------------------------------------
            // Back
            // -----------------------------------------

            case 3:
                return;


            // -----------------------------------------
            // Exit
            // -----------------------------------------

            case 0:
                exit(0);


            default:
                cout << "\nInvalid choice.\n";
        }
    }
}



// =====================================================
// ASSIGNMENT 3 MENU
// =====================================================

void assignment3()
{
    int choice;

    while(true)
    {
        cout << "\n====================================\n";
        cout << "           ASSIGNMENT 3\n";
        cout << "====================================\n";

        cout << "1. Kruskal's MST\n";
        cout << "2. Prim's MST\n";
        cout << "3. Back to Main Menu\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;


        switch(choice)
        {
            // -----------------------------------------
            // Kruskal
            // -----------------------------------------

            case 1:

                cout << "\nCompiling Kruskal's MST...\n";

                system(
                    "g++ -std=c++17 -O2 "
                    "assignment_3/kruskal/driver/driver.cpp "
                    "assignment_3/kruskal/src/kruskal.cpp "
                    "assignment_1/CSR_Graph/src/csr.cpp "
                    "-o assignment_3/kruskal/kruskal"
                );

                cout << "\nRunning Kruskal's MST...\n\n";

                system(
                    "cd assignment_3/kruskal && "
                    "./kruskal"
                );

                break;


            // -----------------------------------------
            // Prim
            // -----------------------------------------

            case 2:

                cout << "\nCompiling Prim's MST...\n";

                system(
                    "g++ -std=c++17 -O2 "
                    "assignment_3/prim/driver/driver.cpp "
                    "assignment_3/prim/src/prim.cpp "
                    "assignment_1/CSR_Graph/src/csr.cpp "
                    "-o assignment_3/prim/prim"
                );

                cout << "\nRunning Prim's MST...\n\n";

                system(
                    "cd assignment_3/prim && "
                    "./prim"
                );

                break;


            // -----------------------------------------
            // Back
            // -----------------------------------------

            case 3:
                return;


            // -----------------------------------------
            // Exit
            // -----------------------------------------

            case 0:
                exit(0);


            default:
                cout << "\nInvalid choice.\n";
        }
    }
}



// =====================================================
// MAIN MENU
// =====================================================

int main()
{
    int assignment;

    while(true)
    {
        cout << "\n\n";
        cout << "====================================\n";
        cout << "         ASSIGNMENT WRAPPER\n";
        cout << "====================================\n";

        cout << "1. Assignment 1\n";
        cout << "2. Assignment 2\n";
        cout << "3. Assignment 3\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> assignment;


        switch(assignment)
        {
            // -----------------------------------------
            // Assignment 1
            // -----------------------------------------

            case 1:
                assignment1();
                break;


            // -----------------------------------------
            // Assignment 2
            // -----------------------------------------

            case 2:
                assignment2();
                break;


            // -----------------------------------------
            // Assignment 3
            // -----------------------------------------

            case 3:
                assignment3();
                break;


            // -----------------------------------------
            // Exit
            // -----------------------------------------

            case 0:

                cout << "\nExiting program...\n";
                return 0;


            default:

                cout << "\nInvalid assignment choice.\n";
        }
    }

    return 0;
}