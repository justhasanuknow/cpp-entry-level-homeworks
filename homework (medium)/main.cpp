#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

struct movie_struct {
  string title;
  double rating;
};

double get_average_score(const vector<movie_struct> *);
bool compare_by_rating(const movie_struct &, const movie_struct &);

int main() {
  int movie_count{0};

  cout << "Enter how many movies to store: ";
  cin >> movie_count;

  if (movie_count <= 0) {
    cout << "Movie count must be positive!" << endl;
    return 1;
  }

  vector<movie_struct> *movie_db = new vector<movie_struct>;

  for (size_t i = 0; i < movie_count; i++) {
    movie_struct new_movie;

    cout << "Please enter the title of movie " << i + 1 << ": ";
    cin.ignore();
    getline(cin, new_movie.title);

    cout << "Please enter the rating of movie " << i + 1 << ": ";
    cin >> new_movie.rating;

    (*movie_db).push_back(new_movie);
    cout << endl;
  }

  cout << endl
       << "Movies Entered:" << '\n';

  int movie_index{0};

  for (movie_struct movie : *movie_db) {
    cout << movie_index + 1 << ". " << movie.title << " Rating: " << movie.rating << "\n";
    movie_index++;
  }

  const double average = get_average_score(movie_db);

  cout << endl
       << "Average rating: " << average << endl;

  sort((*movie_db).begin(), (*movie_db).end(), compare_by_rating);

  cout << "Highest-rated movie: " << (*movie_db).at(0).title << " Rating (" << (*movie_db).at(0).rating << ")" << endl;
  cout << "Lowest-rated movie: " << (*movie_db).at(movie_count - 1).title << "- Rating (" << (*movie_db).at(movie_count - 1).rating << ")" << endl;

  delete movie_db;

  return 0;
}

double get_average_score(const vector<movie_struct> *movie_db) {
  const size_t size = (*movie_db).size();
  double total = 0;

  for (size_t i = 0; i < size; i++) {
    total += (*movie_db).at(i).rating;
  }

  return total / size;
}

bool compare_by_rating(const movie_struct &x, const movie_struct &y) {
  return x.rating < y.rating;
}