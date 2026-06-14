#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Book {
    string id;
    string title;
    string author;
    string year;
    string rating;
};

int main() {

    // -------------------- READ BOOKS --------------------
    ifstream file("books.txt");

    if (!file) {
        cerr << "books.txt not found\n";
        return 0;
    }

    vector<Book> v;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Book b;

        getline(ss, b.id, '|');
        getline(ss, b.title, '|');
        getline(ss, b.author, '|');
        getline(ss, b.year, '|');
        getline(ss, b.rating, '|');

        v.push_back(b);
    }

    file.close();

    // -------------------- ADJACENCY MATRIX --------------------
    int n = v.size();
    vector<vector<int>> adj(n, vector<int>(n, 0));
    ifstream file2("citations.txt");

    if (!file2) {
        cerr << "citations.txt not found\n";
        return 0;
    }

    while (getline(file2, line)) {
        stringstream ss(line);
        int a, b;

        while (ss >> a >> b) {
            int x = a - 101;  // converting book id to index
            int y = b - 101;

            adj[x][y] = 1;
            adj[y][x] = 1; // undirected relation
        }
    }

    file2.close();

    // -------------------- INPUT USER --------------------
    cout << "Enter book ID you liked: ";
    int liked;
    cin >> liked;

    int idx = liked - 101;
    cout << "Your recommendation list is: ";

    for (int j = 0; j < adj[idx].size(); j++) {
        if (adj[idx][j] == 1) {
            cout << (j + 101) << " ";
        }
    }

    cout << endl;

    return 0;
}