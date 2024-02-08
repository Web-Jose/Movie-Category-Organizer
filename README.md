# 🎬 Movie & Category Organizer 📁
This program is a movie and category organizer designed to store information about movies, such as their release dates and titles, and to organize them into categories.

## 🛠 Classes
The program includes two main classes,`Date` and `Movie`.

### 📅 `Date`
This class holds information about the release date of a movie, including the month, day, and year.

### 🎥 `Movie`
This class holds information about a movie, including its title and release date.

## 🗃 Data Structures
The program also includes a circular linked list to hold the movies of a category, as well as a vector to hold all categories.

### 🔁 Circular Linked List
The circular linked list holds movies in a category, and has the following methods:

- `InsertRearCLL(Movie d)`: inserts a movie at the end of the list.
- `RemoverCLL()`: removes the last movie before the list loops around.
- `PrintListCLL()`: prints all movies in the list.
- `SearchMovie(string st)`: searches the list for a movie with a specific title.
- `RemoveAllMovies()`: removes all movies in the list.
### 📈 Vector
The vector holds all categories, and has the following methods:

- `push_back(MovieCLL m)`: adds a new category to the vector.
- `at(int index)`: retrieves the category at the specified index.
## 🚀 Usage
To use this program, simply run the `main()` function. The program will prompt you to enter information about movies and categories, and then allow you to perform various operations on them, such as adding, removing, and searching for movies.

## 📝 Credits
This program was written by Jose Cortes as part of the CSCI 41 course at California State University of Fresno.
