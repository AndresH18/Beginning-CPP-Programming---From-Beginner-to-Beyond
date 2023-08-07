#include <iostream>
#include <vector>

using namespace std;

int main() {

    // ARRAYS

    /*
     * Is array zero-base collection of elements
     * Fix size
     *
     * WARNING
     * It does NOT check bounds. If array has 5 elements and you ask the 6 element,
     * you will get whatever is at that position, even if it is not inside the array
     *
     * DECLARATION
     * Element_Type array_Name [constant number of elements];
     *
     * INITIALIZATION
     * Element_Type array_Name [constant number of elements] {init list};
     * int test_scores [5] {100, 90, 70, 50, 80};
     * int high_score [100] {3, 5}; // [0] = 3, [1] = 5, [2-99] = 0
     * double hot_days [365] {}; // init all to 0
     *
     * int another_array[] {1,2,3,4,5}; // size automatically calculated
     *
     * ACCESSING
     * array_name [element_index]
     *
     * CHANGING CONTENT
     * cin >> array_name [element_index];
     * array_name [element_index] = new_value;
     */

    cout << "ARRAYS" << endl;

    char vowels_array[]{'a', 'e', 'i', 'o', 'u'};
    cout << "The first vowel is: " << vowels_array[0] << endl;
    cout << "The last vowel is: " << vowels_array[4] << endl;

    // THIS MAY CRASH THE PROGRAM BECAUSE WE DELETE SOMETHING THAT MAY HVE BEEN IMPORTANT
//    cin >> vowels_array[5];
//    cout << vowels_array[5];

//    for (char vowel : vowels_array) {
//        cout << vowel << "\t";
//    }
    int array[]{1, 2, 3, 4};
    cout << sizeof array << endl; // this displays the memory address of the array

    // Multidimensional Arrays
    /*
     * Element_Type array_name[row][column]
     * Element_type array_name[dim1_size][dim2_size]...[dimN_size]
     */

    int movie_ratings_array[3][4]
            {
                    {0, 4, 3, 5},
                    {2, 3, 3, 5},
                    {1, 4, 4, 5}
            };

    cout << "===================================" << endl << endl;

    cout << "VECTORS" << endl;

    //VECTORS
    /*
     * Dynamic Array
     *
     * Is part of the "C++ Standard Template Library"
     *
     * Zero-Base Collection
     *
     * An array that can grow and shrink at execution time.
     * Provides similar semantics and syntax as arrays.
     * Very efficient.
     * Provide Bounds Checking functions.
     * Can use a lot of functions like: sort, reverse, find, erase, and more.
     *
     * DECLARING
     * #include <vector>
     * std::vector <Type> vector_name;
     * std::vector <Type> vector_name (size);
     *
     * INITIALIZATION
     * All elements are automatically initialized to 0, unless specified otherwise
     * using namespace std;
     * vector <char> vowels (5);
     * vector <int> test_scores (10); //initializes all 10 values to 0
     * vector <Type> vector_name (size, value_for_all_elements);
     *
     * vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
     * vector <int> test_scores {100, 98, 80, 50, 76};
     * vector <double> hi_temperatures (360, 80.0); // the First parameter is the size of the vector.
     *                                      The Second value what we want to initialize ALL values of the vector
     *
     * WARNING
     * if you access vector positions using [], Then there are NO Bounds Checking
     *
     * ACCESSING VECTOR ELEMENTS
     * vector_name [element_index] // the same like with arrays. Therefore, NO Bound Checking
     *
     * vector_name.at(element_index);
     *
     * MODIFYING VECTOR ELEMENTS
     * vector_name[element_index] = new_element // NO BOUND CHECKING
     *
     * vector_name.at(element_index) = new_element;
     *
     * ADD TO THE LAST POSITION
     * vector_name.push_back(element) // The vector will automatically allocate the required space
     *
     */


//    vector<char> vowels_vector; // Empty vector
//    vector<char> vowels_vector(5); // Size 5, initialized to 0
    vector<char> vowels_vector{'a', 'e', 'i', 'o', 'u'};

    cout << vowels_vector[0] << endl;
    cout << vowels_vector[4] << endl;

//    vector <int> test_scores (3); // 3 elements initialized to 0
//    vector <int> test_scores (3, 100); // 3 elements initialized to 100
    vector<int> test_scores{100, 98, 89};

    cout << "\nTest Scores using array Syntax" << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;

    cout << "\nTest Scores using vector syntax" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "\nThere are " << test_scores.size() << " scores in the vector" << endl;

    cout << "\nEnter 3 scores: ";
    cin >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);

    cout << "\nUpdated test scores" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;

    cout << "\nEnter a test score to add to the vector: ";
    int score_to_add{0};
    cin >> score_to_add;
    test_scores.push_back(score_to_add);

    cout << "Enter one more score to the vector: ";
    cin >> score_to_add;
    test_scores.push_back(score_to_add);

    cout << "\nNew Test Scores" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << test_scores.at(4) << endl;

    cout << "\nAnd the new Size is: " << test_scores.size() << endl;

//    cout << "\nThis throws an exception" << test_scores.at(10) << endl;

    //2 DIMENSIONAL VECTOR

    vector<vector<int>> movie_ratings // vector of vectors
            {
                    {1, 2, 3, 4},
                    {1, 2, 4, 4},
                    {1, 3, 5, 4}
            };

    cout << "\nHere are the movie ratings for reviewer #1 using array syntax" << endl;
    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings[0][1] << endl;
    cout << movie_ratings[0][2] << endl;
    cout << movie_ratings[0][3] << endl;

    cout << "\nHere are the movie ratings for reviewer #2 using vector syntax" << endl;
    cout << movie_ratings.at(1).at(0) << endl;
    cout << movie_ratings.at(1).at(1) << endl;
    cout << movie_ratings.at(1).at(2) << endl;
    cout << movie_ratings.at(1).at(3) << endl;



    // SECTION CHALLENGE
    vector<int> vector1;
    vector1.push_back(10);
    vector1.push_back(20);

    cout << "\nvector1" << endl << vector1.at(0) << endl << vector1.at(1) << endl << "Size=" << vector1.size() << endl;

    vector<int> vector2;
    vector2.push_back(100);
    vector2.push_back(200);

    cout << "\nvector2" << endl << vector2.at(0) << endl << vector2.at(1) << endl << "Size=" << vector2.size() << endl;

    vector<vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "\nVector 2D" << endl;
    cout << vector_2d.at(0).at(0) << endl << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << endl << vector_2d.at(1).at(1) << endl;
    cout << "Size=" << vector_2d.size();


    return 0;
}
