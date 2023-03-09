/* CSCI 41 LAB WORK DONE BY: JOSE CORTES*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* The idea behind the Movie and Date classes was to emulate LAB 6, to hold the information needed for this project */
// Realase date
class Date{
    private:
        int month, day, year;
    public:
        // Default constructor
        Date(){}
        // Date Constructor
        Date(int m, int d, int y){
            month = m;
            day = d;
            year = y;
        }
        // Setters for month, day, and year
        void setMonth(int m){
            month = m;
        }
        void setDay(int d){
            day = d;
        }
        void setYear(int y){
            year = y;
        }
        // Getters for month, day, and year
        int getMonth(){
            return month;
        }
        int getDay(){
            return day;
        }
        int getYear(){
            return year;
        }
};
// Movie information - Date and Title
class Movie{ 
    private:
        string title;
        Date ReleaseDate;

    public:
    Movie(){}
    // Constructor to organize information
    Movie (string t, Date rd){
        title = t;
        ReleaseDate = rd;
    }
    //Print Movie Information
    void PrintMovie(){
        cout << endl << "Movie title: " << getTitle() << endl;
        cout << "Date: " << getDate().getMonth() << "-" << getDate().getDay() << "-" << getDate().getYear() << endl;
    }
    // Setters
    void setTitle(string t){
        title = t;
    }
    void setDate(Date rd){
        ReleaseDate = rd;
    }

    // Getters
    string getTitle(){
        return title;
    }
    Date getDate(){
        return ReleaseDate;
    }
};

// Circular Linked List - referencing Double_Circular.cpp from the sylabus...
struct CLLnode{
    Movie data;
    bool ishead;
    CLLnode* next;

    CLLnode() {}
    CLLnode(Movie a){
        ishead = false;
        data = a;
        next = NULL;
    }
};

// A circular linked list to hold the movies of a category
class MovieCLL{
    private:
        CLLnode* head, * tail;
        int NumElements;
    public:
        // Defualt Constructor
        MovieCLL(){
            head = NULL;
            tail = NULL;
            NumElements = 0;
        }
        // Get the head of the list
        CLLnode* gethead (){
            return head;
        }
        // Get the tail of the list
        CLLnode* getTail(){
            return tail;
        }
        // Insert at rear
        void InsertRearCLL(Movie d){
            CLLnode* temp = new CLLnode(d);
            if (head == NULL){
                temp -> ishead = true;
                head = temp;
                tail = temp;
                tail->next = head;
            }
            else {
                tail->next = temp;
                tail = temp;
                tail->next = head;
            }
            NumElements += 1;
        }
        // Removes last element before it loops - This was supposed to assist in deleting all movies in a category (Couldn't delete head)
        void RemoverCLL(){
            CLLnode* temp = head;
            if (head == NULL){
                cout << "no elements to remove" << endl;
                return;
            }
            else {
                if (head -> next == head){
                    head = tail = NULL;
                }
                else{
                    while (temp -> next -> next != head){
                        temp = temp -> next;
                    }
                    tail = temp;
                    tail -> next = head;
                }
            }
            NumElements -= 1;
        }
        // Print all movie information in the list
        void PrintListCLL(){
            CLLnode* temp = head;
            if (head != NULL){
                do{
                    temp -> data.PrintMovie();
                    temp = temp -> next;
                }
                while (temp != head);
                cout << endl;
            }
        }
        // A local function to search the movie list
        bool SearchMovie(string st){
            CLLnode* temp = head;
            if (head != NULL){
                do{
                    if (temp -> data.getTitle() == st){
                        cout << "Movie was found..." << endl;
                        temp -> data.PrintMovie();
                        return true;
                    }
                    temp = temp -> next;
                }
                while (temp != head);
            }
            return false;
        }
        // A local fuction to remove all movies in hopes it would remove the head, it did not
        void RemoveAllMovies(){
            while((head != NULL) && (tail != NULL)){
            if (head == NULL){
                cout << "no elements to remove" << endl;
                return;
            }
            else {
                if (head -> next == head){
                    head = tail = NULL;
                }
                else{
                    CLLnode* temp = head;
                    while (temp -> next -> next != head){
                        temp = temp -> next;
                    }
                    tail = temp;
                    tail -> next = head;
                    }
                }
                NumElements -= 1;
            }
        }
};

// This vector was made to hold premade objects because I was having difficulty understanding where I would input arrays, my mistake...
vector <MovieCLL> MovieCategories(15);

// Similar to the movie class, The category class was going to hold the information needed to form a category (Name, Movie list)
class Category{
    private:
        string CategoryName;
        MovieCLL CategoryData;
    public:
        // Defualt
        Category(){}
        // Constructor to organize information
        Category(string CN, MovieCLL CD){
            CategoryName = CN;
            CategoryData = CD;
        }
        // Print Category information (Including movie list)
        void PrintCategory(){
            cout << endl << "Catagory: " << CategoryName << endl;
            CategoryData.PrintListCLL();
        }
        // Set Category Name
        void setName(string n){
            CategoryName = n;
        }
        // Set movie list to reference
        void setMovieList(MovieCLL d){
            CategoryData = d;
        }
        // Get Category Name
        string getName(){
            return CategoryName;
        }
        // get movie list
        MovieCLL getMovieList(){
            return CategoryData;
        }
};

// Creation of Double Linked List
struct DLLnode {
    DLLnode* prev;
    Category data;
    DLLnode* next;

    DLLnode() {}
    DLLnode(Category a) {
        prev = NULL;
        data = a;
        next = NULL;
    }
};

// Double Linked List - to go through the category data
class CategoryDLL {
    private:
        DLLnode* head, * tail;
        int numelements;

    public:
        // Defualt
        CategoryDLL() {
            head = NULL;
            tail = NULL;
            numelements = 0;
            cout << "in default const" << endl;
        }
        // Get head
        DLLnode* GetHead() {
            return head;
        }
        // Get Tail
        DLLnode* GetTail() {
            return tail;
        }
        // Insert at the end of DLL
        void InsertRear(Category d) {
            DLLnode* temp = new DLLnode(d);
            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail -> next = temp;
                temp -> prev = tail;
                tail = temp;
            }
            numelements += 1;
        }
        // Remove last element of DLL
        void RemoverDLL() {
            if (head == NULL) {
                cout << "no elements to remove" << endl;
                return;
            }
            else {
                if (head->next == NULL) {
                    head = tail = NULL;
                }
                else {
                    tail = tail->prev;
                    tail->next = NULL;
                }
            }
            numelements -= 1;
        }
        // Print List of Categories
        void PrintCategoryList(){
            DLLnode* temp = head;
            int i = 1;
            cout << "Categories)" << endl;
            if (head != NULL) {
                while (temp != NULL) {
                    cout << "   " << i << ". " << ((temp -> data).getName()) << endl;
                    i++;
                    temp = temp -> next;
                }
            }
        }
        // Print all movies from all categories
        void PrintList() {
            DLLnode* temp = head;
            if (head != NULL) {
                while (temp != NULL) {
                    (temp -> data).PrintCategory();
                    temp = temp -> next;
                }
            }
        }
        // Add category at the end of the list
        void AddCategory(){
            string newCatTitle;
            if (numelements < 15){
                cout << "What is the name of this category?" << endl;
                cin.ignore();
                getline(cin, newCatTitle);
                InsertRear(Category(newCatTitle, MovieCategories.at(numelements)));
                cout << "Category added successfully: " << (GetTail() -> data.getName()) << endl;
            }
            else{
                cout << "New category could not be added" << endl;
            }
        }
        // Search for a category by name
        void SearchCategory(){
            string SearchTerm;
            DLLnode* temp = head;
            cout << "What category are you searching for? (Cap-sensitive)" << endl;
            cin.ignore();
            getline(cin, SearchTerm);
            if (head != NULL) {
                while (temp != NULL) {
                    if (temp -> data.getName() == SearchTerm){
                        temp -> data.PrintCategory();
                        return;
                    }
                    temp = temp -> next;
                }
                cout << "No category was found under \"" << SearchTerm << "\", check capitalization..." << endl;
                return;
            }
            cout << "No categories..." << endl;
        }
        // Search for movie by name
        void SearchMovieList(){
            string SearchTerm;
            DLLnode* temp = head;
            cout << "What movie are you looking for? (Cap-sensitive)" << endl;
            cin.ignore();
            getline(cin, SearchTerm);
            if (head != NULL) {
                while (temp != NULL) {
                    if (temp -> data.getMovieList().SearchMovie(SearchTerm)){
                        cout << "Category: "<< temp -> data.getName() << endl;
                        return;
                    }
                    temp = temp -> next;
                }
                cout << "No movie was found under \"" << SearchTerm << "\", check capitalization..." << endl;
                return;
            }
            cout << "No categories... so no movies..." << endl;
        }
        // Remove a category by name
        void RemoveCategory(){
            string SearchTerm;
            DLLnode* temp = head;
            cout << "What category would you like to delete? (Cap-sensitive)" << endl;
            cin.ignore();
            getline(cin, SearchTerm);
            if (head != NULL) {
                while (temp != NULL) {
                    if (temp -> data.getName() == SearchTerm){
                        //temp -> data.getMovieList().RemoveAllMovies();
                        while (temp -> next != NULL){
                            temp -> next -> prev = temp -> next;
                            temp = temp -> next;
                            if (temp -> next -> next == NULL){
                                tail = temp -> next;
                            }
                        }
                    return;
                    }
                    temp = temp -> next;
                }
                cout << "No category was found under \"" << SearchTerm << "\", check capitalization..." << endl;
                return;
            }
            cout << "No categories..." << endl;
        }
};
// This returns a number to active a function in the switch case 
int ExploreFeatures(){
    int choice;
    cout << "Would you like to..." << endl;
    cout << "   1. Add a new category" << endl;
    cout << "   2. Search for a category by name" << endl;
    cout << "   3. Search for a movie by name" << endl;
    cout << "   4. Remove a category by name" << endl;
    cout << "   5. Delete all movies before a certain date" << endl;
    cout << "   6. Print all movies from all categories" << endl;
    cout << "   7. Exit program" << endl;
    cin >> choice;
    if (choice > 7 || choice < 1){
        cout << "Invaild response..." << endl << "Try again..." << endl;
        ExploreFeatures();
    }
    return choice;
}

int main () {
    // premade objects of categories (I forgot I could of used a array MovieCLL c = new MovieCLL [?])
    MovieCLL c1, c2 ,c3, c4, c5, c6, c7 ,c8 ,c9 ,c10, c11, c12, c13, c14, c15;
    // Inserting them in the vector
    MovieCategories = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15};
    // Object to hold all categories
    CategoryDLL MovieEngine;
    // This inserts and establishes the categories and movies needed for the examples
    c1.InsertRearCLL(Movie("Barbie",Date(10,23,2001)));
    c1.InsertRearCLL(Movie("Harry Potter",Date(11,14,2001)));
    c1.InsertRearCLL(Movie("The Lion King",Date(6,24,1994)));
    MovieEngine.InsertRear(Category("Children", c1));
    c2.InsertRearCLL(Movie("MI 5",Date(5,8,2015)));
    c2.InsertRearCLL(Movie("Rocky",Date(11,21,1976)));
    c2.InsertRearCLL(Movie("Taken",Date(1,30,2009)));
    MovieEngine.InsertRear(Category("Action", c2));
    c3.InsertRearCLL(Movie("Harold & Kumar",Date(6,30,2004)));
    c3.InsertRearCLL(Movie("Jerry McGuire",Date(12,13,1996)));
    c3.InsertRearCLL(Movie("Tuxedo",Date(9,27,2002)));
    MovieEngine.InsertRear(Category("Comedy", c3));
    // Print those so you can be sure it worked
    MovieEngine.PrintList();
    MovieEngine.PrintCategoryList();
    // set Up the switch case and a while function to keep going through the options till you exit
    int numChoice = 1;
while (numChoice < 8 && numChoice > 0){
    switch (numChoice = ExploreFeatures())
    {
    case 1:
        // New Category by name
        MovieEngine.AddCategory();
        MovieEngine.PrintCategoryList();
        break;
    case 2:
        // Search for a category by name
        MovieEngine.SearchCategory();
        break;
    case 3:
        // Search for a movie by name
        MovieEngine.SearchMovieList();
        break;
    case 4:
        // Remove a category by name
        // MovieEngine.RemoveCategory();
        cout << "Couldn't figure it out, but check out the code I wrote for it." << endl;
        break;
    case 5:
        // Delete all movies before a certain date
        cout << "Didn't get to this part..." << endl;
        break;
    case 6:
    // Print all Movies within all categories
        MovieEngine.PrintList();
        break;
    case 7: 
        numChoice = 9;
        break;
    }
}
    cout << "Program exited successfully..." << endl;
    return 0;
}  